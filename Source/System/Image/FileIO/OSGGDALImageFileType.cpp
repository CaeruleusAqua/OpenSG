/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *             Copyright (C) 2000-2002 by the OpenSG Forum                   *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 *   contact: dirk@opensg.org, gerrit.voss@vossg.org, jbehr@zgdv.de          *
 *                                                                           *
\*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*\
 *                                License                                    *
 *                                                                           *
 * This library is free software; you can redistribute it and/or modify it   *
 * under the terms of the GNU Library General Public License as published    *
 * by the Free Software Foundation, version 2.                               *
 *                                                                           *
 * This library is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of                *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU         *
 * Library General Public License for more details.                          *
 *                                                                           *
 * You should have received a copy of the GNU Library General Public         *
 * License along with this library; if not, write to the Free Software       *
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.                 *
 *                                                                           *
\*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*\
 *                                Changes                                    *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
\*---------------------------------------------------------------------------*/
//-------------------------------
// Includes  
//-------------------------------

#include <cstdlib>
#include <cstdio>

#include "OSGConfig.h"

#include "OSGGDALImageFileType.h"

#ifdef OSG_WITH_GDAL
#include "gdal/gdal_priv.h"
#endif


#ifndef OSG_DO_DOC
#    ifdef OSG_WITH_GDAL
#        define OSG_GDAL_ARG(ARG) ARG
#    else
#        define OSG_GDAL_ARG(ARG)
#    endif
#else
#    define OSG_GDAL_ARG(ARG) ARG
#endif


OSG_USING_NAMESPACE


/*! \class OSG::GDALImageFileType 
    \ingroup GrpSystemImage
  
  Image File Type to read/write and store/restore Image objects as
  GDAL (tif/tiff suffix) data.
  
  To be able to load TIFF images you need the IJG TIFF library, 
  (check the Prerequisites page on www.opensg.org). 
  The lib comes with all Linux distributions.
  
  You have to --enable-tif in the configure line to enable
  the singleton object.
  
 */


// Static Class Varible implementations:
static const Char8 *suffixArray[] = 
{
    "gtif", "gtiff"
};

GDALImageFileType GDALImageFileType:: _the("image/gdal",
                                           suffixArray, 
                                           sizeof(suffixArray),
                                           (OSG_READ_SUPPORTED));


//-------------------------------------------------------------------------
/*! Tries to fill the image object with the data read from
    the given fileName. Returns true on success.
 */

bool GDALImageFileType::read(      ImagePtrArg  OSG_GDAL_ARG(pImage), 
                             const Char8       *OSG_GDAL_ARG(fileName)) 
{
#ifdef OSG_WITH_GDAL
    bool returnValue = false;

    fprintf(stderr, "READ GDAL \n");
    
    GDALDataset *pDataset;

    pDataset = (GDALDataset *) GDALOpen(fileName, GA_ReadOnly);

    if(pDataset != NULL)
    {
        double        adfGeoTransform[6];
        
        printf("Driver: %s/%s\n",
               pDataset->GetDriver()->GetDescription(), 
               pDataset->GetDriver()->GetMetadataItem( GDAL_DMD_LONGNAME ) );
        
        printf("Size is %dx%dx%d\n", 
                pDataset->GetRasterXSize(), 
                pDataset->GetRasterYSize(),
                pDataset->GetRasterCount() );

        
        if(pDataset->GetProjectionRef()  != NULL )
            printf( "Projection is `%s'\n", pDataset->GetProjectionRef() );
        
        if(pDataset->GetGeoTransform(adfGeoTransform) == CE_None)
        {
            printf("Origin = (%.6f,%.6f)\n",
                   adfGeoTransform[0], 
                   adfGeoTransform[3] );
            
            printf("Pixel Size = (%.6f,%.6f)\n",
                   adfGeoTransform[1], 
                   adfGeoTransform[5]);
        }

        GDALRasterBand *poBand;
        int             nBlockXSize, nBlockYSize;
        int             bGotMin, bGotMax;
        double          adfMinMax[2];
        
        poBand = pDataset->GetRasterBand( 1 );
        poBand->GetBlockSize( &nBlockXSize, &nBlockYSize );

        printf( "Block=%dx%d Type=%s, ColorInterp=%s\n",
                nBlockXSize, nBlockYSize,
                GDALGetDataTypeName(poBand->GetRasterDataType()),
                GDALGetColorInterpretationName(
                    poBand->GetColorInterpretation()) );
        
        adfMinMax[0] = poBand->GetMinimum( &bGotMin );
        adfMinMax[1] = poBand->GetMaximum( &bGotMax );

        if( ! (bGotMin && bGotMax) )
            GDALComputeRasterMinMax((GDALRasterBandH)poBand, TRUE, adfMinMax);

        printf( "Min=%.3fd, Max=%.3f\n", adfMinMax[0], adfMinMax[1] );
        
        if( poBand->GetOverviewCount() > 0 )
            printf( "Band has %d overviews.\n", poBand->GetOverviewCount() );

        if( poBand->GetColorTable() != NULL )
            printf( "Band has a color table with %d entries.\n", 
                     poBand->GetColorTable()->GetColorEntryCount() );    



        GDALRasterBand *pBand;

        pBand = pDataset->GetRasterBand(1);

        if(pBand != NULL)
        {
            Image::PixelFormat ePF = Image::OSG_INVALID_PF;

            switch(pDataset->GetRasterCount())
            {
                case 1:
                    ePF = Image::OSG_L_PF;
                    break;
                case 2:
                    ePF = Image::OSG_LA_PF;
                    break;
                case 3:
                    ePF = Image::OSG_RGB_PF;
                    break;
                case 4:
                    ePF = Image::OSG_RGBA_PF;
                    break;
            }

            Image::Type eDT = Image::OSG_INVALID_IMAGEDATATYPE;

            switch(pBand->GetRasterDataType())
            {
                case GDT_Byte:
                    eDT = Image::OSG_UINT8_IMAGEDATA;
                    break;

                case GDT_UInt16:
                    eDT = Image::OSG_UINT16_IMAGEDATA;
                    break;

                case GDT_Int16:
                    eDT = Image::OSG_INT16_IMAGEDATA;
                    break;

                case GDT_UInt32:
                    eDT = Image::OSG_UINT32_IMAGEDATA;
                    break;

                case GDT_Int32:
                    eDT = Image::OSG_INT32_IMAGEDATA;
                    break;

                case GDT_Float32: 
                    eDT = Image::OSG_FLOAT32_IMAGEDATA;
                    break;

                case GDT_Float64:
                case GDT_CInt16: 
                case GDT_CInt32:
                case GDT_CFloat32:
                case GDT_CFloat64:
                default:
                    GDALClose(pDataset);
                    return returnValue;
                    break;
        
            }

            pImage->set(ePF,             
                        pDataset->GetRasterXSize(), 
                        pDataset->GetRasterYSize(),
                        1,
                        1,
                        1,
                        0.0,
                        NULL,
                        eDT);
            
            UChar8 *dst = pImage->editData();

            fprintf(stderr, "FOO %p\n", dst);

            pBand->RasterIO(GF_Read,
                            0, 
                            0,
                            pDataset->GetRasterXSize(), 
                            pDataset->GetRasterYSize(),
                            dst,
                            pDataset->GetRasterXSize(), 
                            pDataset->GetRasterYSize(),
                            pBand->GetRasterDataType(),
                            0,
                            0);

            returnValue = true;
        }

        GDALClose(pDataset);
    }

    return returnValue;

#else

    SWARNING << getMimeType()
             << " read is not compiled into the current binary "
             << std::endl;
    return false;

#endif // OSG_WITH_GDAL
}

//-------------------------------------------------------------------------
/*! Tries to write the image object to the given output stream.
    Returns true on success.
*/

bool GDALImageFileType::write(      ImageConstPtrArg  OSG_GDAL_ARG(pImage), 
                              const Char8            *OSG_GDAL_ARG(fileName)) 
{
    bool                retCode = false;

#ifdef OSG_WITH_GDALX
    if(pImage->getDimension() < 1 || pImage->getDimension() > 2)
    {
        FWARNING(("TIFImageFileType::write: invalid dimension %d!\n",
            pImage->getDimension()));

        return false;
    }

    TIFF         *out = TIFFClientOpen("dummy", "wm", (thandle_t)&os,
                                       osReadProc, 
                                       osWriteProc, 
                                       osSeekProc, 
                                       closeProc,
			                           osSizeProc, 
                                       mapFileProc, 
                                       unmapFileProc);

    int           lineSize = pImage->getWidth() * pImage->getBpp();
    int           photometric = 0;
    int           samplesPerPixel = 0;
    const UChar8 *data;
    int           row;

    // TODO: implement all cases correct
    switch(pImage->getBpp())
    {
        case 1:
            samplesPerPixel = 1;
            photometric = PHOTOMETRIC_MINISBLACK;
            break;
        case 2:
            samplesPerPixel = 2;
            photometric = PHOTOMETRIC_MINISBLACK;
            break;
        case 3:
            samplesPerPixel = 3;
            photometric = PHOTOMETRIC_RGB;
            break;
        case 4:
            samplesPerPixel = 4;
            photometric = PHOTOMETRIC_RGB;
            break;
    }
    
    if(out)
    {
        TIFFSetField(out, TIFFTAG_IMAGEWIDTH, pImage->getWidth());
        TIFFSetField(out, TIFFTAG_IMAGELENGTH, pImage->getHeight());
        TIFFSetField(out, TIFFTAG_XRESOLUTION, pImage->getResX());
        TIFFSetField(out, TIFFTAG_YRESOLUTION, pImage->getResY());
        TIFFSetField(out, TIFFTAG_RESOLUTIONUNIT, pImage->getResUnit());
        TIFFSetField(out, TIFFTAG_ORIENTATION, ORIENTATION_TOPLEFT);
        TIFFSetField(out, TIFFTAG_SAMPLESPERPIXEL, samplesPerPixel);
        TIFFSetField(out, TIFFTAG_BITSPERSAMPLE, 8);
        TIFFSetField(out, TIFFTAG_PLANARCONFIG, PLANARCONFIG_CONTIG);
        TIFFSetField(out, TIFFTAG_PHOTOMETRIC, photometric);

        if(_options.find("compressionType=LZW") != std::string::npos)
        {
            TIFFSetField(out, TIFFTAG_COMPRESSION, COMPRESSION_LZW);
        }
        else
        {
            TIFFSetField(out, TIFFTAG_COMPRESSION, COMPRESSION_NONE);
        }

        TIFFSetField(out, TIFFTAG_ROWSPERSTRIP, TIFFDefaultStripSize(out, 0));

        for(row = 0; row < pImage->getHeight(); row++)
        {
            data = 
                pImage->getData() + 
                ((pImage->getHeight() - row - 1) * lineSize);

            if(TIFFWriteScanline(out, 
                                 (tdata_t) const_cast<UChar8 *>(data), 
                                 row, 
                                 0) < 0)
            {
                break;
            }
        }
        
        TIFFClose(out);

        retCode = true;
    }

#else
    SWARNING << getMimeType()
             << " write is not compiled into the current binary " 
             << std::endl;
#endif

    return retCode;
}

bool GDALImageFileType::validateHeader(const Char8 *fileName, bool &implemented)
{
    implemented = true;

    return true;
}


//-------------------------------------------------------------------------
/*! Constructor used for the singleton object
 */

GDALImageFileType::GDALImageFileType(const Char8  *mimeType,
                                     const Char8  *suffixArray[],
                                           UInt16  suffixByteCount,
                                           UInt32  flags) :
    Inherited(mimeType,
              suffixArray, 
              suffixByteCount, 
              flags          )
{
    static bool initTIFFLib = true;
    
#ifdef OSG_WITH_GDAL
    GDALAllRegister();
#endif
}

//-------------------------------------------------------------------------
/*! Destructor
 */

GDALImageFileType::~GDALImageFileType(void)
{
}
