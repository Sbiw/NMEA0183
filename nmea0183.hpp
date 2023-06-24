#if ! defined( NMEA_0183_CLASS_HEADER )

#define NMEA_0183_CLASS_HEADER

/*
Author: Samuel R. Blackburn
Internet: wfc@pobox.com

"You can get credit for something or get it done, but not both."
Dr. Richard Garwin

The MIT License (MIT)

Copyright (c) 1996-2019 Sam Blackburn

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/* SPDX-License-Identifier: MIT */

/*
** General Purpose Classes
*/

#include "sentence.hpp"
#include "response.hpp"
#include "latlong.hpp"
#include "lorantd.hpp"
#include "manufact.hpp"
#include "mlist.hpp"
#include "omegapar.hpp"
#include "deccalop.hpp"
#include "ratiopls.hpp"
#include "radardat.hpp"
#include "satdat.hpp"
#include "freqmode.hpp"
#include "wayptloc.hpp" // Sentence Not Recommended For New Designs

/*
** Response Classes
*/

#include "aam.hpp"
#include "alm.hpp"
#include "apb.hpp"
#include "asd.hpp"
#include "bec.hpp"
#include "bod.hpp"
#include "bwc.hpp"
#include "bwr.hpp"
#include "bww.hpp"
#include "dbt.hpp"
#include "dcn.hpp"
#include "dpt.hpp"
#include "fsi.hpp"
#include "gda.hpp" // sentence not recommended for new designs
#include "gdf.hpp" // sentence not recommended for new designs
#include "gdp.hpp" // sentence not recommended for new designs
#include "gga.hpp"
#include "gla.hpp" // sentence not recommended for new designs
#include "glc.hpp"
#include "glf.hpp" // sentence not recommended for new designs
#include "gll.hpp"
#include "glp.hpp" // sentence not recommended for new designs
#include "goa.hpp" // sentence not recommended for new designs
#include "gof.hpp" // sentence not recommended for new designs
#include "gop.hpp" // sentence not recommended for new designs
#include "gsa.hpp"
#include "gsv.hpp"
#include "gtd.hpp" // sentence not recommended for new designs
#include "gxa.hpp"
#include "gxf.hpp" // sentence not recommended for new designs
#include "gxp.hpp" // sentence not recommended for new designs
#include "hcc.hpp" // sentence not recommended for new designs
#include "hdg.hpp"
#include "hdm.hpp" // sentence not recommended for new designs
#include "hdt.hpp"
#include "hsc.hpp"
#include "ima.hpp" // sentence not recommended for new designs
#include "lcd.hpp"
#include "mhu.hpp" // sentence not recommended for new designs
#include "mta.hpp" // sentence not recommended for new designs
#include "mtw.hpp"
#include "mwv.hpp"
#include "oln.hpp"
#include "osd.hpp"
#include "p.hpp"
#include "rma.hpp"
#include "rmb.hpp"
#include "rmc.hpp"
#include "rot.hpp"
#include "rpm.hpp"
#include "rsa.hpp"
#include "rsd.hpp"
#include "rte.hpp"
#include "sfi.hpp"
#include "stn.hpp"
#include "tep.hpp" // sentence not recommended for new designs
#include "trf.hpp"
#include "ttm.hpp"
#include "vbw.hpp"
#include "vdr.hpp"
#include "vhw.hpp"
#include "vlw.hpp"
#include "vpw.hpp"
#include "vtg.hpp"
#include "vwe.hpp" // sentence not recommended for new designs
#include "wcv.hpp"
#include "wdc.hpp" // sentence not recommended for new designs
#include "wdr.hpp" // sentence not recommended for new designs
#include "wnc.hpp"
#include "wpl.hpp"
#include "xdr.hpp"
#include "xte.hpp"
#include "xtr.hpp"
#include "zda.hpp"
#include "zfi.hpp" // sentence not recommended for new designs
#include "zfo.hpp" 
#include "zlz.hpp" // sentence not recommended for new designs
#include "zpi.hpp" // sentence not recommended for new designs
#include "zta.hpp" // sentence not recommended for new designs
#include "zte.hpp" // sentence not recommended for new designs
#include "ztg.hpp"
#include "zti.hpp" // sentence not recommended for new designs
#include "zwp.hpp" // sentence not recommended for new designs
#include "zzu.hpp" // sentence not recommended for new designs

class NMEA0183
{
   private:

      SENTENCE m_Sentence;

      void m_Initialize( void ) noexcept;

   protected:

      std::vector<RESPONSE *> m_ResponseTable;

      void m_SetContainerPointers( void ) noexcept;

   public:

      NMEA0183();

      /*
      HOW TO USE THIS CLASS
      Normally, you don't care about most sentences.
      Modify the declaration of this class (or copy this class to your own
      class) and get rid of the sentences you don't care about. For example,
      if you're interfacing with a device that will NEVER produce an AAM sentence,
      get rid of the Aam member. Don't have code that will never be called.
      */

      /*
      ** NMEA 0183 Sentences we understand
      */

      AAM Aam;
      ALM Alm;
      APB Apb;
      ASD Asd;
      BEC Bec;
      BOD Bod;
      BWC Bwc;
      BWR Bwr;
      BWW Bww;
      DBT Dbt;
      DCN Dcn;
      DPT Dpt;
      FSI Fsi;
      GDA Gda; // Sentence Not Recommended For New Designs
      GDF Gdf; // Sentence Not Recommended For New Designs
      GDP Gdp; // Sentence Not Recommended For New Designs
      GGA Gga;
      GLA Gla; // Sentence Not Recommended For New Designs
      GLC Glc;
      GLF Glf; // Sentence Not Recommended For New Designs
      GLL Gll;
      GLP Glp; // Sentence Not Recommended For New Designs
      GOA Goa; // Sentence Not Recommended For New Designs
      GOF Gof; // Sentence Not Recommended For New Designs
      GOP Gop; // Sentence Not Recommended For New Designs
      GSA Gsa;
      GSV Gsv;
      GTD Gtd; // Sentence Not Recommended For New Designs
      GXA Gxa;
      GXF Gxf; // Sentence Not Recommended For New Designs
      GXP Gxp; // Sentence Not Recommended For New Designs
      HCC Hcc; // Sentence Not Recommended For New Designs
      HDG Hdg;
      HDM Hdm; // Sentence Not Recommended For New Designs
      HDT Hdt;
      HSC Hsc;
      IMA Ima; // Sentence Not Recommended For New Designs
      LCD Lcd;
      MHU Mhu; // Sentence Not Recommended For New Designs
      MTA Mta; // Sentence Not Recommended For New Designs
      MTW Mtw;
      MWV Mwv;
      OLN Oln;
      OSD Osd;
      P   Proprietary;
      RMA Rma;
      RMB Rmb;
      RMC Rmc;
      ROT Rot;
      RPM Rpm;
      RSA Rsa;
      RSD Rsd;
      RTE Rte;
      SFI Sfi;
      STN Stn;
      TEP Tep; // Sentence Not Recommended For New Designs
      TRF Trf;
      TTM Ttm;
      VBW Vbw;
      VDR Vdr;
      VHW Vhw;
      VLW Vlw;
      VPW Vpw;
      VTG Vtg;
      VWE Vwe; // Sentence Not Recommended For New Designs
      WCV Wcv;
      WDC Wdc; // Sentence Not Recommended For New Designs
      WDR Wdr; // Sentence Not Recommended For New Designs
      WNC Wnc;
      WPL Wpl;
	  XDR Xdr;
	  XTE Xte;
      XTR Xtr;
      ZDA Zda;
      ZFI Zfi; // Sentence Not Recommended For New Designs
      ZFO Zfo;
      ZLZ Zlz; // Sentence Not Recommended For New Designs
      ZPI Zpi; // Sentence Not Recommended For New Designs
      ZTA Zta; // Sentence Not Recommended For New Designs
      ZTE Zte; // Sentence Not Recommended For New Designs
      ZTI Zti; // Sentence Not Recommended For New Designs
      ZTG Ztg;
      ZWP Zwp; // Sentence Not Recommended For New Designs
      ZZU Zzu; // Sentence Not Recommended For New Designs

      std::string ErrorMessage; // Filled when Parse returns FALSE
      std::string LastSentenceIDParsed; // ID of the lst sentence successfully parsed
      std::string LastSentenceIDReceived; // ID of the last sentence received, may not have parsed successfully
      std::string PlainText; // A human-readable string of text that explains what just happened

      std::string TalkerID;
      std::string ExpandedTalkerID;

      virtual bool IsGood( void ) const noexcept;
      virtual bool Parse( void ) noexcept;
      virtual void SetSentence(std::string_view source) noexcept;
      virtual void GetSentence(std::string& destination) const noexcept;

      inline NMEA0183& operator << (std::string_view source) noexcept
      {
          SetSentence(source);
          return(*this);
      }

      inline NMEA0183& operator >> (std::string& destination) noexcept
      {
          GetSentence(destination);
          return(*this);
      }
};

#endif // NMEA_0183_CLASS_HEADER
