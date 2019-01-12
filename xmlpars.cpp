// xmlpars.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include <iostream>
#include <time.h>
//#include <ostream>
#include <string>
using namespace std;
#define S0_MAX_LINK               ((INT8U) 8)

#define US_PORT_COMMON_PORT       LOG_TLN_PORT_MIN

#define VP_PROFILE 12

/*amounts of virtual ports*/
#define AMOUNT_OF_VP_MOBILE_CONNECT      150
#define NUM_OF_LOG_TLN_PORT                 1500
#define AMOUNT_OF_CONFERENCE_ROOMS       10

#define AMOUNT_OF_PARK_POSITION         1

#define AMOUNT_OF_VP_FAX                1500

#define AMOUNT_OF_VP_AUTO_ATTENDANT     20
#define AMOUNT_OF_VP_VOICEMAIL_GROUPS   20
#define AMOUNT_OF_VP_PROFILE            20
#define AMOUNT_OF_VP_FREE_CONFIG        20
#define AMOUNT_OF_VP_FAX_PILOTS         60
#define AMOUNT_OF_VP_CALL_CENTER_FAX    60
#define AMOUNT_OF_VP_FAX_GROUPS         60
#define AMOUNT_OF_VP_MEETME             1

#define AMOUNT_UP0_X1  16
#define AMOUNT_IP_X1 20  /*IP+SIP*/
#define AMOUNT_ANALOG_X1  4
#define AMAOUNT_VIRTUAL_X1 250
#define AMAOUNT_RAS_X1 2
#define AMOUNT_ISDN_X1 2
#define AMOUNT_GROUPS_X1 797
#define AMOUNT_DECT_X1   16
#define DID_SIZE  16
#define AMOUNT_OF_NON_VIRTUAL_PORTS            510 /* EVM-ports from 500-509 */
#define AMOUNT_OF_IP_PORTS                     500

#define AMOUNT_OF_NON_VIRTUAL_PORTS_V2_S       1510
#define AMOUNT_OF_IP_PORTS_V2_S                1500

#define AMOUNT_OF_ANALOG_PORTS                 384
#define AMOUNT_OF_S0_PORTS                     128
#define MAX_AMOUNT_OLD_FORMAT		                 6
#define MAX_AMOUNT_NEW_FORMAT		                 8
	

#define MAX_TYP 					 3
#define MAX_LICENCE					 2

#define MAX_MOBILE					26
#define MAX_PRIVATE_NUMBER			        26
#define MAX_NODEID					 4
#define MAX_IP_ADDRESS				        15
#define LAST_PORT_TYPE				        15
#define LAST_NODEID				       100 
#define LAST_IP 				       100

#define AMOUNT_OF_TRKGRP_SIP		                 4
#define AMOUNT_OF_VOICEMAIL_CALLN	                 1

#ifndef HOOLE
#define AMOUNT_OF_RAS_REMOTE		                 1
#define AMOUNT_OF_RAS_CLS			         1
#define AMOUNT_OF_RAS_TOTAL				 300
#else
#define AMOUNT_OF_RAS_REMOTE		                 0
#define AMOUNT_OF_RAS_CLS			         0
#define AMOUNT_OF_RAS_TOTAL                              0
#endif

#define MAXLENSTRS_CUSTOMER  50
#define MAXLENSTR_NAME  32

#define AMOUNT_OF_MEET_ME			         1

/// temp TEMP *****
#define AMOUNT_OF_VP_FAXPILOTS   AMOUNT_OF_VP_FAX_PILOTS



#define DS_BPL_ONE_X1  19 /*the definition copied from file  sta_stic.h */

typedef struct TAG_DB_KW_CHK_KWZ_NAME
{
    int* rufnr_ptr;
    int  rn_length;
    int  rtg_ind;
    int port;
    int kwz_index;

}DB_KW_CHK_KWZ_NAME;



 typedef enum
                {       
                        LINE_OK,
                        INVALID_DELIMETER,
                        TOO_MANY_LINES,
                        INDEX_NOT_UNIQUE,
                        INVALID_CALL_NO_1,
                        INVALID_NAME,
                        EXCEEDED_STN_LINES,
                        INVALID_INDEX,
                        STN_TYP_UNKNOWN,
                        TOO_MANY_IP,
                        TOO_MANY_ANALOG,
                        INVALID_EMAIL,
                        INVALID_MOBILE,
                        INVALID_DUWA,
                        IP_CLIENT_MISSING,
                        CALL_NO_NOT_UNIQUE,
                        DUWA_NOT_UNIQUE,
                        INVALID_LIC_TYPE,
                        TOO_MANY_ISDN,

   /*******************************************************************************
    *                        V E R S I O N 3                      *
    ******************************************************************************/

                        
                                                INVALID_PRIVATE_NUMBER,
                                                INVALID_NODEID1,
                                                INVALID_IP,
                                                TOO_MANY_TRUNK,
                                                TOO_MANY_VOICEMAIL,
                                                TOO_MANY_RAS_REMOTE,
                                                TOO_MANY_RAS_CLS,
                                                TOO_MANY_PARK,
                                                TOO_MANY_OSO_CONFERENCE,
                                                TOO_MANY_MEET_ME,
                                                TOO_MANY_VP_AUTO_ATTENDANT,
                                                TOO_MANY_GROUPS,
                                                INVALID_FILE_FORMAT,
                                                CALL_NO_MISSING,
                                                STN_TYP_MISSING,
                                                DUWA_NOT_SUPPORTED,
                                                LIC_TYPE_NOT_SUPPORTED,
                                                NODE_ID_MIXUP,
                                                TOO_MANY_RAS,
                                                TOO_MANY_DESK,/*38*/
                                                TOO_MANY_UP0, /*39*/
                                                TOO_MANY_SIP, /*40*/
                                                TOO_MANY_CCFAX,/*41*/
                                                TOO_MANY_DECT, /*42*/
                                                LIC_NOT_EXISTS,/*43*/
                                                LIC_TYP_USTYP, /*44*/
                                                LIC_TYP_VCMAIL, /*45*/
                                                LIC_TYP_GRWAREUS, /*46*/
                                                LIC_TYP_UCUSER , /*47*/
                                                LIC_TYP_UCFAX, /*48*/
                                                LIC_TYP_UCCONF, /*49*/
                                                LIC_TYP_MYATTEND, /*50*/
                                                LIC_TYP_MYAGENT, /*51*/
                                                LIC_TYP_SOCMEDIA, /*52*/
                                                LIC_TYP_APPLAUNCH, /*53*/
                                                LIC_TYP_TAPI, /*54*/
                                                LIC_TYP_SMARTUC,/*55*/                                                                                          
                                                INVALID_SECGW, /*56*/
                                                LIC_TYP_ZIMBRA,/*57*/
                                                TOO_MANY_FAXGROUPS,/*58*/
                                                TOO_MANY_STATIONS,/*59*/
                                                TOO_MANY_RAS_ADMIN,/*60*/
                                                TOO_MANY_RAS_LIC,/*61*/
                                                NO_DATA_NODE,/*62*/
                                                NO_ANALOG_SLOT,/*63*/
                                                NO_UP0_SLOT,/*64*/
                                                WRONG_ACCESS_TYPE,/*65*/
                                                WRONG_ACEESS_FORMAT,/*66*/
                                                WRONG_VOICEMAIL_FORMAT,/*67*/
                                                TOO_MANYVOICEMAIL_EVM,/*68*/
                                                INVALID_FAXCALLNO,/*69*/
                                                INVALID_FAXDID,/*70*/
                                                INVALID_COS,/*71*/
                                                INVALID_CALLPICKUP,/*72*/
                                                FAX_CALL_NOT_UNIQUE,/*73*/
                                                FAX_DID_NOT_UNIQUE,/*74*/
                                                MISSING_FAX_CALLNO,/*75*/
                                                TOO_MANY_FAXES,/*76*/
                                                INVALID_FAX_NAME,/*77*/
                                                CALL_NO_SPD_MISSING,/*78*/
                                                SPD_DIALNUMB_MISSING,/*79*/
                                                INVALID_NAME_CHARACTERS,/*80*/
                                                INVALID_REALM,/*81*/
                                                INVALID_USERID_USERNAME,/*82*/
                                                SIP_NOT_EXIST,/*83*/
                                                INVALID_PASSWORD,/*84*/
                                                
                                                INVALID_UCTYPE,/*85*/
                                                INVALID_SITENAME,/*86*/
                                                INVALID_LASTNAME,/*87*/
                                                INVALID_FIRSTNAME,/*88*/
                                                INVALID_OUTLADD,/*89*/
                                                INVALID_UCCLIENT,
                                                INVALID_UCFAX,
                                                INVALID_CONFSERV,
                                                INVALID_NETWSITE
                                                
                                                
                                







                } RESULT_VALUE;


/*---------------Start------definitions for Xml File Import----------------------------------------------*/
int  NR_TLN= 1650;
int RUFNR_SIZE= 250;
int TLN_NAME_SIZE= 16;
int INVALID_CALL_NO = 33;
int INVALID_NODEID = 444;
int MAX_EMAIL=70;

typedef struct rd_kds_return
        {
        int inhalt[32]; /* Speicherplatz fuer max. 32 KDS-Daten   */
        int ui;                             /* Zusaetzlicher Rueckgabeparameter      */
        } RD_KDS_RETURN;

typedef struct xmlStationsName
{
	char namedcell[50];
	char headerrecord[50];
}fpxmlStationsName;

typedef struct xmlUsa
{
  char element[50];
} xmlUsa;


xmlUsa xmlUsaElements[29]=
{
      {"nodeid"}, 				
      {"sitename"}, 	 
      {"uctype"},
      {"cpickgroup"}, 		
      {"lastname"}, 	 		
      {"firstname"}, 	
      {"displayname"}, 	 		
      {"internumber"}, 	 		
      {"didnumber"}, 	 			
      {"emailaddr"}, 	 		
      {"mobile"}, 	 		
      {"devtype"}, 	 		
      {"voicemail"}, 	 
      {"outlookaddin"}, 		
      {"ucclient"}, 	 
      {"ucfax"}, 	 
      {"faxcallno"}, 	 	
      {"faxdid"}, 	 		
      {"faxname"}, 	 		
      {"confserver"}, 	 	
      {"myattend"}, 	 		
      {"myagent"}, 	 		
      {"applaunch"}, 	
      {"tapi"}, 	 
      {"cos"}, 		 		
      {"callpickup"}, 	
      {"networksite"}, 	
      {"segw"}, 	
      {"access"}

};





fpxmlStationsName xmlStationsNameTable[15]=

{
	//namedcell       headerrecord
	{"internumber" ,"Internal number"},  	//   xmlStationsNameTable[0]  
	{"didnumber"   ,"DID number"},		//   xmlStationsNameTable[1]
	{"displayname" ,"Display name"},	//   xmlStationsNameTable[2]
	{"stationtype" ,"Station type"},	//   xmlStationsNameTable[3]
	/*------------CR  FAX -------------------------------------------*/
	{"faxcallno"  ,"Fax Callno"},		//   xmlStationsNameTable[4]  
	{"faxdid"     ,"Fax DID"},		//   xmlStationsNameTable[5]  
	{"faxname"    ,"Fax name"},		//   xmlStationsNameTable[6]  
	{"cos"        ,"Class of service"},	//   xmlStationsNameTable[7]    
	{"callpickup" ,"Call pickup"},	        //   xmlStationsNameTable[8]
	/*------------CR  FAX -------------------------------------------*/	
	{"access"      ,"Access"},		//   xmlStationsNameTable[9]  
	{"voicemail"    ,"Voicemail"},		//   xmlStationsNameTable[10]  
	{"emailaddr"   ,"Email address"},	//   xmlStationsNameTable[11]    
	{"mobile"      ,"Mobile number"},	//   xmlStationsNameTable[12]
	{"node"        ,"Node"},		//   xmlStationsNameTable[13]
	{"gateway"     ,"Secondary gateway"}	//     xmlStationsNameTable[14]	 
};


fpxmlStationsName xmlLicensesNameTable[13]=
{
	//namedcell       headerrecord
	{"licinternumber"   ,"Internal number"}, //Column B 	xmlLicensesNameTable[0] 
        {"licusertype" , "User Type"},          //Column C 	[1]			
	{"licvoicemail"     ,"Voicemail"},     //Column D 	xmlLicensesNameTable[2]					
	{"licgroupwareuser" ,"Groupware User"},//Column E 	xmlLicensesNameTable[3]					
	{"licucuser"        ,"UC-User"},//Column F 	xmlLicensesNameTable[4]							
	{"licucfax"         ,"UC-Fax"},	//Column G 	xmlLicensesNameTable[5]							
	{"licucconference"  ,"UC-Conference"},  //Column H 	xmlLicensesNameTable[6]							        
	{"licmyattendant"   ,"My Attendant"},	//Column I 	xmlLicensesNameTable[7]								
	{"licmyagent"       ,"myAgent"},       //Column J 	xmlLicensesNameTable[8]							         
//	{"licsocialmedia"   ,"Social Media"}, //Column K 	xmlLicensesNameTable[9]							          
	{"licapplauncher"   ,"Application Launcher"},  //Column L 	xmlLicensesNameTable[9]							 
	{"lictapi"   ,"TAPI"},   //Column M 	xmlLicensesNameTable[10]   			
	{"licsmartuc"   ,"Smart-UC"},  //Column N 	xmlLicensesNameTable[11] 
//	{"liczimbra"   ,"Zimbra"},  //Column N 	xmlLicensesNameTable[12]
	{"licnode"   ,"Node"}  //Column N 	xmlLicensesNameTable[12]
};


fpxmlStationsName xmlGroupsNameTable[5]=
{
	//namedcell       headerrecord
	{"grinternalnumber","Internal number"}, //  Column  B   ,  xmlGroupsNameTable[0]
	{"grdidnumber" 	   ,"DID number"},	//  Column  C   ,  xmlGroupsNameTable[1]
	{"grdispalyname"   ,"Display name"},	//  Column  D   ,  xmlGroupsNameTable[2]
	{"grvoicemail"      ,"Voicemail"},	        //  Column  D   ,  xmlGroupsNameTable[3]
	{"grnode"          ,"Node"}  		//  Column  E   ,  xmlGroupsNameTable[4]

};
fpxmlStationsName xmlVirtualNameTable[5]=
{
	//namedcell       headerrecord
	{"virinternalnum"  ,"Internal number"}, 
	{"virdidnum" 	   ,"DID number"},	
	{"virdisplayname"  ,"Display name"},	
	{"virtype"         ,"Type"},	        
	{"virnode"         ,"Node"}  		

};
fpxmlStationsName xmlTrunkGrpNameTable[3]=
{
	//namedcell       headerrecord
	{"trnkinternulnum"  ,"Internal number"}, //  Column  B   ,  xmlTrunkGrpNameTable[0]
	{"trnkdisplayname"  ,"Display name"},	//  Column  D   ,  xmlTrunkGrpNameTable[2]
	{"trnknode"         ,"Node"}  		

};
fpxmlStationsName xmlVoiceMailNameTable[3]=
{
	//namedcell       headerrecord
	{"vcinternalnum"  ,"Internal number"}, //  Column  B   ,  xmlTrunkGrpNameTable[0]
	{"vcdisplayname"  ,"Display name"},	//  Column  D   ,  xmlTrunkGrpNameTable[2]
	{"vcnode"         ,"Node"}  		

};

fpxmlStationsName xmlSpdStationsTable[3]=
{
	//namedcell       headerrecord
	{"spddialling" ,"Speed dialling"}, //  Column  A   
	{"spdnumber"  ,"Call number"},	//  Column  B   
	{"spdname"    ,"Name"}  	//  Column  C	
 
};

// SipConfig

fpxmlStationsName xmlSipConfigTable[5]=
{
	/*sipnternalnum sippassword siprealm sipuseridname*/
	{"sipnternalnum"  ,"Internal number"}, //  Column  A   
	{"sippassword"    ,"Password"},	//  Column  B   
	{"sipuseridname"  ,"UserId/Username"},  	//  Column  C	
	{"siprealm"       ,"Realm"},  	//  Column  D
	{"sipnode"       ,"Node"}  	//  Column  E	
 
};

typedef struct stationTypes
{
	char name[20];
}fpstationTypes;

fpstationTypes  xmlDevType[14]=
{    
   {"SIP"},
   {"SIP fax"},
   {"UP0"},
   {"IP"},
   {"RAS"},
   {"DeskShare"},
   {"a/b fax"},
   {"a/b"},
   {"ISDN"},   
   {"DECT"},   
   {"RAS-ADMIN"},   
   {"RAS-LIC"},
   {"digital"},
   {"analog"}   
};


fpstationTypes xmlStationTypes[12]= // {SIP , SIP fax , UP0, IP ,RAS , DeskShare ,a/b, a/b fax, ISDN, DECT }
{
   {"SIP"},
   {"SIP fax"},
   {"UP0"},
   {"IP"},
   {"RAS"},
   {"DeskShare"},
   {"a/b fax"},
   {"a/b"},
   {"ISDN"},   
   {"DECT"},   
   {"RAS-ADMIN"},   
   {"RAS-LIC"}   
};

fpstationTypes xmlVirtualStationTypes[7]= // Auto-Attendant, Fax ,CC Fax, Parking , Conferencing
{
   {"Auto-Attendant"},
   {"CC Fax"},
   {"Parking"},
   {"Conferencing"},
   {"Fax Group"},
   {"Virtual"},   
   {"MeetMe"}   
};
fpstationTypes xmlLicensesUserType[4]= // IP, TDM, DESKSHARE,MOBILITY
{
   {"IP"},
   {"TDM"},
   {"DESKSHARE"},
   {"MOBILITY"}
};

fpxmlStationsName LXxmlStationsNameTable[8]=
{
	//namedcell       headerrecord
	{"internumber" ,"Internal number"},  	// Internal number Column  B   ,  xmlStationsNameTable[0]  
	{"didnumber"   ,"DID number"},		// DID number Column  C        ,  xmlStationsNameTable[1]
	{"displayname" ,"Display name"},	// Display name Column  D      ,  xmlStationsNameTable[2]
	{"stationtype" ,"Station type"},	// Station type Column  E      ,  xmlStationsNameTable[3]
	{"emailaddr"   ,"Email address"},		// Email address Column  G     ,  xmlStationsNameTable[5]    
	{"mobile"      ,"Mobile number"},		// Mobile number Column  H     ,  xmlStationsNameTable[6]
	{"node"        ,"Node"},			// Node  Column  I   	       ,  xmlStationsNameTable[7]
	{"gateway"     ,"Secondary gateway"}	// Secondary gateway Column J  ,  xmlStationsNameTable[8]	

};



/*---------------End ------definitions for Xml File Import----------------------------------------------*/


/*---Start------------XML Import   For LX NextGen Systems----------------------------------------------------*/
typedef struct LXstationTypes
{
	char name[20];
}LXfpstationTypes;



LXfpstationTypes LXxmlStationTypes[4]= // {SIP , SIP fax , UP0, IP ,RAS , DeskShare ,a/b, a/b fax, ISDN, DECT }
{
   {"SIP"},
   {"SIP fax"},
   {"IP"},
   {"DeskShare"}
};
LXfpstationTypes LXxmlLicensesUserType[3]= // P,MOBILITY,DESKSHARE
{
   {"IP"},
   {"DESKSHARE"},
   {"MOBILITY"}
};
/*---End--------------XML Import   For LX NextGen Systems----------------------------------------------------*/
bool checkSipConfigInStations(char **strStation, char **strSipConfig,int countStation, int countSipConfig, int* dubentries)
{
	int i=0,j=0,entry=0,k=0;
	bool blFind=false;
	
	for(i=0; i<countSipConfig-1;   i++)
	{
		
		blFind=false;
		if(entry>19)
		break;
		
		for(j=0;  j<countStation-1;  j++)
		{
		   if( strcmp(strStation[j],strSipConfig[i])  == 0 )
		   {
		    blFind =true; 
			break;
		   }
		}
		
		if(!blFind)
		{
			
				dubentries[entry]=i+1;
				entry++;
			
		}
		
	}
	if(entry > 0)
		return  false;
	else 
		return true;
}


void LXsumNodeStationsType(char **sTypes,char **sNodes, int numSt, int &stSip, int &stIp, int &stDesk , int &vrAutoA , int &virCCfax , int &vrPark , int &virConf ,int &virFaxGroup ,int &virVirtual, int &stRasAdmin, int &stRasLic,int &virMeetMe )
{
  int i=0;
  int curNodeAtoi=0;
  RD_KDS_RETURN	kdsretNode; 
  
   
  stSip=0;
  stIp=0;
  stDesk=0;
  vrAutoA=0;
  virCCfax=0;
  vrPark=0;
  virConf=0;
  virFaxGroup=0;
  virVirtual=0;
  virMeetMe=0;
  
   kdsretNode.inhalt[3] = 0;

  for(i=0;  i<numSt; i++)
  {

     curNodeAtoi = atoi(sNodes[i]); 

     if(curNodeAtoi ==  kdsretNode.inhalt[3]) /* Count the Stations Ports ONLY for Current Node*/
     {
	if( !strcmp(sTypes[i],LXxmlStationTypes[0].name) )
	{
		stSip++;
	}
	else if( !strcmp(sTypes[i],LXxmlStationTypes[1].name) )
	{
		stSip++;
	}
	else if( !strcmp(sTypes[i],LXxmlStationTypes[2].name) )
	{
		stIp++;
	}
	else if( !strcmp(sTypes[i],LXxmlStationTypes[3].name) )
	{
		stDesk++;
	}
	else if( !strcmp(sTypes[i],xmlVirtualStationTypes[0].name) )
	{
		vrAutoA++;
	}
	else if( !strcmp(sTypes[i],xmlVirtualStationTypes[1].name) )
	{
		virCCfax++;
	}
	else if( !strcmp(sTypes[i],xmlVirtualStationTypes[2].name) )
	{
		vrPark++;
	}
	else if( !strcmp(sTypes[i],xmlVirtualStationTypes[3].name) )
	{
		virConf++; 
	}									
	else if( !strcmp(sTypes[i],xmlVirtualStationTypes[4].name) )
	{
		virFaxGroup++;
	}	
	else if( !strcmp(sTypes[i],xmlVirtualStationTypes[5].name) )
	{
		virVirtual++; 
	}				
	else if( !strcmp(sTypes[i],xmlVirtualStationTypes[6].name) )
	{
		virMeetMe++; 
	}				
          
     }// End if Current Node 
  
  }

}


bool writeXmlSipConfig(char* fname, int numSipConfig)
{		
 char line [128]; 
 FILE *fxml = fopen(fname,"r");
 int fLast,fFirst,intLen,wksFound,findNameCell=0,findCell=0,countLine=0,wksRowFound;
 string tempstr,totalstr,strData,strCell ;  
 bool blSipConfig=false,blCallFunc=false;
 int i=0,pos=0,curRecord=0,iTrnkGroupPort=11,curNodeAtoi=0,icurNodeRecords=0,fFiltDb=0;	
 char **stnNumber,**stnPassword,**stnUserId,**stnRealm,**stnNode;
 bool  firstEmpty=false,blCellEnd=false,blEndRecord=false;
 long filter=0;	
 RD_KDS_RETURN   kdsreturn;
 char stnrufnr[50];
 int tblSize = 50;// RUFNR_SIZE*2;    
 int portIndex =  0;
 long lDbFilter;
 RD_KDS_RETURN	kdsretNode;
 bool findFirst=false,findSecond=false,findThird=false,findFourth=false,findFifth=false,findSixth=false,findSeventh=false,findEighth=false; 
 
   

   //Db_rddtb(KDS_NODE_ID,KEINE_ZEILE,KEINE_SPALTE,(RD_KDS_RETURN*)&kdsretNode);
    
    stnNumber = new char*[numSipConfig+1];
	stnPassword = new char*[numSipConfig+1];
	stnUserId= new char*[numSipConfig+1];
	stnRealm= new char*[numSipConfig+1];
	stnNode= new char*[numSipConfig+1];
    

    for(i=0; i<numSipConfig+1; i++)
    {	 
	stnNumber[i]= new char[tblSize];
    	stnPassword[i]= new char[tblSize];
	stnUserId[i]= new char[tblSize];
	stnRealm[i]= new char[tblSize];
	stnNode[i]= new char[tblSize];
    }
  
    for(i=0; i<numSipConfig+1; i++)
    {	
	for(pos=0; pos<tblSize; pos++)
	{
		stnNumber[i][pos]='\0';
	    	stnPassword[i][pos]='\0';
		stnUserId[i][pos]='\0';
		stnRealm[i][pos]='\0';
		stnNode[i][pos]='\0';
	}
    }
    
    

    while(fgets ( line,128,fxml ) != NULL ) // read a line by line
    {
	
	tempstr=line; // this temp str contains the current line
	intLen = strlen(line);

	//---1-find----WorkSheet name ------------------------------
	wksFound= tempstr.find("Worksheet ss:Name");
	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
	        fFirst= tempstr.find("\"");
	        fLast=tempstr.find_last_of("\"");   
	        tempstr = tempstr.substr(fFirst+1,(fLast-(fFirst+1)));		
		

		if(tempstr == "SipConfig")
		{
	   	   blSipConfig = true;
		}
    	}// end worksheet search 

	//---2 find the End of WorkSheet-------------
	wksFound= tempstr.find("</Worksheet>");
	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
		if(blSipConfig)
		{
			blSipConfig = false;
			break;
			//return true;
		}
	}
	
	blEndRecord = false;

	wksFound = tempstr.find("</Data>");
	findNameCell = tempstr.find("<NamedCell");
	findCell = tempstr.find("</Cell>");
	wksRowFound = tempstr.find("</Row>");
	fFiltDb = tempstr.find("FilterDatabase");
	
	//  CASE  A -- Check if the line is empty, has no data, only namedcell
	if((findNameCell > -1) && (wksFound == -1)  && (fFiltDb==-1) ) 
	{
		fLast = tempstr.find("</Cell>");
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		strData = "empty";
		blEndRecord = true;
	}
	// CASE B scenario we had Data and NameCell Filled in the Same Line 		
	else if( (wksFound > -1) && (findNameCell > -1)  && (findCell >-1) )
	{			
		fLast = tempstr.find("</Cell>");
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		fLast = wksFound;  //tempstr.find("</Data>");
		fFirst = tempstr.rfind("\">");
		strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));
		blEndRecord = true;
	}
	// CASE C -- Has Data and NameCell but the Cell END is in the next Line
	else if( (wksFound > -1) && (findNameCell > -1)  && (findCell == -1) )
	{
		fLast = wksFound;  //tempstr.find("</Data>");
		fFirst = tempstr.rfind("\">");
		strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));
		if(strData.length() == 0 )
				strData = "empty";
		blCellEnd = true; // wait the end of the Cell		
	}
	else if( (findCell > -1) &&  (blCellEnd)  ) // find the end of Cell
	{
		blCellEnd = false;
		fLast = tempstr.find("</Cell>"); 
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		blEndRecord = true;	
	}
	else if(wksRowFound > -1)	
	{
		blEndRecord = true;
		strData = "</Row>";
		strCell="";
	}
	// If the Record is OK
	if(blEndRecord)
	{
//-----------------------Trunk Groups ------------------------------------------------------------------------------------------	    
	    if(blSipConfig)
	    {			
		//------------{"sipnternalnum"  ,"Internal number"}, //  Column  A   
		if ( ( strcmp(strCell.c_str(),xmlSipConfigTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[0].headerrecord)!= 0 )  )			
		{
			if (strData =="empty")
			{
				firstEmpty=true;
				blSipConfig = false;
			}
			else
			{
				firstEmpty=false;
				strcpy(stnNumber[curRecord],strData.c_str());
				findFirst=true; 
			 }			
		}		
		//---{"sippassword"    ,"Password"},	//  Column  B   
		else if ( ( strcmp(strCell.c_str(),xmlSipConfigTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[1].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) ||  (strcmp(strData.c_str(),"-") ==0) )
					strcpy(stnPassword[curRecord],"");
				else
					strcpy(stnPassword[curRecord],strData.c_str());		
	
				findSecond=true; 	
			}
		}						
		//---{"sipuseridname"  ,"UserId/Username"},  	//  Column  C	
		else if ( ( strcmp(strCell.c_str(),xmlSipConfigTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[2].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) ||  (strcmp(strData.c_str(),"-") ==0) )
				  strcpy(stnUserId[curRecord],"0");
				else
				 strcpy(stnUserId[curRecord],strData.c_str());
				
				findThird=true; 			
			}
		}
		//---{"siprealm"       ,"Realm"},  	//  Column  D
		else if ( ( strcmp(strCell.c_str(),xmlSipConfigTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[3].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) ||  (strcmp(strData.c_str(),"-") ==0) )
				  strcpy(stnRealm[curRecord],"0");
				else
				 strcpy(stnRealm[curRecord],strData.c_str());
				
				findFourth=true; 			
			}
		}
		//---{"sipnode"       ,"Node"}  	//  Column  E	
		else if ( ( strcmp(strCell.c_str(),xmlSipConfigTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[4].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) ||  (strcmp(strData.c_str(),"-") ==0) )
				  strcpy(stnNode[curRecord],"0");
				else
				 strcpy(stnNode[curRecord],strData.c_str());
				
				findFourth=true; 			
			}
		}
		//------Else if End Row--- The Current Record Finished---------------------------
		else if( strcmp(strData.c_str(),"</Row>")  == 0  )
		{
			if( findFirst) // If has Call Number 
			{								   			
				curRecord++; 
			}
			
			findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; 
		}		

	      }//  END blTrunkGroup 
//-----------------------END Trunk Groups------------------------------------------------------------------------------------------	    

	      	
	} //end If blEndRecord
		

	countLine++;//increase countLines number to numberring Lines   
	
    }  // ----end while read lines-------
    
    fclose(fxml);
	
    int retport=-1;
	
    for(i=0;  i<curRecord;  i++)
    {	
	curNodeAtoi = atoi(stnNode[i]);
	retport=-1;
	
	
	if(curNodeAtoi == 0 ) // Means The Same Node As the System 
	{
	
	
       		//retport  = GetStationPort(stnNumber[i]) ;
		if (retport > -1)
		{
		   if (strcmp(stnPassword[i],"empty") !=0) 
			   printf("lias");
		   //	fFpSetStnDbWorkpointPwd(retport,  (FPString*)stnPassword[i], strlen(stnPassword[i]),true);
		   if (strcmp(stnUserId[i],"empty") !=0) 				   
		   //	fFpSetStnDbSipClUserId(retport, stnUserId[i], strlen(stnUserId[i]));
		     printf("lias1");
		   if (strcmp(stnRealm[i],"empty") !=0) 
			     printf("lias2");
		   //	fFpSetStnDbSipClRealm(retport, stnRealm[i], strlen(stnRealm[i]));
		}
	
      }  
   }  
      
      
      
   for(i=0; i<numSipConfig+1; i++)
    {	 
	    delete []stnNumber[i];
    	delete []stnPassword[i];
		delete []stnUserId[i];
		delete []stnRealm[i];
		delete []stnNode[i];
    }
  
  
    delete []stnNumber;
    delete []stnPassword;
	delete []stnUserId;
	delete []stnRealm;
	delete []stnNode;
   
      
	
	if(icurNodeRecords ==0)
	return false;
	else 
	return true;
}

bool checkvalidAccess(char* num)
{
	int i=0;
	
	for(i=0; i<strlen(num); i++)
	{
		if(num[i] < 48 ||  num[i]>57)
		{
			if(num[i] != 45)
			return false;
		}
	}
	
	return true;

}

 // The Function Check If the Station Type is contained in the default List,If Not Return False, if it's ok Return True
 bool LXCheckStationType(const char* strTypes)
 {
     int i,k=0;
     
 
     for(i=0; i <4; i++)
     {
     	if( strcmp(strTypes,LXxmlStationTypes[i].name)  == 0 )
	k++;
	
     }	
     
     if (k>0)
     return true;
     else
     return false;
 
 }
 
 bool checkFaxDuplicate(char **stnNumbers,char **stnFaxes, int countNumbers, int faxCount, int* dubentries)
{
    int i=0,j=0,entry=0,k=0;
    bool blFind;
    
    for(i=0;  i<faxCount;  i++)
    {        
    	blFind = false;	
	
	for(j=0; j<countNumbers; j++)
	{
	  if( strcmp(stnNumbers[j],stnFaxes[i]) == 0 )
	  {
	     
	     if((strcmp(stnNumbers[j],"empty")!=0)    &&   (strcmp(stnFaxes[i],"empty")!=0) )
	     blFind = true;   	 
	  }
	}
    
        if(blFind)
	{
	    
	    if(entry > 0 )
	    {
	    	for(k=0; k<entry; k++)
		{
			if( dubentries[k] == i+1)
			{
				entry = entry;
			}
			else
			{
			      dubentries[entry]=i;
		              entry++;
			}
			
		}
	    }
	    else
	    {
		    dubentries[entry]=i+1;
		    entry++;
	    }
	}
    
    }

    if(entry>0)
    return false;
    else 
    return true;

}
 bool LXCheckLicenseUserType(const char* strTypes)
 {
     int i,k=0;
     
 
     for(i=0; i <3; i++)
     {
     	if( strcmp(strTypes,LXxmlLicensesUserType[i].name)  == 0 )
	k++;
	
     }	
     
     if (k>0)
     return true;
     else
     return false;
 
 }
 
 

  
int my_strlen_utf8_c(const char *s) {
   int i = 0, j = 0;
   while (s[i]) {
     if ((s[i] & 0xc0) != 0x80) j++;
     i++;
   }
   return j;
}

bool checkVoicemailNumbers( char **voicemail, char **node,int numRecords)
{
  int i=0,cntVoicemail=0;
  int curNodeAtoi=0;
  RD_KDS_RETURN	kdsretNode; 
  
   kdsretNode.inhalt[3] = 1;
  for(i=0;  i<numRecords; i++)
  {

     curNodeAtoi = atoi(node[i]); 

     if(curNodeAtoi ==  kdsretNode.inhalt[3]) /* Count the Stations Ports ONLY for Current Node*/
     {
     	if( strcmp(voicemail[i],"X")==0     ||    strcmp(voicemail[i],"x")==0 )
	   cntVoicemail++;
     	
     }
  }
  
  if(cntVoicemail > 320)
  return false;
  else
  return true;
  
}
/*-------------------------------------------------------*/
bool checkvalidmail(char* email)
{
	int j=0, i=0, counter=0;

        int mailsize=strlen(email);
	for (j=0; j<mailsize; j++)  
	{
		if (email[j]==64)
		{
			for(i=j+1; i<mailsize; i++)
			{
				if (email[i]==64)
					return false;
				if (email[i]==46)
					counter++;        
			}
			break;
		}

       }
	if (counter>0)
		return true;
	else
		return false;
}
bool checkdouble(char **input, int &linesnumber, int* dubentries)

{

    int i=0,k=0,j=0,entry=0;

    for(i=0;i<linesnumber;i++)
	{
		k=i+1;
		for(j=k;j<linesnumber;j++)
		{
			if((!strcmp(input[i],""))  ||  (!strcmp(input[i],"-"))   ||  (!strcmp(input[i],"empty"))  )
				break;
			if(!strcmp(input[i],input[j]))
			{
				if(entry>19)
					break;
				
				
				dubentries[entry]=j+1;
				entry++;
				break;
			}
		}
	}
	//linesnumber=entry;
	if(entry)
		return false;
	else
		return true;
}
bool checkdoubledigits(char **input, int &linesnumber, int* dubentries)

{
    
    int aLen=0,bLen=0,cmpLen=0,i=0,j=0,k=0,entry=0,rs=0,rsEnd=0;
    bool rfind=false;


	for(i=0; i<20; i++)
    {
      if(dubentries[i] !=0)
		rsEnd++;
    }

    for(i=0;i<linesnumber;i++)
	{
		k=i+1;
		for(j=k;j<linesnumber;j++)
		{
			
			aLen = strlen(input[i]);
			bLen = strlen(input[j]);
			if(aLen> bLen)
				cmpLen=bLen;
			else
				cmpLen=aLen;
				
			
			
			
			if((!strcmp(input[i],""))  ||  (!strcmp(input[i],"-"))   ||  (!strcmp(input[i],"empty"))  )
				break;
				
			if(strncmp( input[i], input[j],cmpLen)  == 0 )
			{
				if(entry>19)
					break;
				
				
				for(rs=0;  rs<rsEnd; rs++)
				{
				    if(dubentries[rs] == j+1)	
				      rfind=true;
				}
				
				if(!rfind)
				{
					dubentries[entry]=j+1;
					entry++;
				}
				break;
			}
			
			aLen=0;
			bLen=0;
			cmpLen=0;
			rfind=false;
		}
	}
	//linesnumber=entry;
	if(entry)
		return false;
	else
		return true;
}
bool checkvalidCallDuwa(char* number)
{

	int i=0,j=0,k=0,counter=0,position=0,counter1=0,counter2=0,counter3=0;
	int numbersize=strlen(number);

	bool symbol=false;

	if (number[0]==35 || number[0]==42) // 35= '#' , 42= '*'
		symbol=true;
	
	if(!symbol)

		for (i=0; i<numbersize; i++)  
			{
			
			if (number[i]<48 || number[i]>57)	
				return false;
			}
	else
		{
		for (i=1; i<numbersize; i++)  
			{
				if(number[i]<48 || number[i]>57)
				{
					return false;
				}
					
					
			}
		}

	return true;
}






bool checkvalidnumber(char* call)
{

	int i=0,j=0,k=0,counter=0,position=0,counter1=0,counter2=0,counter3=0,all_digits=0;
	int callsize=strlen(call);

	bool plus=false;
	if (call[0]==43) // 43= '+'
		{
		plus=true;
		for (i=1; i<callsize; i++)  
		 {			
		  if (call[i]<48 || call[i]>57)	
				all_digits++;
		 }
		 if(!all_digits)
		    return true;
		}
	
	if(!plus)

		for (i=0; i<callsize; i++)  
			{
			
			if (call[i]<48 || call[i]>57)	
				return false;
			}
	else
		{
		for (i=1; i<callsize; i++)  
			{
				if(call[i]<48 || call[i]>57)
				{
					if(call[i]!=32)
					{
						if(call[i]!=40)
						{
							if(call[i]!=41) 
							   return false;
						}
					}
				}
					
					
				if (call[i]==40)    //40= '('
					{
						if(call[i+1]<48 || call[i+1]>57)
							return false;
				
						else				
							counter1++;

						if (counter1>1)
							return false;
					}
				
				
				
				if (call[i]==41)    // 41= ')'
					{	
						if(counter1!=1)
							return false;
							
						if(call[i-1]<48 || call[i-1]>57)
							return false;
						else 				
							counter2++;
						
						if(counter2>1)
							return false;
					}
					

				if (call[i]==32) // 32= ' '
					{
							
						if (!((call[i+1]==40 && (call[i-1]>47 || call[i-1]<58)) || (call[i-1]==41 && (call[i+1]>47 || call[i+1]<58))))	
							return false;
							
						else 
							counter3++;
					}
			}

	if(counter1!=1 || counter2!=1 ||counter3!=2 )
		return false;
		}

	return true;
}





 // The Function Check If the Station Type is contained in the default List,If Not Return False, if it's ok Return True
 bool CheckStationType(const char* strTypes)
 {
     int i,k=0;
     
 
     for(i=0; i <12; i++)
     {
     	if( strcmp(strTypes,xmlStationTypes[i].name)  == 0 )
	k++;
	
     }	
     
     if (k>0)
     return true;
     else
     return false;
 
 }
 
 bool CheckStationTypeVirtual(const char* strTypes)
 {
     int i,k=0;
     
 
     for(i=0; i <7; i++)
     {
     	if( strcmp(strTypes,xmlVirtualStationTypes[i].name)  == 0 )
	k++;
	
     }	
     
     if (k>0)
     return true;
     else
     return false;
 
 }
 
 bool CheckLicenseUserType(const char* strTypes)
 {
     int i,k=0;
     
 
     for(i=0; i <4; i++)
     {
     	if( strcmp(strTypes,xmlLicensesUserType[i].name)  == 0 )
	k++;
	
     }	
     
     if (k>0)
     return true;
     else
     return false;
 
 }
 
 
 // Returns FALSE(0)  if Error, TRUE(CORRECT)
 bool compare_extension(char *filename, char *extension)
{
   

    if(filename == NULL || extension == NULL)
        return false;

    if(strlen(filename) == 0 || strlen(extension) == 0)
        return false;

    if(strchr(filename, '.') == NULL || strchr(extension, '.') == NULL)
        return false;

    /* Iterate backwards through respective strings and compare each char one at a time */

    for(int i = 0; i < strlen(filename); i++)
    {
        if(tolower(filename[strlen(filename) - i - 1]) == tolower(extension[strlen(extension) - i - 1]))
        {
            if(i == strlen(extension) - 1)
                return true;
        } else
            break;
    }

    return false;
}

bool checkAccessType(char **input, int &linesnumber, int* dubentries, int icaseFlag, int CheckType) //icaseFlag  0 Analog , 1 UP0 // CheckType=0 check the Format ,ChekType=1 Check the Slots
{
	RD_KDS_RETURN   kdsreturn;
	int i=0,iSlot=0,iCard=0,ic=0,ientries=0,iPort=0;
	int phyPort;
	string str="";
	string strFirst="";
	string strSlot="";
	string strLine="";
	string strPort = "";
	string tmpString="";
	
	
	
	/*  Check the Access Type. The Access Type For Up0 and Analog should be filled in all records or empty*/
	if( CheckType == 0)
	{	
		
		strFirst =  input[0];	
		strFirst = strFirst.substr(0,strFirst.find(","));
		//cout <<" ilias strFirst="<<strFirst<<", linesnumber="<<linesnumber<<endl;
		
		for(i=1; i<linesnumber; i++)
		{
			
			str = input[i];			
			strLine = str.substr(str.find(",") +1);
			str = str.substr(0,str.find(","));			
			
			
			//ic++;
			//cout <<"  strFirst.find(empty)="<<strFirst.find("empty")<<endl;
			
			//if( strFirst.find("empty") > -1  ) // means the first is empty 
			if( strcmp(strFirst.c_str(),"empty") == 0   )
			{
				if(  strcmp(str.c_str(),"empty") !=0   )
				{
				  dubentries[ientries] =  atoi(strLine.c_str());// linesnumber;
				  ientries++;
				 } 
			}
			else // the first is not empty
			{
				if(  strcmp(str.c_str(),"empty") ==0   )
				{
				  dubentries[ientries] = atoi(strLine.c_str()); // linesnumber;
				  ientries++;
				 } 
				
			}
		}
		
		if( (ientries == 0)  &&  (strcmp(strFirst.c_str(),"empty") != 0) )
		{			
			return true;
		}
		else if( (ientries == 0)  &&  (strcmp(strFirst.c_str(),"empty") == 0) )
		{	
			return false;		
		}
		else 
		{
			return false;
			
		}	
		
		
		/*
		
		if( ic == linesnumber) 
		{
			return false;
		}
		else if( (ic >0)  && (ic != linesnumber)   )
		{
			dubentries[0] = 1111;
			return false;
		}
		else if(ic ==0)
		{
			return true;
		}	
		
		*/
	}
	
	
	
	
	/* Check if The Current Slot Exists in the System , if not return Error*/
	if(CheckType == 1)
	{
	
	for(i=0; i< linesnumber;  i++)
	{
	 // strcpy(str.c_str(),input[i]);
	 str = input[i];
	 tmpString = str.substr(0,str.find(","));
	  //str = str.substr(0,str.find(","));

	  if( strcmp(tmpString.c_str(),"empty")  )
	    continue;
	  
	  strSlot = str.substr(0,str.find("-"));
	  strLine = str.substr(str.find(",") +1);
	  strPort = str.substr(str.find("-")+1, str.find(",") );

	  if(strSlot.length() > 0)
	  {    
	  	iSlot = atoi(strSlot.c_str());	
		iPort = atoi(strPort.c_str());
		//db_rddtb(KDS_DB_CARD_TBL, iSlot, KEINE_SPALTE, &kdsreturn);
		iCard = 1; kdsreturn.inhalt[0]; // get the Slot type

		
		if((iSlot > 25)  ||  (iCard == 0xFFFF) )
		{
			dubentries[ientries] = atoi(strLine.c_str());
			ientries++;
			continue;
		}
		
		if(icaseFlag ==0 )// analog check
		{
		
	      		if(     iCard != 1           /*Analog*/         
				&& iCard != 2)
			
			{					
					dubentries[ientries] = atoi(strLine.c_str());
					ientries++;
			}
		}// end analog Check
		
		else if(icaseFlag ==1 )// UP0 check
		{
		
		
	      		if(	iCard != 1  /*UP0*/
				&& iCard != 2 
				&& iCard != 3
				)
				{
					dubentries[ientries] = atoi(strLine.c_str());
					ientries++;					
 				}
		} // end UP0 check

		
		
			
	  }
	  
	 } 
	 
	} // end Check Type ==1 
	
}
 
bool checkNodeType(char **input, int &linesnumber, int* dubentries)
{

    int i=0,entry=0;


    
    for(i=0; i < linesnumber; i++)
    {
    	if(!checkvalidCallDuwa(input[i]))
	{
	        dubentries[entry]=i+1;
		entry++;	
	}
    }
    
    /*
    
    if(!strcmp(input[0],"0") )
    {	
	    for(i=1;i<linesnumber;i++)
	    {
			

		//if (  atoi(input[i]) > 0  )
		if ( strcmp( input[i] , "0")  !=0 )
		{
			dubentries[entry]=i+1;
			entry++;
		}				
    	    }
   }
   else //  Is Number
   {
	    for(i=1;i<linesnumber;i++)
	    {
			
		//if (  atoi(input[i])  < 1  )
		if ( strcmp( input[i] , "0")  ==0   )
		{
			dubentries[entry]=i+1;
			entry++;
		}		
    	    }
   }
*/
   
    if(entry)
	return false;
    else
	return true;
}

bool checkLicensesNumbers(char **stnNumbers,char **stnLicNums, int countNumbers, int CountLics, int* dubentries)
{

    int i=0,j=0,entry=0;;
    bool blFind;
    
    
    for(i=0;  i<CountLics;  i++)
    {        
    	blFind = false;	
	
	for(j=0; j<countNumbers; j++)
	{
	  if( strcmp(stnNumbers[j],stnLicNums[i]) == 0 )
	     blFind = true;   	 
	}
    
        if(!blFind)
	{
	    dubentries[entry]=i+1;
	    entry++;
	}
    
    }

    if(entry>0)
    return false;
    else 
    return true;
    
}  
int  GetLogPortFromSlotPort(int iSlot,int iPort, int iLogId)// 
{
	int i=0,cur=0,slt=0,port=0,logid=0,rc=-1;
	 RD_KDS_RETURN   kdsreturn;

	for(i=0; i<100; i++)
	{
		cur =  2;
	        //db_rddtb ( KDS_LPORT_SLOT_RELPORT,  (DB_ZEILE_T) i,  KEINE_SPALTE,   &kdsreturn);
		slt = 1;//  kdsreturn.inhalt[0];
	    	port = kdsreturn.inhalt[1];
    		logid = kdsreturn.inhalt[2];
		
		
		if( (port == iPort)  && (slt==iSlot)  && (logid == iLogId) )
		{
			rc = i;
			break;
			//return i;
		}

	}
	return rc;
}
bool checkNumberOfStations(int &stUp0, int &stAn, int &stDect, int &stIsdn) /* Get the Numbher of Stations From the System */
{
	int i=0,countUp0=0,countAnal=0,cur=0,islt=0,iport=0,ilogid=0;
	 RD_KDS_RETURN   kdsreturn;

	for(i=0; i<NR_TLN; i++)
	{
	      
	      cur =  2;

		switch(cur)
		{

			case 1: 
		        {
			  stUp0++;		  
  				    /*
				    db_rddtb ( KDS_LPORT_SLOT_RELPORT,  (DB_ZEILE_T) i,  KEINE_SPALTE,   &kdsreturn);
				    islt =  kdsreturn.inhalt[0];
				    iport = kdsreturn.inhalt[1];
				    ilogid = kdsreturn.inhalt[2];
				    */
				    
			  break;
			}
			case 2: 
		        {
			  stAn++;
			  break;
			}			
			case 3 : // ISDN
			{
			  //stDect++;	
			  stIsdn++;
			  break;
			}			
			case 4 :// DECT
			{
			   stDect++;
			   //stIsdn++;
			   break;
			}
						

		}
	}


	return true;

}


int  GetStationPort(char curStation[50])
{
   int curPort=0;
   char RnrString[50]={0};
   int retvalue=0;
    
   
   
   
      return 1;

}

void sumNodeStationsType(char **sTypes,char **sNodes, int numSt, int &stSip, int &stUp0, int &stIp, int &stRas , int &stDesk , int &stAb , int &stIsdn , int &stDect ,int &vrAutoA , int &virCCfax , int &vrPark , int &virConf ,int &virFaxGroup ,int &virVirtual, int &stRasAdmin, int &stRasLic,int &virMeetMe )
{
  int i=0;
  int curNodeAtoi=0;
  RD_KDS_RETURN	kdsretNode; 
 // Db_rddtb(KDS_NODE_ID,KEINE_ZEILE,KEINE_SPALTE,(RD_KDS_RETURN*)&kdsretNode);
  kdsretNode.inhalt[3] = 0;

  stSip=0;
  stUp0=0;
  stIp=0;
  stRas=0;
  stDesk=0;
  stAb=0;
  stIsdn=0;
  stDect=0;
  vrAutoA=0;
  virCCfax=0;
  vrPark=0;
  virConf=0;
  virFaxGroup=0;
  virVirtual=0;
  virMeetMe=0;  
  
  for(i=0;  i<numSt; i++)
  {

     curNodeAtoi = atoi(sNodes[i]); 

     if(curNodeAtoi ==  kdsretNode.inhalt[3]) /* Count the Stations Ports ONLY for Current Node*/
     {
	if( !strcmp(sTypes[i],xmlStationTypes[0].name) )
	{
		stSip++;
	}
	else if( !strcmp(sTypes[i],xmlStationTypes[1].name) )
	{
		stSip++;
	}
	else if( !strcmp(sTypes[i],xmlStationTypes[2].name) )
	{
		stUp0++;
	}
	else if( !strcmp(sTypes[i],xmlStationTypes[3].name) )
	{
		stIp++;
	}
	else if( !strcmp(sTypes[i],xmlStationTypes[4].name) )
	{
		stRas++;
	}
	else if( !strcmp(sTypes[i],xmlStationTypes[5].name) )
	{
		stDesk++;
	}
	else if( !strcmp(sTypes[i],xmlStationTypes[6].name) )
	{
		stAb++;
	}
	else if( !strcmp(sTypes[i],xmlStationTypes[7].name) )
	{
		stAb++;
	}
	else if( !strcmp(sTypes[i],xmlStationTypes[8].name) )
	{
		stIsdn++;
	}
	else if( !strcmp(sTypes[i],xmlStationTypes[9].name) )
	{
		stDect++;
	}			
	else if( !strcmp(sTypes[i],xmlStationTypes[10].name) )
	{
		stRasAdmin++;
	}			
	else if( !strcmp(sTypes[i],xmlStationTypes[11].name) )
	{
		stRasLic++;
	}			
	else if( !strcmp(sTypes[i],xmlVirtualStationTypes[0].name) )
	{
		vrAutoA++;
	}
	else if( !strcmp(sTypes[i],xmlVirtualStationTypes[1].name) )
	{
		virCCfax++;
	}
	else if( !strcmp(sTypes[i],xmlVirtualStationTypes[2].name) )
	{
		vrPark++;
	}
	else if( !strcmp(sTypes[i],xmlVirtualStationTypes[3].name) )
	{
		virConf++;
	}									
	else if( !strcmp(sTypes[i],xmlVirtualStationTypes[4].name) )
	{
		virFaxGroup++;
	}	
	else if( !strcmp(sTypes[i],xmlVirtualStationTypes[5].name) )
	{
		virVirtual++; 
	}
	else if( !strcmp(sTypes[i],xmlVirtualStationTypes[6].name) )
	{
		virMeetMe++; 
	}					
     
     }// End if Current Node 
  
  }

}

bool LXwriteXmlSipConfig(char* fname, int numSipConfig)
{		
 char line [128]; 
 FILE *fxml = fopen(fname,"r");
 int fLast,fFirst,intLen,wksFound,findNameCell=0,findCell=0,countLine=0,wksRowFound;
 string tempstr,totalstr,strData,strCell ;  
 bool blSipConfig=false,blCallFunc=false;
 int i=0,pos=0,curRecord=0,iTrnkGroupPort=11,curNodeAtoi=0,icurNodeRecords=0,fFiltDb=0;	
 char **stnNumber,**stnPassword,**stnUserId,**stnRealm,**stnNode;
 bool  firstEmpty=false,blCellEnd=false,blEndRecord=false;
 long filter=0;	
 RD_KDS_RETURN   kdsreturn;
 char stnrufnr[50];
 int tblSize = 50;// RUFNR_SIZE*2;    
 //WORD portIndex =  NO_PORT;
 long lDbFilter;
 RD_KDS_RETURN	kdsretNode;
 bool findFirst=false,findSecond=false,findThird=false,findFourth=false,findFifth=false,findSixth=false,findSeventh=false,findEighth=false; 
 
   

   //Db_rddtb(KDS_NODE_ID,KEINE_ZEILE,KEINE_SPALTE,(RD_KDS_RETURN*)&kdsretNode);
    
    stnNumber = new char*[numSipConfig+1];
	stnPassword = new char*[numSipConfig+1];
	stnUserId= new char*[numSipConfig+1];
	stnRealm= new char*[numSipConfig+1];
	stnNode= new char*[numSipConfig+1];
    

    for(i=0; i<numSipConfig+1; i++)
    {	 
	stnNumber[i]= new char[tblSize];
    	stnPassword[i]= new char[tblSize];
	stnUserId[i]= new char[tblSize];
	stnRealm[i]= new char[tblSize];
	stnNode[i]= new char[tblSize];
    }
  
    for(i=0; i<numSipConfig+1; i++)
    {	
	for(pos=0; pos<tblSize; pos++)
	{
		stnNumber[i][pos]='\0';
	    	stnPassword[i][pos]='\0';
		stnUserId[i][pos]='\0';
		stnRealm[i][pos]='\0';
		stnNode[i][pos]='\0';
	}
    }
    
    

    while(fgets ( line,128,fxml ) != NULL ) // read a line by line
    {
	
	tempstr=line; // this temp str contains the current line
	intLen = strlen(line);

	//---1-find----WorkSheet name ------------------------------
	wksFound= tempstr.find("Worksheet ss:Name");
	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
	        fFirst= tempstr.find("\"");
	        fLast=tempstr.find_last_of("\"");   
	        tempstr = tempstr.substr(fFirst+1,(fLast-(fFirst+1)));		
		

		if(tempstr == "SipConfig")
		{
	   	   blSipConfig = true;
		}
    	}// end worksheet search 

	//---2 find the End of WorkSheet-------------
	wksFound= tempstr.find("</Worksheet>");
	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
		if(blSipConfig)
		{
			blSipConfig = false;
			break;
			//return true;
		}
	}
	
	blEndRecord = false;

	wksFound = tempstr.find("</Data>");
	findNameCell = tempstr.find("<NamedCell");
	findCell = tempstr.find("</Cell>");
	wksRowFound = tempstr.find("</Row>");
	fFiltDb = tempstr.find("FilterDatabase");
	
	//  CASE  A -- Check if the line is empty, has no data, only namedcell
	if((findNameCell > -1) && (wksFound == -1)  && (fFiltDb==-1) ) 
	{
		fLast = tempstr.find("</Cell>");
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		strData = "empty";
		blEndRecord = true;
	}
	// CASE B scenario we had Data and NameCell Filled in the Same Line 		
	else if( (wksFound > -1) && (findNameCell > -1)  && (findCell >-1) )
	{			
		fLast = tempstr.find("</Cell>");
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		fLast = wksFound;  //tempstr.find("</Data>");
		fFirst = tempstr.rfind("\">");
		strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));
		blEndRecord = true;
	}
	// CASE C -- Has Data and NameCell but the Cell END is in the next Line
	else if( (wksFound > -1) && (findNameCell > -1)  && (findCell == -1) )
	{
		fLast = wksFound;  //tempstr.find("</Data>");
		fFirst = tempstr.rfind("\">");
		strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));
		if(strData.length() == 0 )
				strData = "empty";
		blCellEnd = true; // wait the end of the Cell		
	}
	else if( (findCell > -1) &&  (blCellEnd)  ) // find the end of Cell
	{
		blCellEnd = false;
		fLast = tempstr.find("</Cell>"); 
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		blEndRecord = true;	
	}
	else if(wksRowFound > -1)	
	{
		blEndRecord = true;
		strData = "</Row>";
		strCell="";
	}
	// If the Record is OK
	if(blEndRecord)
	{
//-----------------------Trunk Groups ------------------------------------------------------------------------------------------	    
	    if(blSipConfig)
	    {			
		//------------{"sipnternalnum"  ,"Internal number"}, //  Column  A   
		if ( ( strcmp(strCell.c_str(),xmlSipConfigTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[0].headerrecord)!= 0 )  )			
		{
			if (strData =="empty")
			{
				firstEmpty=true;
				blSipConfig = false;
			}
			else
			{
				firstEmpty=false;
				strcpy(stnNumber[curRecord],strData.c_str());
				findFirst=true; 
			 }			
		}		
		//---{"sippassword"    ,"Password"},	//  Column  B   
		else if ( ( strcmp(strCell.c_str(),xmlSipConfigTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[1].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) ||  (strcmp(strData.c_str(),"-") ==0) )
					strcpy(stnPassword[curRecord],"");
				else
					strcpy(stnPassword[curRecord],strData.c_str());		
	
				findSecond=true; 	
			}
		}						
		//---{"sipuseridname"  ,"UserId/Username"},  	//  Column  C	
		else if ( ( strcmp(strCell.c_str(),xmlSipConfigTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[2].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) ||  (strcmp(strData.c_str(),"-") ==0) )
				  strcpy(stnUserId[curRecord],"0");
				else
				 strcpy(stnUserId[curRecord],strData.c_str());
				
				findThird=true; 			
			}
		}
		//---{"siprealm"       ,"Realm"},  	//  Column  D
		else if ( ( strcmp(strCell.c_str(),xmlSipConfigTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[3].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) ||  (strcmp(strData.c_str(),"-") ==0) )
				  strcpy(stnRealm[curRecord],"0");
				else
				 strcpy(stnRealm[curRecord],strData.c_str());
				
				findFourth=true; 			
			}
		}
		//---{"sipnode"       ,"Node"}  	//  Column  E	
		else if ( ( strcmp(strCell.c_str(),xmlSipConfigTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[4].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) ||  (strcmp(strData.c_str(),"-") ==0) )
				  strcpy(stnNode[curRecord],"0");
				else
				 strcpy(stnNode[curRecord],strData.c_str());
				
				findFourth=true; 			
			}
		}
		//------Else if End Row--- The Current Record Finished---------------------------
		else if( strcmp(strData.c_str(),"</Row>")  == 0  )
		{
			if( findFirst) // If has Call Number 
			{								   			
				curRecord++; 
			}
			
			findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; 
		}		

	      }//  END blTrunkGroup 
//-----------------------END Trunk Groups------------------------------------------------------------------------------------------	    

	      	
	} //end If blEndRecord
		

	countLine++;//increase countLines number to numberring Lines   
	
    }  // ----end while read lines-------
    
    fclose(fxml);
	
    int retport=-1;
    
    for(i=0;  i<curRecord;  i++)
    {	
	curNodeAtoi = atoi(stnNode[i]);
	retport=-1;
	
	
	if(curNodeAtoi == kdsretNode.inhalt[3] ) // Means The Same Node As the System 
	{
	
	
       		retport  = GetStationPort(stnNumber[i]) ;
		
		/*
		if (retport > -1)
		{
		   if (strcmp(stnPassword[i],"empty") !=0) 
		   //	fFpSetStnDbWorkpointPwd(retport,  (FPString*)stnPassword[i], strlen(stnPassword[i]),false);
		   if (strcmp(stnUserId[i],"empty") !=0) 				   
		   //	fFpSetStnDbSipClUserId(retport, stnUserId[i], strlen(stnUserId[i]));
		   if (strcmp(stnRealm[i],"empty") !=0) 
		   //	fFpSetStnDbSipClRealm(retport, stnRealm[i], strlen(stnRealm[i]));
		}*/
	
      }  
   }  
      
      
      
   for(i=0; i<numSipConfig+1; i++)
    {	 
	    delete []stnNumber[i];
    	delete []stnPassword[i];
		delete []stnUserId[i];
		delete []stnRealm[i];
		delete []stnNode[i];
    }
  
  
    delete []stnNumber;
    delete []stnPassword;
	delete []stnUserId;
	delete []stnRealm;
	delete []stnNode;
   
      
	
	if(icurNodeRecords ==0)
	return false;
	else 
	return true;
}
//----------------loloca
bool writeXmlStations(char* fname, int numStations, int &voicemailCounter)
{
   char line [128]; 
    FILE *fxml = fopen(fname,"r");
    int fLast,fFirst,intLen,wksFound,findNameCell=0,findCell=0,countLine=0,wksRowFound,fFiltDb=0;
    string tempstr,totalstr,strData,strCell,tmpStrAccess ;  
    bool blStations=false,blCallFun=false;
    int i=0,pos=0,curRecord=0,curNodeAtoi=0,iSlot=0,iPort=0,iLogId=0;	
   // PORT_T phyPort;
    char **stnNumber,**stnDuwa,**stnDisplay,**stnStation,**stnEmail,**stnMobile,**stnNode,**stnGw,**stnAccessSlot,**stnAccessPort,**stnAccessLogId,**stnVoicemail, **stnFaxCallno, **stnFaxDid, **stnCos, **stnCallPick, **stnFaxName;
    char **logPorts,**sEmails,**sMobiles;
    bool  firstEmpty=false,blCellEnd=false,blEndRecord=false;
    int  stSipCounter=0, stUp0Counter=0, stIpCounter=0, stRasCounter=0, stDeskCounter=0, stAnalogIndex=0, stIsdnCounter=0, stDectCounter=0, stRasAdminCounter=0, stRasLicCounter=0,iVslCounter=0;
    long filter=0;	
    RD_KDS_RETURN   kdsreturn,rdrecflag,rdgrp1evm,rdgrp2evm;;
   // WR_KDS_RETURN   wrreturn;
    char stnrufnr[50];
    int tblSize = 50;// RUFNR_SIZE*2;
    RD_KDS_RETURN	kdsretNode;
    int startIndexSip=0, startIndexIp=0,startIndexRas=0,startIndexDesk=0,icurNodeRecords=0,evmCounter=0,wFaxPort=-1;
    bool findFirst=false,findSecond=false,findThird=false,findFourth=false,findFifth=false,findSixth=false,findSeventh=false,findEighth=false,findNingth=false, findTenth=false, findEleventh=false, findTwelveth=false,findThrirteenth=false;     
    // DB_INHALT_T inhalt[500];
     int s0_idx; 
     char *tmpNumbers;
    // DB_OSO_PORTS    write_data; 
    RD_KDS_RETURN   uc_buffer;
   // DB_INHALT_T grp;
           
     
        
    stnNumber = new char*[numStations];
    stnDuwa = new char*[numStations];
    stnDisplay = new char*[numStations];
    stnStation = new char*[numStations];
    stnEmail = new char*[numStations];
    stnMobile = new char*[numStations];
    stnNode = new char*[numStations];
    stnGw = new char*[numStations];
    stnAccessSlot= new char*[numStations];
    stnAccessPort= new char*[numStations];
    stnAccessLogId= new char*[numStations];
    stnVoicemail= new char*[numStations];
    stnFaxCallno= new char*[numStations];
    stnFaxDid= new char*[numStations];
    stnCos= new char*[numStations];
    stnCallPick= new char*[numStations];
    stnFaxName = new char*[numStations];
    
    for(i=0; i<numStations; i++)
    {	 
	stnNumber[i]= new char[tblSize];
	stnDuwa[i] =new char[tblSize];
    	stnDisplay[i] = new char[tblSize];
    	stnStation[i] = new char[tblSize];
    	stnEmail[i] = new char[MAX_EMAIL];
    	stnMobile[i] = new char[tblSize];
    	stnNode[i] = new char[tblSize];
    	stnGw[i] = new char[tblSize];
	stnAccessSlot[i] = new char[tblSize];
	stnAccessPort[i] = new char[tblSize];
	stnAccessLogId[i] = new char[tblSize];
	stnVoicemail[i] = new char[tblSize];
	stnFaxCallno[i] = new char[tblSize];
    	stnFaxDid[i] = new char[tblSize];
    	stnCos[i] = new char[tblSize];
    	stnCallPick[i] = new char[tblSize];
	stnFaxName[i] = new char[tblSize];
    }
  
    for(i=0; i<numStations; i++)
    {	
	for(pos=0; pos<tblSize; pos++)
	{
		stnNumber[i][pos]='\0';
		stnDuwa[i][pos]='\0';
    		stnDisplay[i][pos]='\0';
	    	stnStation[i][pos]='\0';	    	
	    	stnMobile[i][pos]='\0';
	    	stnNode[i][pos]='\0';
	    	stnGw[i][pos]='\0';
		stnAccessSlot[i][pos]='\0';
		stnAccessPort[i][pos]='\0';
		stnAccessLogId[i][pos]='\0';
		stnVoicemail[i][pos]='\0';
		stnFaxCallno[i][pos]='\0';
	    	stnFaxDid[i][pos]='\0';
    		stnCos[i][pos]='\0';
	    	stnCallPick[i][pos]='\0';
		stnFaxName[i][pos]='\0';
	}
	for(pos=0; pos<MAX_EMAIL; pos++)
	{
		stnEmail[i][pos]='\0';
	}
    }
    
   // Db_rddtb(KDS_NODE_ID,KEINE_ZEILE,KEINE_SPALTE,(RD_KDS_RETURN*)&kdsretNode);
    
    while(fgets ( line,128,fxml ) != NULL ) // read a line by line
    {
	
	tempstr=line; // this temp str contains the current line
	intLen = strlen(line);

	//---1-find----WorkSheet name ------------------------------
	wksFound= tempstr.find("Worksheet ss:Name");
	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
	        fFirst= tempstr.find("\"");
	        fLast=tempstr.find_last_of("\"");   
	        tempstr = tempstr.substr(fFirst+1,(fLast-(fFirst+1)));		

		if(tempstr == "Stations")
		{
	   	   blStations = true;
		}
    	}// end worksheet search 

	//---2 find the End of WorkSheet-------------
	wksFound= tempstr.find("</Worksheet>");
	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
		if(blStations)
		{
			blStations = false;
			break;
			//return true;
		}
	}
	
	blEndRecord = false;

	wksFound = tempstr.find("</Data>");
	findNameCell = tempstr.find("<NamedCell");
	findCell = tempstr.find("</Cell>");
	wksRowFound = tempstr.find("</Row>");
	fFiltDb = tempstr.find("FilterDatabase");
	//  CASE  A -- Check if the line is empty, has no data, only namedcell
	if((findNameCell > -1) && (wksFound == -1)  && (fFiltDb==-1) ) 
	{
		fLast = tempstr.find("</Cell>");
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		strData = "empty";
		blEndRecord = true;
	}
	// CASE B scenario we had Data and NameCell Filled in the Same Line 		
	else if( (wksFound > -1) && (findNameCell > -1)  && (findCell >-1) )
	{			
		fLast = tempstr.find("</Cell>");
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		fLast = wksFound;  //tempstr.find("</Data>");
		fFirst = tempstr.rfind("\">");
		strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));
		blEndRecord = true;
	}
	// CASE C -- Has Data and NameCell but the Cell END is in the next Line
	else if( (wksFound > -1) && (findNameCell > -1)  && (findCell == -1) )
	{
		fLast = wksFound;  //tempstr.find("</Data>");
		fFirst = tempstr.rfind("\">");
		strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));
		if(strData.length() == 0 )
				strData = "empty";
		blCellEnd = true; // wait the end of the Cell		
	}
	else if( (findCell > -1) &&  (blCellEnd)  ) // find the end of Cell
	{
		blCellEnd = false;
		fLast = tempstr.find("</Cell>"); 
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		blEndRecord = true;	
	}
	else if(wksRowFound > -1)	
	{
		blEndRecord = true;
		strData = "</Row>";
		strCell="";
	}

	// If the Record is OK
	if(blEndRecord)
	{
//-----------------------STATIONS------------------------------------------------------------------------------------------	    
	    if(blStations)
	    {
		
		
		//---- internal numbers 0 //		//if( (strCell=="internumber")  &&  (strData !="Internal number") && (strData !="empty") )
		if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[0].headerrecord)!= 0 )  )			
		{
			if (strData =="empty")
			{
				firstEmpty=true;
				blStations = false;
			}
			else
			{
				firstEmpty=false;
				strcpy(stnNumber[curRecord],strData.c_str());
				findFirst=true; 
			 }				 
			 		
		}
		//-- DID duwa numbers 1
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[1].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{
			if(findFirst)
			{

				if((strcmp(strData.c_str(),"empty") ==0) ||  (strcmp(strData.c_str(),"-") == 0)    )
					strcpy(stnDuwa[curRecord],"-");
				else	
					strcpy(stnDuwa[curRecord],strData.c_str());
					
				findSecond=true; 
			}
		}
		
		//---Display Numbers	2	
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[2].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					strcpy(stnDisplay[curRecord],"-");
				else			
				        strcpy(stnDisplay[curRecord],strData.c_str());		
				
				findThird=true;
			}
		}		
		
		//------Station Type   3 -----------------------------------
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[3].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				strcpy(stnStation[curRecord],strData.c_str());	
			
				findFourth=true;
			}
		}
		
		//--------FAX Callno---------------------------------
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[4].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				strcpy(stnFaxCallno[curRecord],strData.c_str());	
				findFifth=true;
			}
		}
		
		//--------FAX DID---------------------------------
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[5].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[5].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				strcpy(stnFaxDid[curRecord],strData.c_str());				
				findSixth=true;
			}
		}
		
		//--------FAX NAME---------------------------------
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[6].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[6].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					strcpy(stnFaxName[curRecord],"empty");
				else			
			        	strcpy(stnFaxName[curRecord],strData.c_str());				
			}
		}
		//--------Class of service-------------------------
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[7].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[7].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if((strcmp(strData.c_str(),"empty") ==0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					strcpy(stnCos[curRecord],"-1");	
				else 
				{
				      strcpy(stnCos[curRecord],strData.c_str());				
				      findSeventh=true;
				}
			}
		}
		//--------Call pickup---------------------------------
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[8].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[8].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if((strcmp(strData.c_str(),"empty") ==0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					strcpy(stnCos[curRecord],"-1");				
				else
				{
					strcpy(stnCallPick[curRecord],strData.c_str());				
					findEighth=true;
				}
			}
		}
		
		//------Access   9 -----------------------------------
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[9].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[9].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				
				tmpStrAccess = "";
				
				if((strcmp(strData.c_str(),"empty") ==0) ||  (strcmp(strData.c_str(),"-") == 0)  )
				{
					strcpy(stnAccessSlot[curRecord],"empty");
					strcpy(stnAccessPort[curRecord],"empty");
					strcpy(stnAccessLogId[curRecord],"empty"); 
				}
				else
				{
					string stra="";
					string strb="";
					string strc="";
					tmpStrAccess = strData.substr(0,strData.find(" "));
					
					stra = tmpStrAccess.substr(0,tmpStrAccess.find("-"));
					strb = tmpStrAccess.substr(tmpStrAccess.find("-")+1);
					//stra = strData.substr(0,strData.find("-"));
					//strb = strData.substr(strData.find("-")+ 1);
					tmpStrAccess = strData.substr(strData.find(" ")+1);

					strc = tmpStrAccess;
										
					strcpy( stnAccessSlot[curRecord] ,stra.c_str()); //strData.substr(0,strData.find("-").c_str(); // from Starto to the Position char '-'
					strcpy( stnAccessPort[curRecord] ,strb.c_str()); // strData.substr(strData.find("-")+ 1).c_str(); // from the position to the end
					strcpy( stnAccessLogId[curRecord] ,strc.c_str()); 
			
					findNingth=true;
				
				}
			}
		}
		
		//---Voicemail    10
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[10].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[10].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if((strcmp(strData.c_str(),"empty") ==0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					strcpy(stnVoicemail[curRecord],"-");	
				else
				        strcpy(stnVoicemail[curRecord],strData.c_str());	
			}
		}
		
		//---Email Address     11
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[11].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[11].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if((strcmp(strData.c_str(),"empty") ==0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					strcpy(stnEmail[curRecord],"");	
				else
				{        strcpy(stnEmail[curRecord],strData.c_str());	
					findTenth=true;			
				}
			}
		}
		//---Mobile number     12
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[12].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[12].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if((strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") == 0)  )
					strcpy(stnMobile[curRecord],"");	
				else
				{	
					strcpy(stnMobile[curRecord],strData.c_str());	
					findEleventh=true;
				}
			}
		}
		//---NODE ID 
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[13].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[13].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if ( (strcmp( strData.c_str(),"empty") ==0) || ( (strcmp(strData.c_str(),"-") == 0) ) )
				  strcpy(stnNode[curRecord],"0");
				else
				{ 
					strcpy(stnNode[curRecord],strData.c_str());
					findTwelveth=true; 		 
				}
			}
		}
		//---Secondary Gateway    14
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[14].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[14].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			
			if(findFirst)
			{
				if((strcmp(strData.c_str(),"empty") ==0) || ( (strcmp(strData.c_str(),"-") == 0) ) )
					strcpy(stnGw[curRecord],"");
				else
				{
					strcpy(stnGw[curRecord],strData.c_str());																		
					findThrirteenth=true; 
				}
			}
			
		}
		//------Else if End Row--- The Current Record Finished---------------------------
		else if( strcmp(strData.c_str(),"</Row>")  == 0  )
		{
			if( findFirst) // If has Call Number 
			{       
			
				if(!findSecond) // DID
				   strcpy(stnDuwa[curRecord],"-");
				if(!findThird)   
				   strcpy(stnDisplay[curRecord],"-");
				if(! findEleventh)   
				  strcpy(stnMobile[curRecord],"");	
				if(!findTwelveth)
				  strcpy(stnNode[curRecord],"0");
				//if(!findEighth)
				//  strcpy(stnGw[curRecord],"0");
				if(!findNingth)
				{
					strcpy(stnAccessSlot[curRecord],"empty");
					strcpy(stnAccessPort[curRecord],"empty");
					strcpy(stnAccessLogId[curRecord],"empty");
				}
				if(!findFifth)
				{
				    strcpy(stnFaxCallno[curRecord],"empty");
				}
				
				curRecord++; 				
			}
			
			findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNingth=false; findTenth=false; findEleventh=false;
			findTwelveth=false; findThrirteenth=false;     
		}
	


	      }//  END BLSTATION 
//-----------------------END STATIONS------------------------------------------------------------------------------------------	    

	      	
	} //end If blEndRecord
		

	countLine++;//increase countLines number to numberring Lines   
	
    }  // ----end while read lines-------
    
    fclose(fxml);
    int k=0;

    for (i = 0; i < TLN_NAME_SIZE; i++)
    {
       rdgrp1evm.inhalt[i] = 0;
    }
    
   // Db_wrdtb (KDS_EVM_MBX_NO,&rdgrp1evm.inhalt[0],0,(DB_SPALTE_T) KEINE_SPALTE, &wrreturn ); /*write NON default mailbox 1 in evm (index 0)*/
   // Db_wrdtb (KDS_EVM_MBX_NO,&rdgrp1evm.inhalt[0],1,(DB_SPALTE_T) KEINE_SPALTE, &wrreturn );/*write NON default mailbox 2 in evm (index 1)*/
  //  Db_rddtb(KDS_EVM_MBX_NO, 1,KEINE_SPALTE,&rdgrp2evm);
    /*for mailbox evm 2 index1  the Greeting must be greeting1 and the auto-attendant flag false deactivated*/
    //     0=greeting1 1=greeting2 ....
     
   //  Db_wrdtb(KDS_EVM_MBX_AA_FLAG,rdgrp1evm.inhalt, 1,KEINE_SPALTE,&wrreturn);
     rdgrp1evm.inhalt[0] = 0;
   //  Db_wrdtb(KDS_EVM_MBX_GREETING_INDEX,rdgrp1evm.inhalt, 1,KEINE_SPALTE,&wrreturn);
 //    Db_wrdtb(KDS_EVM_MBX_GREETING_CONTROL,rdgrp1evm.inhalt,1,KEINE_SPALTE,&wrreturn);

    /*  --------------- Initiate VSL data------------------------------------------- */
    cout  << "  ilias initiate Vsl Pointers.....numStations=" <<numStations<<endl;
    logPorts = new char*[numStations];
    sEmails = new char*[numStations];
    sMobiles = new char*[numStations];
    
    for(i=0; i<numStations; i++)
    {	 
		logPorts[i]= new char[tblSize];
		sEmails[i] =new char[MAX_EMAIL];
		sMobiles[i] = new char[tblSize];
    }
  
    for(i=0; i<numStations; i++)
    {	
	for(pos=0; pos<tblSize; pos++)
	{
		logPorts[i][pos]='\0';		
		sMobiles[i][pos]='\0';
	}
	for(pos=0; pos<MAX_EMAIL; pos++)
	{
		sEmails[i][pos]='\0';
	}
    }  
      
    cout  << "  ilias END initiate Vsl Pointers....." <<endl;  
       
	for(i=0;  i<numStations;  i++)
	{
		
	      curNodeAtoi = 0;    
  	     if(curNodeAtoi == 0 ) // Means The Same Node As the System  
  	     {
		icurNodeRecords++;  
//		printf("\n  (stnNumber[%d]=%s)-(stnDuwa[%d]=%s )-(stnDisplay[%d]=%s)-(stnStation[%d]=%s)-(stnEmail[%d]=%s) ",i,stnNumber[i],i,stnDuwa[i],i,stnDisplay[i], i, stnStation[i],i,stnEmail[i]);
		
//----------------SIP--------------------------------------------------STN_WP_SIP=7 ,  STNTYP_WP_SIP          5 ------------------------
		


//----------------IP--------------------------------------------------------------STN_WP_SYS=5  ,  STNTYP_WP_SYS          1------------------
		if( !strcmp(stnStation[i],xmlStationTypes[3].name) )
		{
			
			startIndexIp=stIpCounter;

				
			/*if(has_mail || has_mobile)
			storevsldata(ipindex,stnemail,stnmobile,stnrufnr,stnname);
			*/				
			if(  (strcmp(stnEmail[i],"") !=0 ) ||  (strcmp(stnMobile[i],"")!=0) )
			{			      
			      
			      //storevsldata(stIpCounter,stnEmail[i],stnMobile[i],stnNumber[i],stnDisplay[i]);
			      cout << "  ilias  IP  iVslCounter="<<iVslCounter<< "   ,stIpCounter="<<stIpCounter<<", stnEmail[i]="<<stnEmail[i]<< ", stnMobile[i]="<<stnMobile[i]<<endl;
			      sprintf(logPorts[iVslCounter], "%d", stIpCounter);
			      cout << " ilias pass 1" <<endl;
			      strcpy(sEmails[iVslCounter],stnEmail[i]);
			      cout << " ilias pass 2" <<endl;
			      strcpy(sMobiles[iVslCounter],stnMobile[i]);
			      cout << " ilias pass 3" <<endl;
			      iVslCounter++;
			} 		
			
			
			//  Write Fax 
			
			
			
			stIpCounter++;
			
			

			

		}

//----------------------------------------------------------------------------------------------------------------------

//----------------RAS-LIC--------------------------------------------------------------------------------------------
				
		
				
//----------------------------------------------------------------------------------------------------------------------
		
		// stRasAdminCounter=0, stRasLicCounter=0;
		
	    } // END IF IS THE CURRENT NODE 				
	}
	
	
	//-----Call function in order to update the database 
	cout << "  ilias call StoreVslAllData" <<endl;
	for(int i=0;  i<iVslCounter; i++)
	{
	  //storevsldata(atoi(logPorts[i]),sEmails[i],sMobiles[i],"0","0");
	}
	cout << "  ilias finish call  StoreVslAllData" <<endl;
	//-------------------------------------------------
	
	

    	for(i=0;i<numStations;i++)
   	{

		delete []stnNumber[i];
		delete []stnDuwa[i];
		delete []stnDisplay[i];
		delete []stnStation[i];
		delete []stnEmail[i];
		delete []stnMobile[i];
		delete []stnNode[i];
		delete []stnGw[i];
		delete []stnAccessSlot[i];
		delete []stnAccessPort[i];
		delete []stnAccessLogId[i];
		delete []stnVoicemail[i];
		delete []stnFaxCallno[i];
		delete []stnFaxDid[i];
		delete []stnCos[i];
		delete []stnCallPick[i];
		delete []stnFaxName[i];
		delete []logPorts[i];
		delete []sEmails[i];
		delete []sMobiles[i];
	}
   
	delete []stnNumber;
	delete []stnDuwa;
	delete []stnDisplay;
	delete []stnStation;
	delete []stnEmail;
	delete []stnMobile;
	delete []stnNode;
	delete []stnGw;	   
	delete []stnAccessSlot; 
	delete []stnAccessPort; 
	delete []stnAccessLogId; 
	delete []stnVoicemail;
	delete []stnFaxCallno;
	delete []stnFaxDid;
	delete []stnCos;
	delete []stnCallPick;
	delete []stnFaxName;
	delete []logPorts;
	delete []sEmails;
	delete []sMobiles;

	
	voicemailCounter = evmCounter;
	
	if ( icurNodeRecords == 0 ) 
		return false;
	else
		return true; 
}  

//----------------loloca

/* The Function Find the Numbers of Record Per Worksheet, then will Fill the Table Type with corresponding data
  Type    	search string     returns Number Of Entries
    [0]		"Stations"     
    [1]		"Licenses"
    [2]		"Groups"
    [3]		"Virtual"
    [4]		"Trunk Groups"
    [5]		"Voicemail"      
*/    

int WorkSheetRecords(char* fname, int type[7], int errorCount, int faults[21][3])
{
    char line [128]; 
    char *tmpNumbers;
    FILE *fxml = fopen(fname,"r");
    int fLast,fFirst,intLen,wksFound,findNameCell=0,findCell=0,countLine=0,rowCount=0,result=-1,wksRowFound,corXml=0,klen=0,fFiltDb=0,uc_count=0;
    string tempstr,totalstr,strData,strCell;  
    bool blStations=false,blLicenses=false,blGroups=false,blVirtual=false,blTrunkGroup=false,blVoicemail=false,blCellEnd=false,blEndRecord=false,blX1=false,blSipConfig=false;
    int i=0,pos=0,numStations=0,numLicenses=0,numGroups=0,numVoicemail=0,numVirtual=0,numTrunkGroups=0,numberoflines=1,faultrow=1,record=0,block=0,numSipConfig=0;	
    bool firstEmpty=false,secondEmpty=false,thirdEmpty=false,fourthEmpty=false,fifthEmpty=false,sixthEmpty=false,seventhEmpty=false,eighthEmpty=false,ninthEmpty=false,tenthEmpty=false,eleventhEmpty=false
    ,twelvthEmpty=false,therteenthEmpty=false;
    bool findFirst=false,findSecond=false,findThird=false,findFourth=false,findFifth=false,findSixth=false,findSeventh=false,findEighth=false,findNinth=false,findTenth=false,findEleventh=false,findTwelvth=false,findTherteenth=false;
//    unsigned char chEmpty;
    RD_KDS_RETURN			kdsreturn,kdsreturnacode;
    RD_KDS_RETURN           kdsreturnX1;
    char * sacode;
    int   inhalt[256];
    
    
    
    
    // uc_count= Db_rddtb((enum KDS_TABLE) KDS_VPLRN_DDI, (DB_ZEILE_T)0, (DB_SPALTE_T)KEINE_SPALTE, &kdsreturnacode );
    // FPUti::bcd_to_a ( &kdsreturnacode.inhalt[0], inhalt, (WORD)uc_count );   
     
    
    
    
   // Db_rddtb(KDS_AUSBAU_VAR,KDS_ANLAGEN_AUSBAU,KEINE_SPALTE,(RD_KDS_RETURN*)&kdsreturnX1);   // takes System type 

   // if(kdsreturnX1.inhalt[0]==DS_BPL_ONE_X1)  //DS_BPL_ONE
  	blX1=false; // means system is X1
	
    errorCount = 0;
        
    for(i=0;i<21;i++)
    {
	for(pos=0;pos<3;pos++)
		faults[i][pos]=0;
    }

// -- Prepei na mpoun edo kai Safe Conditions an Skasei        
    while ( fgets ( line,128,fxml ) != NULL ) // read a line by line
    {
	
	if (faultrow > 20)
		break;
	
	tempstr=line; // this temp str contains the current line
	intLen = strlen(line);

	
	//---1-find----WorkSheet name ------------------------------
	wksFound= tempstr.find("Worksheet ss:Name");

	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
	        fFirst= tempstr.find("\"");
	        fLast=tempstr.find_last_of("\"");   
	        tempstr = tempstr.substr(fFirst+1,(fLast-(fFirst+1)));		

		if(tempstr == "Stations")
		{
	   	   blStations = true;
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name   
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;
		   countLine=0;
		   corXml++;
		}
		else if(tempstr =="Licenses")
		{
		   blLicenses = true; 	
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;
		   countLine=0;
		   corXml++;		   
		}
		else if(tempstr =="Groups")		
		{
		   blGroups = true;		    
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 		
		   countLine=0;		
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;
		   corXml++;		   
		}
		else if(tempstr =="Virtual")		
		{
		   blVirtual = true;
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 		
		   countLine=0;		
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;
		   corXml++;		   
		   
		}
		else if(tempstr =="Trunk Groups")
		{
		   blTrunkGroup = true;		
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 		   
		   countLine=0;		
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;
		   corXml++;		   

		}
		else if(tempstr =="Voicemail")	
		{
		   blVoicemail = true;		   
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 		   
		   countLine=0;		
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;
		   corXml++;
		}
		else if(tempstr =="SipConfig")	
		{
		   blSipConfig = true;		   
		   block=0;          
		   record=0;        
		   countLine=0;		
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;
		   corXml++;
		}

    	}// end worksheet search 

	//---2 find the End of WorkSheet-------------
	wksFound= tempstr.find("</Worksheet>");
	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
		if(blStations)
		{
			blStations = false;
		}
		else if(blLicenses)
		{
			blLicenses = false;
		}
		else if(blGroups)
		{
			blGroups = false;
		}
		else if(blVirtual)
		{
			blVirtual = false;
		}
		else if(blTrunkGroup)
		{
			blTrunkGroup = false;
		}
		else if(blVoicemail)
		{
			blVoicemail = false;
			
		}
		else if(blSipConfig)
		{
			blSipConfig = false;
			break;	
		}

	}


	blEndRecord = false;
	//if(blStations)
	//{
	
		wksFound = tempstr.find("</Data>");
		findNameCell = tempstr.find("<NamedCell");
		findCell = tempstr.find("</Cell>");
		wksRowFound = tempstr.find("</Row>");
		fFiltDb = tempstr.find("FilterDatabase");
		//  CASE  A -- Check if the line is empty, has no data, only namedcell
		if((findNameCell > -1) && (wksFound == -1)  && (fFiltDb==-1) ) 
		{
			fLast = tempstr.find("</Cell>");
			fLast = fLast -3;
			fFirst = tempstr.rfind("=\"");
			fFirst  = fFirst+2;
			strCell = tempstr.substr(fFirst,(fLast-fFirst));
			strData = "empty";
			blEndRecord = true;
		}
		// CASE B scenario we had Data and NameCell Filled in the Same Line 		
		else if( (wksFound > -1) && (findNameCell > -1)  && (findCell >-1) )
		{			
			//cell name
			fLast = tempstr.find("</Cell>");
			fLast = fLast -3;
			fFirst = tempstr.rfind("=\"");
			fFirst  = fFirst+2;
			strCell = tempstr.substr(fFirst,(fLast-fFirst));
			//data 
			fLast = wksFound;  //tempstr.find("</Data>");
			fFirst = tempstr.rfind("\">");
			strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));
			blEndRecord = true;	
		}
		// CASE C -- Has Data and NameCell but the Cell END is in the next Line
		else if( (wksFound > -1) && (findNameCell > -1)  && (findCell == -1) )
		{
			//data
			fLast = wksFound;  //tempstr.find("</Data>");
			fFirst = tempstr.rfind("\">");
			
			strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));

			if(strData.length() == 0 )
				strData = "empty";
			blCellEnd = true; // wait the end of the Cell	
		}
		else if( (findCell > -1) &&  (blCellEnd)  ) // find the end of Cell
		{
			blCellEnd = false;
			//cell name
			fLast = tempstr.find("</Cell>");
			fLast = fLast -3;
			fFirst = tempstr.rfind("=\"");
			fFirst  = fFirst+2;
			strCell = tempstr.substr(fFirst,(fLast-fFirst));
			blEndRecord = true;
		}
		else if(wksRowFound > -1)	
		{
			blEndRecord = true;
			strData = "</Row>";
			strCell="";
		}

		//  When Find a Record the blEndRecord is TRUE 
		if((blEndRecord)  &&  (faultrow <21) )
		{
			
//----------------Start ----  Validation -- Check If the Header of Each  Sheet Is Correct ----------------------------------------------			
			if(blStations) 
			{
				
				
				if(record >14)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
				}
				
				if(block == 0) // CHeck if The Header Column Is COrrect 
				{
					
					if( (strcmp(strCell.c_str(),xmlStationsNameTable[record].namedcell) != 0 ) || 
					(strcmp(strData.c_str(), xmlStationsNameTable[record].headerrecord) != 0) )
					{
					    
						    faults[0][0]++;
						    faults[faultrow][0]=1;
						    faults[faultrow][1]= numStations+2; //countLine+2;
						    faults[faultrow][2]=INVALID_FILE_FORMAT;
						    faultrow++;				     
					}
					
					record++;
				}

			  }
			  if(blLicenses) 
			  {
			
				if(record >12)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
				}
				
				if(block == 0) // CHeck if The Header Column Is COrrect 
				{
					if( (strcmp(strCell.c_str(),xmlLicensesNameTable[record].namedcell) != 0 ) || 
					(strcmp(strData.c_str(), xmlLicensesNameTable[record].headerrecord) != 0) )
					{
					   
						    faults[0][0]++;
						    faults[faultrow][0]=2;	
						    faults[faultrow][1]=numLicenses+2;// countLine+2;
						    faults[faultrow][2]=INVALID_FILE_FORMAT;
						    faultrow++;
					}					
					record++;
				}
				
			   }
			  if(blGroups) 
			  {
				if(record >4)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
				}
				
				if(block == 0) // CHeck if The Header Column Is COrrect 
				{
					if( (strcmp(strCell.c_str(),xmlGroupsNameTable[record].namedcell) != 0 ) || 
					(strcmp(strData.c_str(), xmlGroupsNameTable[record].headerrecord) != 0) )
					{
					   
						    faults[0][0]++;
						    faults[faultrow][0]=3;
						    faults[faultrow][1]=numGroups+2; //countLine+2; 	
						    faults[faultrow][2]=INVALID_FILE_FORMAT;
						    faultrow++;
					}
					
					record++;					
				}
				
			   }
			  
			  if(blVirtual) 
			  {
				if(record >4)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
				}
				
				if(block == 0) // CHeck if The Header Column Is COrrect 
				{
					if( (strcmp(strCell.c_str(),xmlVirtualNameTable[record].namedcell) != 0 ) || 
					(strcmp(strData.c_str(), xmlVirtualNameTable[record].headerrecord) != 0) )
					{						    
						    faults[0][0]++;
						    faults[faultrow][0]=4;
						    faults[faultrow][1]=numVirtual+2; //countLine+2; 	
						    faults[faultrow][2]=INVALID_FILE_FORMAT;
						    faultrow++;
					}
					
					record++;
				}
				
			   }
			   
			  if(blTrunkGroup) 
			  {
				if(record >2)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
				}
				if(block == 0) // CHeck if The Header Column Is COrrect 
				{
					if( (strcmp(strCell.c_str(),xmlTrunkGrpNameTable[record].namedcell) != 0 ) || 
					(strcmp(strData.c_str(), xmlTrunkGrpNameTable[record].headerrecord) != 0) )
					{
						    faults[0][0]++;
						    faults[faultrow][0]=5;
						    faults[faultrow][1]=numTrunkGroups+2; //countLine+2; 	
						    faults[faultrow][2]=INVALID_FILE_FORMAT;
						    faultrow++;
					}
				
					record++;
				}
				
				
			   }
			   
			  if(blVoicemail) 
			  {
				if(record >2)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
				}
				if(block == 0) // CHeck if The Header Column Is COrrect 
				{
					if( (strcmp(strCell.c_str(),xmlVoiceMailNameTable[record].namedcell) != 0 ) || 
					(strcmp(strData.c_str(), xmlVoiceMailNameTable[record].headerrecord) != 0) )
					{
					    
					            faults[0][0]++;
						    faults[faultrow][0]=6;
						    faults[faultrow][1]=numVoicemail+2; //countLine+2; 	
						    faults[faultrow][2]=INVALID_FILE_FORMAT;
						    faultrow++;
					}
					record++;
				}
				
			   }
			   if(blSipConfig)
			   {
				if(record >4)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
				}
				if(block == 0) // CHeck if The Header Column Is COrrect 
				{
					if( (strcmp(strCell.c_str(),xmlSipConfigTable[record].namedcell) != 0 ) || 
					(strcmp(strData.c_str(), xmlSipConfigTable[record].headerrecord) != 0) )
					{
					    
					            faults[0][0]++;
						    faults[faultrow][0]=7;
						    faults[faultrow][1]=numSipConfig+2; //countLine+2; 	
						    faults[faultrow][2]=INVALID_FILE_FORMAT;
						    faultrow++;
					}
					record++;
				}
				
			   }
			   
			  					
//----------------END ----  Validation -- Check If the Header of Each  Sheet Is Correct ----------------------------------------------						
			
//----------------------------------------------STATIONS--------------------------------------------------------------------------------------------------------------
			if( (blStations)  &&  (block > 0) )
			{
				
				//---------------------------INTERNAL NUMBER------------------------------------------------------

				if( ( strcmp(strCell.c_str(),xmlStationsNameTable[0].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[0].headerrecord) != 0 )
				  )
				{														
					// numStations++;					
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if Internal Number Is Emprty 
					{					   
					    firstEmpty = true;					    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true;
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());
					    if(!checkvalidCallDuwa(tmpNumbers))
					    {				       
					       faults[0][0]++;
					       faults[faultrow][0]=1;
   					       faults[faultrow][1]=numStations+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
					    				    
					    }
					    else if(strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					       faults[0][0]++;
					       faults[faultrow][0]=1;
   					       faults[faultrow][1]=numStations+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
			    
					    }
					    else
					    {
					    //----------call old Checks --------------------------------------
					    
					     }
					    //----------call old Checks --------------------------------------					    
					    delete[] tmpNumbers;
				         }
 				    numberoflines++;				    
				}
				//-----------------------END----INTERNAL NUMBER------------------------------------------------------
				
				
				//----------------------------DID NUMBER --------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[1].headerrecord)!= 0
				 ) )
				{
										
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     secondEmpty = true;
					}
					else
					{
						findSecond=true; 
						
						tmpNumbers = new char[strData.length()+1];  
						strcpy(tmpNumbers,strData.c_str());
						
						 //Check if Valid Number  Duwa or Is Empty Then Error
						if( (!checkvalidCallDuwa(tmpNumbers) )  ||  (strcmp(strData.c_str(),"empty") == 0) ) 
						{
					     	        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_DUWA;
					                faultrow++;
						    
						}
						else if(strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    	{						       
						        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_DUWA;
					                faultrow++;
			    
					    	}
						else
						{
						    	
						}
						    delete[] tmpNumbers;
					}
					
					

				}
				//-----------------------END-----DID NUMBER -----------------------------------------------------------
				
				
				//----------------------------DISPLAY NAME ------------------------------------------------------
				//else if( (strCell=="displayname")  &&  (strData !="Display name") && (strData !="empty") )
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[2].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}

					else 
					{
						findThird=true; 
						klen=0;
						klen= my_strlen_utf8_c(strData.c_str());
						
						if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
							faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=INVALID_NAME_CHARACTERS;
						        faultrow++;	
						}
						else if( (strData.length() > (TLN_NAME_SIZE))     &&   (klen>TLN_NAME_SIZE ) )
						{
						    	faults[0][0]++;
							faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=INVALID_NAME;
						        faultrow++;	
						}
					}
					
					
				}
				//--------------------------END --DISPLAY NAME ------------------------------------------------------
				
				//----------------------------STATION TYPE ------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(),xmlStationsNameTable[3].headerrecord)!=0) )
				{
					if ( strcmp(strData.c_str(),"empty") == 0 )
					{	
					     fourthEmpty = true;
					}					
					else 
					{
						findFourth=true; 
						if( !CheckStationType(strData.c_str()) ) // ||  (strcmp(strData.c_str(),"empty") == 0) )
						{					    
							faults[0][0]++;
							faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=STN_TYP_UNKNOWN;
						        faultrow++;	
						}
						
					}
					
					
				}
				//--------------------------END --STATION TYPE ------------------------------------------------------

				// --------------------------FAX Call no -------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[4].headerrecord)!= 0
				 ) )
				{
				
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if Internal Number Is Emprty 
					{					   
					    fifthEmpty = true;					    
					}
					else // Check If Valid Call Number 
					{
					    findFifth=true;
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());
					    if(!checkvalidCallDuwa(tmpNumbers))
					    {				       
					       faults[0][0]++;
					       faults[faultrow][0]=1;
   					       faults[faultrow][1]=numStations+3;
					       faults[faultrow][2]=INVALID_FAXCALLNO;
					       faultrow++;
					    				    
					    }
					    else if(strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					       faults[0][0]++;
					       faults[faultrow][0]=1;
   					       faults[faultrow][1]=numStations+3;
					       faults[faultrow][2]=INVALID_FAXCALLNO;
					       faultrow++;
			    
					    }
					    else
					    {
					    //----------call old Checks --------------------------------------

					     }
					    //----------call old Checks --------------------------------------					    
					    delete[] tmpNumbers;
				         }
				
				}				
				
				//---------------------------FAX DID -----------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[5].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[5].headerrecord)!= 0
				 ) )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     sixthEmpty = true;
					}
					else
					{
						findSixth  = true;
						tmpNumbers = new char[strData.length()+1];  
						strcpy(tmpNumbers,strData.c_str());
						
						 //Check if Valid Number  Duwa or Is Empty Then Error
						if( (!checkvalidCallDuwa(tmpNumbers) )  ||  (strcmp(strData.c_str(),"empty") == 0) ) 
						{
					     	        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_FAXDID;
					                faultrow++;
						    
						}
						else if(strData.length() > ((RUFNR_SIZE*2) -2 ))
					    	{						       
						        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_FAXDID;
					                faultrow++;
			    
					    	}
						        							
						else
						{
						    	
						
						}
						    delete[] tmpNumbers;
					}										
				}
				
				//----------------------------FAX NAME ------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[6].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[6].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     //thirdEmpty = true;
					     therteenthEmpty = true;
					}

					else 
					{
						//findThird=true; 
						findTherteenth=true;
						klen=0;
						klen= my_strlen_utf8_c(strData.c_str());
						if( (strData.length() > (TLN_NAME_SIZE))     &&   (klen>TLN_NAME_SIZE ) )
						{
						    	faults[0][0]++;
							faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=INVALID_FAX_NAME;
						        faultrow++;	
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
							faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=INVALID_FAX_NAME;
						        faultrow++;	
						}
												
					}
					
					
				}

				//---------------------------Class of service  ------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[7].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[7].headerrecord)!= 0
				 ) )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     seventhEmpty = true;
					}
					else
					{
						findSeventh  = true;
						tmpNumbers = new char[strData.length()+1];  
						strcpy(tmpNumbers,strData.c_str());
						
						 //Check if Valid Number  Duwa or Is Empty Then Error
						if( (!checkvalidCallDuwa(tmpNumbers) )  ) 
						{
					     	        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_COS;
					                faultrow++;
						    
						}
						else if(strData.length() > ((DID_SIZE*2) -1))
					    	{						       
						        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_COS;
					                faultrow++;
			    
					    	}
						else if((atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 15 ))
					    	{						       
						        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_COS;
					                faultrow++;
			    
					    	}
						
						
					        delete[] tmpNumbers;
					}				
				
				}				
				
				//---------------------------Call pickup ------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[8].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[8].headerrecord)!= 0
				 ) )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     eighthEmpty = true;
					}
					else
					{
						findEighth  = true;
						tmpNumbers = new char[strData.length()+1];  
						strcpy(tmpNumbers,strData.c_str());
						
						 //Check if Valid Number  Duwa or Is Empty Then Error
						if( (!checkvalidCallDuwa(tmpNumbers) )  ) 
						{
					     	        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_CALLPICKUP;
					                faultrow++;
						    
						}
						else if(strData.length() > ((DID_SIZE*2) -1))
					    	{						       
						        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_CALLPICKUP;
					                faultrow++;
			    
					    	}
						else if((atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 32 ))
					    	{						       
						        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_CALLPICKUP;
					                faultrow++;
			    
					    	}
						
						
					        delete[] tmpNumbers;
					}	
				
				}				


				
				//---------------------------ACCESS ------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[9].namedcell) ==0 )  &&  ( strcmp(strData.c_str(),xmlStationsNameTable[9].headerrecord)!=0) )
				{
					if ( strcmp(strData.c_str(),"empty") == 0 )
					{	
					     //fourthEmpty = fourthEmpty;   // true;
					}					
					
					else 
					{ 	// If the "Access" column is not empty and does not contain the char '-' to seperate the two master/slave then error message
						i = strData.find("-");
						if( (i == -1)  || (strData.length() <3)  || ( (strData.length() - i) < 1 )  || (i==0) )
						{
							faults[0][0]++;
							faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=WRONG_ACEESS_FORMAT;
						        faultrow++;	
						}
				
						tmpNumbers = new char[strData.length()+1];  
						strcpy(tmpNumbers,strData.substr(0,strData.find(" ")).c_str());
						//strcpy(tmpNumbers,strData.c_str());
						if(checkvalidAccess(tmpNumbers) == false)
						{						
							faults[0][0]++;
							faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=WRONG_ACEESS_FORMAT;
						        faultrow++;	
						}
						else if (( strcmp("Master",strData.substr(strData.find(" ")+1).c_str() )  !=0   )   &&	( strcmp("Slave",strData.substr(strData.find(" ")+1).c_str() )  !=0   ) )
						{
							faults[0][0]++;
							faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=WRONG_ACEESS_FORMAT;
						        faultrow++;							
						}
						
					
					}
					
					
					
				}
				//--------------------------END --ACCESS ------------------------------------------------------

				//----------------------------Voicemail ------------------------------------------------------				
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[10].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[10].headerrecord)!= 0
				 )  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)   )
					{	
					     ninthEmpty = true;
					}
					
					else
					{
						if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))							     
						{	
						    faults[0][0]++;
		      				    faults[faultrow][0]=1;
	   					    faults[faultrow][1]=numStations+3;
					            faults[faultrow][2]=WRONG_VOICEMAIL_FORMAT;
					            faultrow++;

						}
					}
					
					
				}
				//--------------------------END --Voicemail ------------------------------------------------------
				
																
				//----------------------------EMAIL ------------------------------------------------------				
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[11].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[11].headerrecord)!= 0
				 )  )
				{
					
					
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)   )
					{	
					     tenthEmpty = true;
					}
					
					else
					{
						
						findTenth=true;	
						
						tmpNumbers = new char[strData.length()+1];  
						strcpy(tmpNumbers,strData.c_str());

						if( !checkvalidmail(tmpNumbers) )
						{	
						    faults[0][0]++;
		      				    faults[faultrow][0]=1;
	   					    faults[faultrow][1]=numStations+3;
					            faults[faultrow][2]=INVALID_EMAIL;
					            faultrow++;

						}
						else if(strData.length() >  MAX_EMAIL )
						{
						    faults[0][0]++;
		      				    faults[faultrow][0]=1;
	   					    faults[faultrow][1]=numStations+3;
					            faults[faultrow][2]=INVALID_EMAIL;
					            faultrow++;		
						}						
						delete [] tmpNumbers;
					}
					
					
				}
				//--------------------------END --EMAIL ------------------------------------------------------

				//----------------------------MOBILE  ------------------------------------------------------				
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[12].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[12].headerrecord)!= 0
				 ) )
				 //) && (strData !="empty") )

				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     eleventhEmpty = true;
					}
					else
					{
						findEleventh=true; 
						

						tmpNumbers = new char[strData.length()+1];  
						strcpy(tmpNumbers,strData.c_str());

						if( !checkvalidnumber(tmpNumbers) )
						{					    							    
						    faults[0][0]++;
		      				    faults[faultrow][0]=1;
	   					    faults[faultrow][1]=numStations+3;
					            faults[faultrow][2]=INVALID_MOBILE;
					            faultrow++;	
						}
						else if(strData.length() > MAX_MOBILE)
						{
						    faults[0][0]++;
		      				    faults[faultrow][0]=1;
	   					    faults[faultrow][1]=numStations+3;
					            faults[faultrow][2]=INVALID_MOBILE;
					            faultrow++;	
				
						}
						delete [] tmpNumbers;
					}
					
					
				}
				//--------------------------END --MOBILE  ------------------------------------------------------

				//----------------------------NODE  ------------------------------------------------------				
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[13].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[13].headerrecord)!= 0
				 ) )
				{										
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					      twelvthEmpty = true; //seventhEmpty = true;
					}
					else
					{
						findTwelvth=true; 
						if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{
							faults[0][0]++;
			      				faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=INVALID_NODEID;
						        faultrow++;
						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						        faults[0][0]++;
			      				faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=INVALID_NODEID;
						        faultrow++;
						}
						else if( strData.length() > 4 )
						{
						   	faults[0][0]++;
			      				faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=INVALID_NODEID;
						        faultrow++;
						}
					}
					
					
				}
				//--------------------------END --NODE   ------------------------------------------------------
				
				//---------------------------- SECONDARY GATEWAY  ------------------------------------------------------				
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[14].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[14].headerrecord)!= 0 ) )
				{
					
					
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)   )
					{	
					     //therteenthEmpty = true;
					}					
					else 
					{
					    //findTherteenth=true;
					    
					    if ( (atoi(strData.c_str()) == 0)  && ( (strData !="0") && (strData!="empty"))  )
					    { 
						faults[0][0]++;
			      			faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_SECGW;
						faultrow++;
					    }
				            else  if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
					    {
						faults[0][0]++;
			      			faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_SECGW;//INVALID_SECGW
						faultrow++;
					    }
					    else if( strData.length() > 4 )
 					    {
						faults[0][0]++;
			      			faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_SECGW;//INVALID_SECGW
						faultrow++;
					    }
					}

				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					/*		
					if(!findFirst)
						numStations++;
					*/

					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) && (fourthEmpty) && (fifthEmpty) && (sixthEmpty) && (seventhEmpty) && (eighthEmpty)&& (ninthEmpty)&&(tenthEmpty) &&(eleventhEmpty) &&
					(twelvthEmpty)   &&  (therteenthEmpty) )
					{
					    blStations = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
					    fourthEmpty=false;
					    fifthEmpty=false;
					    sixthEmpty=false;
					    seventhEmpty=false;
					    eighthEmpty=false;	
					    ninthEmpty=false;	
					    tenthEmpty=false;	
					    eleventhEmpty=false;	
					    twelvthEmpty=false;	
					    therteenthEmpty=false;	 					    					    
					    block =0;
					    record = 0;					    
				    }
										
					if( (findFirst) && (findSecond) && (findThird)  && (findFourth) && (findFifth) && (findSixth) && (findSeventh) && (findEighth) && (findNinth)&&(findTenth) &&(findEleventh) &&
					(findTwelvth)   &&  (findTherteenth) )
					{
						findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false;
						findEleventh=false; findTwelvth=false; findTherteenth=false;
					} 
					else if( (findFirst)  && (!findFourth) )
					{
						faults[0][0]++;
						faults[faultrow][0]=1;
	   					faults[faultrow][1]=numStations+2;
					        faults[faultrow][2]=STN_TYP_UNKNOWN;
					        faultrow++;	
					}
					else if( (!findFirst) &&  ((findSecond) || (findThird)  || (findFourth) || (findFifth) || (findSixth) || (findSeventh) || (findEighth) || (findNinth) || (findTenth) || (findEleventh) ||
					(findTwelvth) ||(findTherteenth)) )
					{					    
					    
					    faults[0][0]++;
			      		    faults[faultrow][0]=1;
		   			    faults[faultrow][1]=numStations+3;
					    faults[faultrow][2]=CALL_NO_MISSING;
					    faultrow++;
					}
					
					if( ((findSixth)    &&   (!findFifth))  ||    ((findTherteenth)    &&   (!findFifth))  )
					{
						faults[0][0]++;
						faults[faultrow][0]=1;
	   				        faults[faultrow][1]=numStations+3;
					        faults[faultrow][2]=MISSING_FAX_CALLNO;
					        faultrow++;
					}

					
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) && (!findFifth) && (!findSixth)  && (!findSeventh) && (!findEighth) && (!findNinth)&&(!findTenth) &&(!findEleventh) &&
					(!findTwelvth)   &&  (!findTherteenth) )
					{
					    //blStations = false;
					    numStations = numStations;
					}
					else
						numStations++;
					
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;findTherteenth=false;				
					firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;twelvthEmpty=false;therteenthEmpty=false;									
				}

			} // END if(blStations)
//---------------------------------------------- END STATIONS--------------------------------------------------------------------------------------------------------------			

                         




			
//----------------------------------------------- LICENSES START----------------------------------------------------------------------------------------------------------			
			else if((blLicenses)  && (block >0))
			{								
				//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[0].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[0].headerrecord) != 0 ))
				{
					
					//numLicenses++;
					
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if LIC Internal Number Is Emprty 
					{										   
					     firstEmpty = true;
					    
					}
					else // Check If Valid Call Number 
					{
					    
					    findFirst=true; 
					   
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());
					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]=LIC_TYPE_NOT_SUPPORTED;
					       faultrow++;				    
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]=LIC_TYPE_NOT_SUPPORTED;
					       faultrow++;				    
					    }

					    delete [] tmpNumbers;
					}     

				        numberoflines++;
										
					
				}
				//--------------------------------USER TYPE------------------------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[1].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[1].headerrecord) != 0 ))
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					    if(findFirst)
					    {
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]=LIC_TYP_USTYP;
					       faultrow++;	
					    }
					    
					}
					else
					{ 	     					    
							findSecond=true; 					    					    
					    	if( !CheckLicenseUserType(strData.c_str()) )
					    	{						    					    
						    faults[0][0]++;
	  			      	    	    faults[faultrow][0]=2;
			   			    faults[faultrow][1]=numLicenses+3;
						    faults[faultrow][2]=LIC_TYP_USTYP;
					    	    faultrow++;
						    }					    					
					}												
				}

				//------------------------------VOICEMAIL -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[2].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[2].headerrecord) != 0 ))
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if LIC Internal Number Is Emprty 
					{										   
					     secondEmpty = true;					    
					}
					else
					{ 	
					     findThird=true; 
					     
					     if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))							     
					     {
				       
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]=LIC_TYP_VCMAIL;
					       faultrow++;				    
					     }
					
					}	
								
				}
				//------------------------------GROUP WARE USER-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[3].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[3].headerrecord) != 0 ))
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     thirdEmpty = true;	
					}			
					else
					{ 	
					     findFourth=true; 
					     
					     if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					     {										
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]=LIC_TYP_GRWAREUS;
					       faultrow++;				    
					     }
					
					}					
				}
				//------------------------------UC USER-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[4].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[4].headerrecord) != 0 ))
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     fourthEmpty = true;
					    
					}
					else
					{ 	
					     findFifth=true; 
					     if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					     {
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]= LIC_TYP_UCUSER;
					       faultrow++;				    
					     }
					
					}
									
									
				}
				//------------------------------UCE FAX-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[5].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[5].headerrecord) != 0 ))
				{
					if ( strcmp(strData.c_str(),"empty") == 0 )
					{										   
					     fifthEmpty = true;
					    
					}
					else
					{ 	
					     findSixth=true; 
					     
					     if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					     {
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]= LIC_TYP_UCFAX;
					       faultrow++;				    
					     }
					
					}
									
									
				}
				//------------------------------UC CONFERENCE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[6].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[6].headerrecord) != 0 ))
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     sixthEmpty = true;
					}
					else
					{ 	
					     findSeventh=true; 
					     if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					     {
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]= LIC_TYP_UCCONF;
					       faultrow++;				    
					     }
					
					}									
				}
				//------------------------------MY ATTENDAND-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[7].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[7].headerrecord) != 0 ))
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if LIC Internal Number Is Emprty 
					{										   
					     seventhEmpty = true;
					}
					else
					{ 	
					    findEighth=true;
					    
					     if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					     {
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]= LIC_TYP_MYATTEND ;
					       faultrow++;				    
					     }
					
					}
																		
				}
				//------------------------------MY AGENT-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[8].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[8].headerrecord) != 0 ))
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if LIC Internal Number Is Emprty 
					{										   
					     eighthEmpty = true;
					}
					else
					{ 	
					     findNinth=true;
					     
					     if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					     {
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]=LIC_TYP_MYAGENT ;
					       faultrow++;				    
					     }
					
					}				
					 				
				}
				/*/------------------------------SOCIAL MEDIA -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[9].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[9].headerrecord) != 0 ))
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if LIC Internal Number Is Emprty 
					{										   
					     ninthEmpty = true;
					}
					else
					{ 	
					     findTenth=true;	
					     if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					     {
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]= LIC_TYP_SOCMEDIA ;
					       faultrow++;				    
					     }
					
					}				
					 				
				}
				*/
				//------------------------------APPLICATION LAUNCHER-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[9].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[9].headerrecord) != 0 ))
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if LIC Internal Number Is Emprty 
					{										   
					     ninthEmpty = true;
					}
					else
					{ 	
					     findEleventh=true; 

					     if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					     {
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]= LIC_TYP_APPLAUNCH;
					       faultrow++;				    
					     }
					
					}
				}

				//------------------------------TAPI-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[10].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[10].headerrecord) != 0 ))
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if LIC Internal Number Is Emprty 
					{										   
					     tenthEmpty = true;
					}
					else
					{ 	
					     findEleventh=true; 



					     if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					     {
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]= LIC_TYP_TAPI ;
					       faultrow++;				    
					     }
					
					}				
									
				}
				//-------------------------------SMART UC-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[11].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[11].headerrecord) != 0 ))
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if LIC Internal Number Is Emprty 
					{										   
					     tenthEmpty = true;
					}
					else
					{ 	
					     findTwelvth=true;
					     if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					     {
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]= LIC_TYP_SMARTUC ;
					       faultrow++;				    
					     }
					
					}
									
									
				}
				
/*-------------------------------Zimbra-----------------------------------------------------------------------------------------------   Comment Out Zimbra License
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[12].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[12].headerrecord) != 0 ))
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if LIC Internal Number Is Emprty 
					{										   
					     tenthEmpty = true;
					}
					else
					{ 	
					     findTwelvth=true;
					     if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					     {
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]= LIC_TYP_ZIMBRA ; // LIC_TYP_ZIMBRA
					       faultrow++;				    
					     }
					
					}
									
									
				}
*/
			        //------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[12].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[12].headerrecord) != 0 ))
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  ) // Check if LIC Internal Number Is Emprty 
					{										   
					        eleventhEmpty = true;
					}
					else 
					{
						if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{
							faults[0][0]++;
			      				faults[faultrow][0]=2;
		   					faults[faultrow][1]=numLicenses+3;
						        faults[faultrow][2]=INVALID_NODEID;
						        faultrow++;
						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						        faults[0][0]++;
			      				faults[faultrow][0]=2;
		   					faults[faultrow][1]=numLicenses+3;
						        faults[faultrow][2]=INVALID_NODEID;
						        faultrow++;
						}
						else if( strData.length() > 4 )
						{
						   	faults[0][0]++;
			      				faults[faultrow][0]=2;
		   					faults[faultrow][1]=numLicenses+3;
						        faults[faultrow][2]=INVALID_NODEID;
						        faultrow++;
						}					
						findTwelvth=true;							
					}
					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					
					
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) && (!findFifth) && (!findSixth)  && (!findSeventh) && (!findEighth) && (!findNinth) && (!findTenth) && (!findEleventh) && (!findTwelvth)  )
					{
					    //blLicenses = false;
					    numLicenses = numLicenses;
					}
					else
					   numLicenses++; 
					
					
					
					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) && (fourthEmpty) && (fifthEmpty) && (sixthEmpty) && (seventhEmpty) && (eighthEmpty) 
					&&(ninthEmpty) &&(tenthEmpty) &&(eleventhEmpty) )
					{
						blLicenses = false;
					}					
					
					if( (findFirst) && (findSecond) && (findThird)  && (findFourth) && (findFifth) && (findSixth) && (findSeventh) && (findEighth) && (findNinth) && (findTenth) && (findEleventh) && (findTwelvth) )
					{
						findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
					} 
					else if( (!findFirst) &&  ((findSecond) || (findThird)  || (findFourth) || (findFifth) || (findSixth) || (findSeventh) || (findEighth) || (findNinth) || (findTenth) || (findEleventh) || (findTwelvth) ) )
					{							
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]=CALL_NO_MISSING;
					       faultrow++;
					}					
					else if( (findFirst) &&  (!findSecond) )
					{	
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]=LIC_TYP_USTYP; //LIC_TYP_UCUSER;
					       faultrow++;	
					}
					
					
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;					
					firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;
					
				}
				

			} // END blLicenses
//----------------------------------------------- LICENSES END----------------------------------------------------------------------------------------------------------						


//-----------------------------------------------GROUPS START-----------------------------------------------------------------------------------------------------------			
			else if( (blGroups) && (block>0))
			{				
				//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlGroupsNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[0].headerrecord)!= 0 ) )
				{
					//numGroups++;
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if GRoup Internal Number Is Emprty 
					{										   
					     firstEmpty = true;	
					     //numGroups--;			    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true; 
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {					       
					       faults[0][0]++;
				      	       faults[faultrow][0]=3;
		   			       faults[faultrow][1]=numGroups+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					       faults[0][0]++;
				      	       faults[faultrow][0]=3;
		   			       faults[faultrow][1]=numGroups+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
					    }
					    else
					    {
					    
					     
					    
					    }					    					    		

					    delete [] tmpNumbers;
					}     	
					numberoflines++;
					
					
				}
				//------------------------------DID NUMBER -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlGroupsNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[1].headerrecord)!= 0 ) )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  ) // Check if GRoup Internal Number Is Emprty 
					{										   
					     secondEmpty = true;
				    
					}
					else // Check If Valid Call Number 
					{
					    findSecond=true; 
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
				               faults[0][0]++;
				      	       faults[faultrow][0]=3;
		   			       faults[faultrow][1]=numGroups+3;
					       faults[faultrow][2]=INVALID_DUWA;
					       faultrow++;
					    }
					    else if (strData.length() > ((DID_SIZE*2) -1) )
		   			    {
				               faults[0][0]++;
				      	       faults[faultrow][0]=3;
		   			       faults[faultrow][1]=numGroups+3;
					       faults[faultrow][2]=INVALID_DUWA;
					       faultrow++;
					    }
					    else
					    {
					     	
							 
					    }
					    
					    
					    delete [] tmpNumbers;
					}    
					 	
				}
				//------------------------------DISPLAY NAME -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlGroupsNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[2].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}
					else 
					{	klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=INVALID_NAME;
						       faultrow++;
						}
						else if ( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=INVALID_NAME;
						       faultrow++;	
						}
						findThird=true; 
					}
					
				}
				//------------------------------Voicemail -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlGroupsNameTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[3].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}
					else 
					{							
						if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0)  )	
						{
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=WRONG_VOICEMAIL_FORMAT;
						       faultrow++;
						}
						findThird=true; 
					}
					
				}
				//------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlGroupsNameTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[4].headerrecord)!= 0)  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     fourthEmpty = true;
					}					
					else 
					{
						if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{	       
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;						       
	
						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;						       
						}
						else if ( strData.length() > 4) 
						{
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;						       
						}
					
						findFourth=true; 
					}
					
					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) )
					{
					   // blGroups = false;
					   numGroups=numGroups;
					}
					else
					   numGroups++;


					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) && (fourthEmpty) )
					{
					    blGroups = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
					    fourthEmpty=false;
				        }
				       
					if( (findFirst) && (findSecond) && (findThird)  && (findFourth)  )
					{
						findFirst=false; findSecond=false; findThird=false; findFourth=false; 
					} 
					else if( (!findFirst) &&  ((findSecond) || (findThird)  || (findFourth) ) )
					{	
						faults[0][0]++;
				      	    	faults[faultrow][0]=3;
		   			    	faults[faultrow][1]=numGroups+3;
					    	faults[faultrow][2]=CALL_NO_MISSING;
					    	faultrow++;					
					}
					
					   
					firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;

					
				}
				
								
			}// END blGroups
			
//-----------------------------------------------GROUPS END-----------------------------------------------------------------------------------------------------------						
			
//-----------------------------------------------VIRTUAL START-----------------------------------------------------------------------------------------------------------									
			
			else if( (blVirtual)  && (block>0))
			{

	  			//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlVirtualNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[0].headerrecord)!= 0 ) )
				{
					//numVirtual++;
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     firstEmpty = true;	
					     //numVirtual--;			    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true;   
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
				           	faults[0][0]++;
				      	    	faults[faultrow][0]=4;
		   			    	faults[faultrow][1]=numVirtual+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;						       					    
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					        faults[0][0]++;
				      	    	faults[faultrow][0]=4;
		   			    	faults[faultrow][1]=numVirtual+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;	
					    
					    }
					    else
					    {
					
					    }
					    					    
					    delete [] tmpNumbers;
					}
					   	
					numberoflines++;
				}
				//------------------------------DID NUMBER -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVirtualNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[1].headerrecord)!= 0 ) )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  ) // Check if GRoup Internal Number Is Emprty 
					{										   
					     secondEmpty = true;
				    
					}
					else // Check If Valid Call Number 
					{
					    findSecond=true;  
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
					        faults[0][0]++;
 			      	    		faults[faultrow][0]=4;
		   			    	faults[faultrow][1]=numVirtual+3;
					    	faults[faultrow][2]=INVALID_DUWA;
					    	faultrow++;
	
					    }
					    else if (strData.length() > ((DID_SIZE*2) -1) )
					    {
					        faults[0][0]++;
 			      	    		faults[faultrow][0]=4;
		   			    	faults[faultrow][1]=numVirtual+3;
					    	faults[faultrow][2]=INVALID_DUWA;
					    	faultrow++;
					    }
					    else
					    {
					    	
					    }					    					    
					    
					    delete [] tmpNumbers;
					}    
						
				}
				//------------------------------DISPLAY NAME -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVirtualNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[2].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}
					else 
					{

						klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						   faults[0][0]++;
	 			      	    	   faults[faultrow][0]=4;
			   			   faults[faultrow][1]=numVirtual+3;
						   faults[faultrow][2]=INVALID_NAME;
						   faultrow++;	
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
	 			      	    	   	faults[faultrow][0]=4;
			   			   	faults[faultrow][1]=numVirtual+3;
						   	faults[faultrow][2]=INVALID_NAME;
						   	faultrow++;		
						}
						findThird=true;
					}
				}
				//----------------------------STATION TYPE ------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVirtualNameTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(),xmlVirtualNameTable[3].headerrecord)!=0) )
				{
					if ( strcmp(strData.c_str(),"empty") == 0 )
					{	
					     fourthEmpty = true;
					}					
					else
					{ 
						if(blX1)
						{
							if(strcmp ( strData.c_str(),  xmlVirtualStationTypes[5].name ) != 0  )
							{
								faults[0][0]++;
								faults[faultrow][0]=4;
		   						faults[faultrow][1]=numVirtual+3;
						        	faults[faultrow][2]=STN_TYP_UNKNOWN;
						        	faultrow++;
							}
							
							findFourth=true;
						
						}
						else
						{
						if( !CheckStationTypeVirtual(strData.c_str()) ) // ||  (strcmp(strData.c_str(),"empty") == 0) )
						{					    					    
						    faults[0][0]++;
	  			      	    	    faults[faultrow][0]=4;
			   			    faults[faultrow][1]=numVirtual+3;
						    faults[faultrow][2]=STN_TYP_UNKNOWN;
						    faultrow++;
						}
						findFourth=true;
						}
					}
				}
				//------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVirtualNameTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[4].headerrecord)!= 0)  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     fifthEmpty = true;
					}					
					else 
					{
						if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{
						    faults[0][0]++;
  				      	    	    faults[faultrow][0]=4;
			   			    faults[faultrow][1]=numVirtual+3;
						    faults[faultrow][2]=INVALID_NODEID;
						   faultrow++;

						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						    faults[0][0]++;
	  			      	    	    faults[faultrow][0]=4;
		   				    faults[faultrow][1]=numVirtual+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;
						}
						else if(strData.length() > 4)
						{
						    faults[0][0]++;
  			      		    	    faults[faultrow][0]=4;
		   				    faults[faultrow][1]=numVirtual+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;
						}
															
						findFifth=true; 
					}
					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) && (!findFifth)  )
					{
					   // blVirtual = false;
					   numVirtual = numVirtual;
					}
					else
					   numVirtual++;
						
					
					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) && (fourthEmpty) && (fifthEmpty))
					{
					    blVirtual = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
					    fourthEmpty=false;
					    fifthEmpty=false;
				        }
				       /*
				        else if(  (firstEmpty)  && ( (!secondEmpty) || (!thirdEmpty) || (!fourthEmpty)  || (!fifthEmpty)  )  )
				        {
					    faults[0][0]++;
  			      	    	    faults[faultrow][0]=4;
		   			    faults[faultrow][1]=numVirtual+2;
					    faults[faultrow][2]=CALL_NO_MISSING;
					    faultrow++;
					    
					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
					    fourthEmpty=false;
					    fifthEmpty = false;
 				        }
					*/
					if( (findFirst) && (findSecond) && (findThird)  && (findFourth) && (findFifth)  )
					{
						findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; 
					}
					else if(  (findFirst) &&  (!findFourth) )
					{
						 faults[0][0]++;
	  			      	    	 faults[faultrow][0]=4;
			   			 faults[faultrow][1]=numVirtual+3;
						 faults[faultrow][2]=STN_TYP_UNKNOWN;
						 faultrow++;						
					} 
					else if( (!findFirst) &&  ((findSecond) || (findThird)  || (findFourth) || (findFifth)  ) )
					{		
						faults[0][0]++;
  			      	    	   	faults[faultrow][0]=4;
		   			    	faults[faultrow][1]=numVirtual+3;
					   	faults[faultrow][2]=CALL_NO_MISSING;
					   	faultrow++;	
					}
					
					firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
					//numVirtual++;
				}
			

				


			}// END If VIRTUAL
//-----------------------------------------------VIRTUAL END-----------------------------------------------------------------------------------------------------------									
			
//-----------------------------------------------TRUNK GROUPS---------------------------------------------------------------------------------------------------------			
			else if( (blTrunkGroup)  && (block>0))
			{

				//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlTrunkGrpNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlTrunkGrpNameTable[0].headerrecord)!= 0 ) )
				{
					//numTrunkGroups++;
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     firstEmpty = true;	
					    // numTrunkGroups--;			    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true; 
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
						faults[0][0]++;
  			      	    	    	faults[faultrow][0]=5;
		   			    	faults[faultrow][1]=numTrunkGroups+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
						faults[0][0]++;
  			      	    	    	faults[faultrow][0]=5;
		   			    	faults[faultrow][1]=numTrunkGroups+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;
					    }
					    else
					    {

					    					    
					    }
					    
					    delete [] tmpNumbers;
					}     	
					numberoflines++;
					
				}
				//------------------------------DISPLAY NAME -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlTrunkGrpNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlTrunkGrpNameTable[1].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     secondEmpty = true;
					}
					else 
					{
						
						klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						    faults[0][0]++;
  			      	    		    faults[faultrow][0]=5;
		   				    faults[faultrow][1]=numTrunkGroups+3;
						    faults[faultrow][2]=INVALID_NAME;
						    faultrow++;
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
						    faults[0][0]++;
  			      	    		    faults[faultrow][0]=5;
		   				    faults[faultrow][1]=numTrunkGroups+3;
						    faults[faultrow][2]=INVALID_NAME;
						    faultrow++;	
						}
						findSecond=true;
					}
				}
				//------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlTrunkGrpNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlTrunkGrpNameTable[2].headerrecord)!= 0)  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}					
					else 
					{
						if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{					       
						    faults[0][0]++;
  				      	    	    faults[faultrow][0]=5;
			   			    faults[faultrow][1]=numTrunkGroups+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;					       					       
						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						    faults[0][0]++;
  				      	    	    faults[faultrow][0]=5;
			   			    faults[faultrow][1]=numTrunkGroups+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;					       					       
						}
						else if (strData.length() > 4)
						{
						    faults[0][0]++;
  				      	    	    faults[faultrow][0]=5;
			   			    faults[faultrow][1]=numTrunkGroups+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;					       					       
						}
						findThird=true; 
					}
						
					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) && (!findFifth) && (!findSixth)  && (!findSeventh) && (!findEighth) && (!findNinth) && (!findTenth) && (!findEleventh) && (!findTwelvth)  )
					{
					    numTrunkGroups=numTrunkGroups;
					}
					else
						numTrunkGroups++;
					
					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) )
					{
					    blTrunkGroup = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
				        }
				        /*else if(  (firstEmpty)  && ( (!secondEmpty) || (!thirdEmpty)  )  )
				        {
					    faults[0][0]++;
  			      	    	    faults[faultrow][0]=5;
		   			    faults[faultrow][1]=numTrunkGroups+2;
					    faults[faultrow][2]=CALL_NO_MISSING;
					    faultrow++;					       					       
					    					    
					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
 				        }	
					*/
					if( (findFirst) && (findSecond) && (findThird)  )
					{
						findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
					} 
					else if( (!findFirst) &&  ((findSecond) || (findThird)  ) )
					{	
						faults[0][0]++;
  			      	    	    	faults[faultrow][0]=5;
		   			    	faults[faultrow][1]=numTrunkGroups+3;
					    	faults[faultrow][2]=CALL_NO_MISSING;
					    	faultrow++;					       					       					    				
					}
					
					
					firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
					
				}				
				

			}
			else if( (blVoicemail)  && (block>0))
			{

				//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlVoiceMailNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVoiceMailNameTable[0].headerrecord)!= 0 ) )
				{
					//numVoicemail++;
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     firstEmpty = true;	
					     //numVoicemail--;			    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true; 
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {					       
					       faults[0][0]++;
	  			      	       faults[faultrow][0]=6;
			   		       faults[faultrow][1]=numVoicemail+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					       faults[0][0]++;
	  			      	       faults[faultrow][0]=6;
			   		       faults[faultrow][1]=numVoicemail+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
				            }
					    else
					    {
						
					    }
					    delete [] tmpNumbers;
					}     	
					numberoflines++;
					
				}
				//------------------------------DISPLAY NAME -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVoiceMailNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVoiceMailNameTable[1].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     secondEmpty = true;
					}
					else
					{
						klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE)  )
						{
					       		faults[0][0]++;
	  			      	       		faults[faultrow][0]=6;
				   		       	faults[faultrow][1]=numVoicemail+3;
						       	faults[faultrow][2]=INVALID_NAME;
						       faultrow++;
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
	  			      	       		faults[faultrow][0]=6;
				   		       	faults[faultrow][1]=numVoicemail+3;
						       	faults[faultrow][2]=INVALID_NAME;
						       faultrow++;	
						}
						findSecond=true; 
					}
				}
				//------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVoiceMailNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVoiceMailNameTable[2].headerrecord)!= 0)  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}					
					else
					{
						 if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{					       
					       		faults[0][0]++;
		  			      	       	faults[faultrow][0]=6;
				   		       faults[faultrow][1]=numVoicemail+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;
						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						       faults[0][0]++;
		  			      	       faults[faultrow][0]=6;
				   		       faults[faultrow][1]=numVoicemail+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;
						}
						else if(strData.length() > 4)
						{
						       faults[0][0]++;
		  			      	       faults[faultrow][0]=6;
				   		       faults[faultrow][1]=numVoicemail+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;
						}
						
						findThird=true; 
					}					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					
					if( (!findFirst) && (!findSecond) && (!findThird) )
					{
						numVoicemail = numVoicemail;
						
					} 
					else
						numVoicemail++;
						
					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) )
					{
					    blVoicemail = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
				        }										
					
					else if( (!findFirst) &&  ((findSecond) || (findThird) ) )
					{		
						faults[0][0]++;
	  			      	  	faults[faultrow][0]=6;
			   		    	faults[faultrow][1]=numVoicemail+3;
					    	faults[faultrow][2]=CALL_NO_MISSING;
					    	faultrow++;		
					}
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;	
					firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;
					//numVoicemail++;
				}
				
			} // end if voicemail
			
//-----------------------------------------------SipConfig-----------------------------------------------------------------------------------------------------------									
			
			else if( (blSipConfig)  && (block>0))
			{

	  			//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlSipConfigTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[0].headerrecord)!= 0 ) )
				{
					
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     firstEmpty = true;	
					     		    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true;   
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
				           	faults[0][0]++;
				      	    	faults[faultrow][0]=6;
		   			    	faults[faultrow][1]=numSipConfig+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;						       					    
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					        faults[0][0]++;
				      	    	faults[faultrow][0]=6;
		   			    	faults[faultrow][1]=numSipConfig+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;	
					    
					    }
					    else
					    {
						  
					    }
					    					    
					    delete [] tmpNumbers;
					}
					   	
					numberoflines++;
				}
				//------------------------------Password Sip -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlSipConfigTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[1].headerrecord)!= 0 ) )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  ) // Check if GRoup Internal Number Is Emprty 
					{										   
					     secondEmpty = true;
				    
					}
					else // Check If Valid Call Number 
					{
					    findSecond=true;  
					    klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						   faults[0][0]++;
	 			      	    	   faults[faultrow][0]=6;
			   			   faults[faultrow][1]=numSipConfig+3;
						   faults[faultrow][2]=55;
						   faultrow++;	
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
	 			      	    	   	faults[faultrow][0]=6;
			   			   	faults[faultrow][1]=numSipConfig+3;
						   	faults[faultrow][2]=88;
						   	faultrow++;		
						}
					    // Here will check the type of password					    
					}    
						
				}
				//------------------------------UserId/Username  -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlSipConfigTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[2].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}
					else 
					{

						klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						   faults[0][0]++;
	 			      	    	   faults[faultrow][0]=6;
			   			   faults[faultrow][1]=numSipConfig+3;
						   faults[faultrow][2]=4;
						   faultrow++;	
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
	 			      	    	   	faults[faultrow][0]=6;
			   			   	faults[faultrow][1]=numSipConfig+3;
						   	faults[faultrow][2]=4;
						   	faultrow++;		
						}
						findThird=true;
					}
				}
				//----------------------------Realm ------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlSipConfigTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(),xmlSipConfigTable[3].headerrecord)!=0) )
				{
					if ( strcmp(strData.c_str(),"empty") == 0 )
					{	
					     fourthEmpty = true;
					}					
					else
					{ 						
						klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						   faults[0][0]++;
	 			      	    	   faults[faultrow][0]=6;
			   			   faults[faultrow][1]=numSipConfig+3;
						   faults[faultrow][2]=4;
						   faultrow++;	
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
	 			      	    	   	faults[faultrow][0]=6;
			   			   	faults[faultrow][1]=numSipConfig+3;
						   	faults[faultrow][2]=4;
						   	faultrow++;		
						}   
					  findFourth=true;						
					}
				}
				//------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlSipConfigTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[4].headerrecord)!= 0)  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     fifthEmpty = true;
					}					
					else 
					{
						if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{
						    faults[0][0]++;
  				      	    	    faults[faultrow][0]=4;
			   			    faults[faultrow][1]=numVirtual+3;
						    faults[faultrow][2]=INVALID_NODEID;
						   faultrow++;

						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						    faults[0][0]++;
	  			      	    	    faults[faultrow][0]=4;
		   				    faults[faultrow][1]=numVirtual+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;
						}
						else if(strData.length() > 4)
						{
						    faults[0][0]++;
  			      		    	    faults[faultrow][0]=4;
		   				    faults[faultrow][1]=numVirtual+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;
						}
															
						findFifth=true; 
					}
					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) && (!findFifth)  )
					{
					   // blVirtual = false;
					   numSipConfig = numSipConfig;
					}
					else
					   numSipConfig++;
						
					
					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) && (fourthEmpty) && (fifthEmpty))
					{
					    blSipConfig = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
					    fourthEmpty=false;
					    fifthEmpty=false;
				        }
				       
				}
			

				


			}// END If SipConfig
//-----------------------------------------------SipConfig-----------------------------------------------------------------------------------------------------------									
			
			
		
		}  // END // If the Record is OK
		
	//} //  END BLSTATION 

	
	countLine++;//increase countLines number to numberring Lines   
	
    }// ----end while read lines-------
    
    //delete [] tmpNumbers;
    
    
    type[0] = numStations; // Licenses Number
    type[1] = numLicenses; // Licenses Number
    type[2] = numGroups;   // Group Number
    type[3] = numVirtual;   //  Virtual Number
    type[4] = numTrunkGroups; // Trunk number
    type[5] = numVoicemail;   // Voicemail Number 
    type[6] = numSipConfig;   // Voicemail Number 
    
    if(corXml==0)
    {
	    faults[0][0]++;
	    faults[faultrow][0]=1;
	    faults[faultrow][1]= 0; // invalid Xml with no contents 
	    faults[faultrow][2]=INVALID_FILE_FORMAT;
	    faultrow++;	
    }
    /*  cout << " numStations= " <<type[0] << endl;    cout << " numLicenses= " <<  type[1]<< endl;    cout << " numGroups= " <<  type[2]<< endl;    cout << " numVirtual= " <<  type[3]<< endl;    cout << " numTrunkGroups= " <<  type[4]<< endl;    cout << " numVoicemail= " <<  type[5] << endl;   
       cout << " ilias aults[0][0]= " <<  faults[0][0] << endl;   
     */
    errorCount = faultrow; 

    fclose(fxml);

    if(faults[0][0]==0)
    return  0; 
    else 
    return errorCount;  

}
 // The Function Check If the Station Type is contained in the default List,If Not Return False, if it's ok Return True
 
 
int LXWorkSheetRecords(char* fname, int type[5], int errorCount, int faults[21][3])
{
    char line [128]; 
    char *tmpNumbers;
    FILE *fxml = fopen(fname,"r");
    int fLast,fFirst,intLen,wksFound,findNameCell=0,findCell=0,countLine=0,rowCount=0,result=-1,wksRowFound,corXml=0,klen=0,fFiltDb=0,uc_count=0;
    string tempstr,totalstr,strData,strCell;  
    bool blStations=false,blLicenses=false,blGroups=false,blVirtual=false,blTrunkGroup=false,blVoicemail=false,blCellEnd=false,blEndRecord=false,blSipConfig=false;
    int i=0,pos=0,numStations=0,numLicenses=0,numGroups=0,numVoicemail=0,numVirtual=0,numTrunkGroups=0,numberoflines=1,faultrow=1,record=0,block=0,numSipConfig=0;	
   
     bool firstEmpty=false,secondEmpty=false,thirdEmpty=false,fourthEmpty=false,fifthEmpty=false,sixthEmpty=false,seventhEmpty=false,eighthEmpty=false,ninthEmpty=false,tenthEmpty=false,eleventhEmpty=false
    ,twelvthEmpty=false,therteenthEmpty=false;
    bool findFirst=false,findSecond=false,findThird=false,findFourth=false,findFifth=false,findSixth=false,findSeventh=false,findEighth=false,findNinth=false,findTenth=false,findEleventh=false,findTwelvth=false,findTherteenth=false;

//    unsigned char chEmpty;
     RD_KDS_RETURN			kdsreturn,kdsreturnacode;
     char * sacode;
     int  inhalt[256];
     bool blHasEvm = true;
    
    
    
    
     // uc_count= Db_rddtb((enum KDS_TABLE) KDS_VPLRN_DDI, (DB_ZEILE_T)0, (DB_SPALTE_T)KEINE_SPALTE, &kdsreturnacode );
     // FPUti::bcd_to_a ( &kdsreturnacode.inhalt[0], inhalt, (WORD)uc_count );   
     
    
    
    errorCount = 0;
        
    for(i=0;i<21;i++)
    {
	for(pos=0;pos<3;pos++)
		faults[i][pos]=0;
    }

// -- Prepei na mpoun edo kai Safe Conditions an Skasei        
    while ( fgets ( line,128,fxml ) != NULL ) // read a line by line
    {
	
	if (faultrow > 20)
		break;
	
	tempstr=line; // this temp str contains the current line
	intLen = strlen(line);

	
	//---1-find----WorkSheet name ------------------------------
	wksFound= tempstr.find("Worksheet ss:Name");
	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
	        fFirst= tempstr.find("\"");
	        fLast=tempstr.find_last_of("\"");   
	        tempstr = tempstr.substr(fFirst+1,(fLast-(fFirst+1)));		

		if(tempstr == "Stations")
		{
	   	   blStations = true;
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name   
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;twelvthEmpty=false; therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false; findTherteenth=false;
		   countLine=0;
		   corXml++;
		}
		else if(tempstr =="Licenses")
		{
		   blLicenses = true; 	
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;twelvthEmpty=false; therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false; findTherteenth=false;
		   countLine=0;
		   corXml++;		   
		}
		else if(tempstr =="Groups")		
		{
		   blGroups = true;		    
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 		
		   countLine=0;		
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;twelvthEmpty=false; therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false; findTherteenth=false;
		   corXml++;		   
		}
		else if(tempstr =="Virtual")		
		{
		   blVirtual = true;
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 		
		   countLine=0;		
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;twelvthEmpty=false; therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false; findTherteenth=false;
		   corXml++;		   
		   
		}
		else if(tempstr =="Trunk Groups")
		{
		   blTrunkGroup = true;		
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 		   
		   countLine=0;		
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;twelvthEmpty=false; therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false; findTherteenth=false;
		   corXml++;		   

		}
		else if(tempstr =="Voicemail")	
		{
		   blVoicemail = true;		   
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 		   
		   countLine=0;		
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;twelvthEmpty=false; therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false; findTherteenth=false;
		   corXml++;
		}
		else if(tempstr =="SipConfig")	
		{
		   blSipConfig = true;		   
		   block=0;          
		   record=0;        
		   countLine=0;		
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;
		   corXml++;
		}

    	}// end worksheet search 

	//---2 find the End of WorkSheet-------------
	wksFound= tempstr.find("</Worksheet>");
	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
		if(blStations)
		{
			blStations = false;
		}
		else if(blLicenses)
		{
			blLicenses = false;
		}
		else if(blGroups)
		{
			blGroups = false;
		}
		else if(blVirtual)
		{
			blVirtual = false;
		}
		else if(blTrunkGroup)
		{
			blTrunkGroup = false;
		}
		else if(blVoicemail)
		{
			blVoicemail = false;
				
		}
		else if(blSipConfig)
		{
			blSipConfig = false;
			break;	
		}


	}


	blEndRecord = false;
	//if(blStations)
	//{
		wksFound = tempstr.find("</Data>");
		findNameCell = tempstr.find("<NamedCell");
		findCell = tempstr.find("</Cell>");
		wksRowFound = tempstr.find("</Row>");
		fFiltDb = tempstr.find("FilterDatabase");

		//  CASE  A -- Check if the line is empty, has no data, only namedcell
		if((findNameCell > -1) && (wksFound == -1)  && (fFiltDb==-1) ) 
		{
			fLast = tempstr.find("</Cell>");
			fLast = fLast -3;
			fFirst = tempstr.rfind("=\"");
			fFirst  = fFirst+2;
			strCell = tempstr.substr(fFirst,(fLast-fFirst));
			strData = "empty";
			blEndRecord = true;
		}
		// CASE B scenario we had Data and NameCell Filled in the Same Line 		
		else if( (wksFound > -1) && (findNameCell > -1)  && (findCell >-1) )
		{			
			//cell name
			fLast = tempstr.find("</Cell>");
			fLast = fLast -3;
			fFirst = tempstr.rfind("=\"");
			fFirst  = fFirst+2;
			strCell = tempstr.substr(fFirst,(fLast-fFirst));
			//data 
			fLast = wksFound;  //tempstr.find("</Data>");
			fFirst = tempstr.rfind("\">");
			strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));
			blEndRecord = true;			
		}
		// CASE C -- Has Data and NameCell but the Cell END is in the next Line
		else if( (wksFound > -1) && (findNameCell > -1)  && (findCell == -1) )
		{
			//data 
			fLast = wksFound;  //tempstr.find("</Data>");
			fFirst = tempstr.rfind("\">");
			strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));
			if(strData.length() == 0 )
				strData = "empty";
			blCellEnd = true; // wait the end of the Cell		
		}
		else if( (findCell > -1) &&  (blCellEnd)  ) // find the end of Cell
		{
			blCellEnd = false;
			//cell name
			fLast = tempstr.find("</Cell>");
			fLast = fLast -3;
			fFirst = tempstr.rfind("=\"");
			fFirst  = fFirst+2;
			strCell = tempstr.substr(fFirst,(fLast-fFirst));
			blEndRecord = true;	
		}
		else if(wksRowFound > -1)	
		{
			blEndRecord = true;
			strData = "</Row>";
			strCell="";			
		}

		//  When Find a Record the blEndRecord is TRUE 
		if((blEndRecord)  &&  (faultrow <21) )
		{
			
//----------------Start ----  Validation -- Check If the Header of Each  Sheet Is Correct ----------------------------------------------			
			if(blStations) 
			{
				
				
				if(record >14)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;twelvthEmpty=false; therteenthEmpty=false;
				}
				

				if(block == 0) // CHeck if The Header Column Is COrrect 
				{
					if( (strcmp(strCell.c_str(),xmlStationsNameTable[record].namedcell) != 0 ) || 
					(strcmp(strData.c_str(), xmlStationsNameTable[record].headerrecord) != 0) )
					{
					    faults[0][0]++;
					    faults[faultrow][0]=1;
					    faults[faultrow][1]= numStations+2; //countLine+2;
					    faults[faultrow][2]=INVALID_FILE_FORMAT;
					    faultrow++;				     
					}
					
					record++;
				}

			  }
			  if(blLicenses) 
			  {
			
				if(record >12)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;twelvthEmpty=false; therteenthEmpty=false;
				}
				
				if(block == 0) // CHeck if The Header Column Is COrrect 
				{
					if( (strcmp(strCell.c_str(),xmlLicensesNameTable[record].namedcell) != 0 ) || 
					(strcmp(strData.c_str(), xmlLicensesNameTable[record].headerrecord) != 0) )
					{
					    faults[0][0]++;
					    faults[faultrow][0]=2;	
					    faults[faultrow][1]=numLicenses+2;// countLine+2;
					    faults[faultrow][2]=INVALID_FILE_FORMAT;
					    faultrow++;
					}					
					record++;
				}
				
			   }
			  if(blGroups) 
			  {
				if(record >4)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;twelvthEmpty=false; therteenthEmpty=false;
				}
				
				if(block == 0) // CHeck if The Header Column Is COrrect 
				{
					if( (strcmp(strCell.c_str(),xmlGroupsNameTable[record].namedcell) != 0 ) || 
					(strcmp(strData.c_str(), xmlGroupsNameTable[record].headerrecord) != 0) )
					{
					    faults[0][0]++;
					    faults[faultrow][0]=3;
					    faults[faultrow][1]=numGroups+2; //countLine+2; 	
					    faults[faultrow][2]=INVALID_FILE_FORMAT;
					    faultrow++;
				    
					}
					
					record++;					
				}
				
			   }
			  
			  if(blVirtual) 
			  {
				if(record >4)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;twelvthEmpty=false; therteenthEmpty=false;
				}
				
				if(block == 0) // CHeck if The Header Column Is COrrect 
				{
					if( (strcmp(strCell.c_str(),xmlVirtualNameTable[record].namedcell) != 0 ) || 
					(strcmp(strData.c_str(), xmlVirtualNameTable[record].headerrecord) != 0) )
					{						    
					    faults[0][0]++;
					    faults[faultrow][0]=4;
					    faults[faultrow][1]=numVirtual+2; //countLine+2; 	
					    faults[faultrow][2]=INVALID_FILE_FORMAT;
					    faultrow++;
					}
					
					record++;
				}
				
			   }
			   
			  if(blTrunkGroup) 
			  {
				if(record >2)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;twelvthEmpty=false; therteenthEmpty=false;
				}
				if(block == 0) // CHeck if The Header Column Is COrrect 
				{
					if( (strcmp(strCell.c_str(),xmlTrunkGrpNameTable[record].namedcell) != 0 ) || 
					(strcmp(strData.c_str(), xmlTrunkGrpNameTable[record].headerrecord) != 0) )
					{
					    faults[0][0]++;
					    faults[faultrow][0]=5;
					    faults[faultrow][1]=numTrunkGroups+2; //countLine+2; 	
					    faults[faultrow][2]=INVALID_FILE_FORMAT;
					    faultrow++;
					}
				
					record++;
				}
				
				
			   }
			   
			  if(blVoicemail) 
			  {
				if(record >2)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;twelvthEmpty=false; therteenthEmpty=false;
				}
				if(block == 0) // CHeck if The Header Column Is COrrect 
				{
					if( (strcmp(strCell.c_str(),xmlVoiceMailNameTable[record].namedcell) != 0 ) || 
					(strcmp(strData.c_str(), xmlVoiceMailNameTable[record].headerrecord) != 0) )
					{
					    faults[0][0]++;
					    faults[faultrow][0]=6;
					    faults[faultrow][1]=numVoicemail+2; //countLine+2; 	
					    faults[faultrow][2]=INVALID_FILE_FORMAT;
					    faultrow++;
					}
					record++;
				}
				
			   }
			   if(blSipConfig)
			   {
				if(record >2)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
				}
				if(block == 0) // CHeck if The Header Column Is COrrect 
				{
					if( (strcmp(strCell.c_str(),xmlSipConfigTable[record].namedcell) != 0 ) || 
					(strcmp(strData.c_str(), xmlSipConfigTable[record].headerrecord) != 0) )
					{
					    
					            faults[0][0]++;
						    faults[faultrow][0]=7;
						    faults[faultrow][1]=numSipConfig+2; //countLine+2; 	
						    faults[faultrow][2]=INVALID_FILE_FORMAT;
						    faultrow++;
					}
					record++;
				}
				
			   }
			  					
//----------------END ----  Validation -- Check If the Header of Each  Sheet Is Correct ----------------------------------------------						
			
//----------------------------------------------STATIONS--------------------------------------------------------------------------------------------------------------
			if( (blStations)  &&  (block > 0) )
			{
				
				//---------------------------INTERNAL NUMBER------------------------------------------------------

				if( ( strcmp(strCell.c_str(),xmlStationsNameTable[0].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[0].headerrecord) != 0 )
				  )
				{														
					// numStations++;
					
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if Internal Number Is Emprty 
					{					   
					    firstEmpty = true;					    
					    //numStations--;
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true;
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {				       
					       faults[0][0]++;
					       faults[faultrow][0]=1;
   					       faults[faultrow][1]=numStations+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
					    				    
					    }
					    else if(strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					       faults[0][0]++;
					       faults[faultrow][0]=1;
   					       faults[faultrow][1]=numStations+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
			    
					    }
					    else
					    {
				

					     }
					    //----------call old Checks --------------------------------------
					    
					    delete[] tmpNumbers;
				         }
 				    numberoflines++;
				    

				}
				//-----------------------END----INTERNAL NUMBER------------------------------------------------------
				
				
				//----------------------------DID NUMBER --------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[1].headerrecord)!= 0
				 ) )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     secondEmpty = true;
					}
					else
					{
						findSecond=true; 
						
						tmpNumbers = new char[strData.length()+1];  
						strcpy(tmpNumbers,strData.c_str());
						
						 //Check if Valid Number  Duwa or Is Empty Then Error
						if( (!checkvalidCallDuwa(tmpNumbers) )  ||  (strcmp(strData.c_str(),"empty") == 0) ) 
						{
					     	        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_DUWA;
					                faultrow++;
						    
						}
						else if(strData.length() >  ((RUFNR_SIZE*2) -2 ) )
					    	{						       
						        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_DUWA;
					                faultrow++;
			    
					    	}
						else
						{
						}
						    delete[] tmpNumbers;
					}
					
					

				}
				//-----------------------END-----DID NUMBER -----------------------------------------------------------
				
				
				//----------------------------DISPLAY NAME ------------------------------------------------------
				//else if( (strCell=="displayname")  &&  (strData !="Display name") && (strData !="empty") )
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[2].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}
					else 
					{
						findThird=true; 
						
						klen=0;
						klen= my_strlen_utf8_c(strData.c_str());
						if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
							faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=INVALID_NAME_CHARACTERS;
						        faultrow++;	

						}
						else if( (strData.length() > (TLN_NAME_SIZE))     &&   (klen>TLN_NAME_SIZE ) )
						{
						    	faults[0][0]++;
							faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=INVALID_NAME;
						        faultrow++;	
						}
					}
					
					
				}
				//--------------------------END --DISPLAY NAME ------------------------------------------------------
				
				//----------------------------STATION TYPE ------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(),xmlStationsNameTable[3].headerrecord)!=0) )
				{
					if ( strcmp(strData.c_str(),"empty") == 0 )
					{	
					     fourthEmpty = true;
					}					
					else 
					{
						
						findFourth=true; 
						if( !LXCheckStationType(strData.c_str()) ) // ||  (strcmp(strData.c_str(),"empty") == 0) )
						{					    
							faults[0][0]++;
							faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=STN_TYP_UNKNOWN;
						        faultrow++;	
						}
					}
					
					
				}
				//--------------------------END --STATION TYPE ------------------------------------------------------
				// --------------------------FAX Call no -------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[4].headerrecord)!= 0
				 ) )
				{
				
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if Internal Number Is Emprty 
					{					   
					    fifthEmpty = true;					    
					}
					else // Check If Valid Call Number 
					{
					    findFifth=true;
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());
					    if(!checkvalidCallDuwa(tmpNumbers))
					    {				       
					       faults[0][0]++;
					       faults[faultrow][0]=1;
   					       faults[faultrow][1]=numStations+3;
					       faults[faultrow][2]=INVALID_FAXCALLNO;
					       faultrow++;
					    				    
					    }
					    else if(strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					       faults[0][0]++;
					       faults[faultrow][0]=1;
   					       faults[faultrow][1]=numStations+3;
					       faults[faultrow][2]=INVALID_FAXCALLNO;
					       faultrow++;
			    
					    }
					    else
					    {
					    
					     }
					    //----------call old Checks --------------------------------------					    
					    delete[] tmpNumbers;
				         }
				
				}				
				
				//---------------------------FAX DID -----------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[5].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[5].headerrecord)!= 0
				 ) )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     sixthEmpty = true;
					}
					else
					{
						findSixth  = true;
						tmpNumbers = new char[strData.length()+1];  
						strcpy(tmpNumbers,strData.c_str());
						
						 //Check if Valid Number  Duwa or Is Empty Then Error
						if( (!checkvalidCallDuwa(tmpNumbers) )  ||  (strcmp(strData.c_str(),"empty") == 0) ) 
						{
					     	        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_FAXDID;
					                faultrow++;
						    
						}
						else if(strData.length() > ((RUFNR_SIZE*2) -2 ))
					    	{						       
						        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_FAXDID;
					                faultrow++;
			    
					    	}
						else
						{
						    	
							
							
						}
						    delete[] tmpNumbers;
					}										
				}
				
				//----------------------------FAX NAME ------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[6].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[6].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     //thirdEmpty = true;
					     therteenthEmpty = true;
					}
					else 
					{
						//findThird=true; 
						findTherteenth=true;
						klen=0;
						klen= my_strlen_utf8_c(strData.c_str());
						if( (strData.length() > (TLN_NAME_SIZE))     &&   (klen>TLN_NAME_SIZE ) )
						{
						    	faults[0][0]++;
							faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=INVALID_FAX_NAME;
						        faultrow++;	
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
							faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=INVALID_FAX_NAME;
						        faultrow++;
						}
												
					}
					
					
				}

				//---------------------------Class of service  ------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[7].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[7].headerrecord)!= 0
				 ) )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     seventhEmpty = true;
					}
					else
					{
						findSeventh  = true;
						tmpNumbers = new char[strData.length()+1];  
						strcpy(tmpNumbers,strData.c_str());
						
						 //Check if Valid Number  Duwa or Is Empty Then Error
						if( (!checkvalidCallDuwa(tmpNumbers) )  ) 
						{
					     	        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_COS;
					                faultrow++;
						    
						}
						else if(strData.length() > ((DID_SIZE*2) -1))
					    	{						       
						        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_COS;
					                faultrow++;
			    
					    	}
						else if((atoi(strData.c_str())  < 1)   ||  (atoi(strData.c_str())  > 15 ))
					    	{						       
						        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_COS;
					                faultrow++;
			    
					    	}
						
						
					        delete[] tmpNumbers;
					}				
				
				}				
				
				//---------------------------Call pickup ------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[8].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[8].headerrecord)!= 0
				 ) )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     eighthEmpty = true;
					}
					else
					{
						findEighth  = true;
						tmpNumbers = new char[strData.length()+1];  
						strcpy(tmpNumbers,strData.c_str());
						
						 //Check if Valid Number  Duwa or Is Empty Then Error
						if( (!checkvalidCallDuwa(tmpNumbers) )  ) 
						{
					     	        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_CALLPICKUP;
					                faultrow++;
						    
						}
						else if(strData.length() > ((DID_SIZE*2) -1))
					    	{						       
						        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_CALLPICKUP;
					                faultrow++;
			    
					    	}
						else if((atoi(strData.c_str())  < 1)   ||  (atoi(strData.c_str())  > 32 ))
					    	{						       
						        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_CALLPICKUP;
					                faultrow++;
			    
					    	}
						
						
					        delete[] tmpNumbers;
					}	
				
				}				

								
				//----------------------------ACCESS ------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[9].namedcell) ==0 )  &&  ( strcmp(strData.c_str(),xmlStationsNameTable[9].headerrecord)!=0) )
				{
					if ( strcmp(strData.c_str(),"empty") != 0 )
					{	
					     faults[0][0]++;
					     faults[faultrow][0]=1;
		   			     faults[faultrow][1]=numStations+3;
					     faults[faultrow][2]=WRONG_ACCESS_TYPE;
					     faultrow++;
					}										
					
				}
				//--------------------------END --ACCESS ------------------------------------------------------


				//----------------------------Voicemail ------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[10].namedcell) ==0 )  &&  ( strcmp(strData.c_str(),xmlStationsNameTable[10].headerrecord)!=0) )
				{
					if(blHasEvm)
					{
						
						if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)   )
						{	
						     //ninthEmpty = true;
						}
					
						else
						{
							if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))							     
							{	
							    faults[0][0]++;
			      				    faults[faultrow][0]=1;
		   					    faults[faultrow][1]=numStations+3;
						            faults[faultrow][2]=WRONG_VOICEMAIL_FORMAT;
						            faultrow++;

							}
						}
						
					}
					else
					{
						/*
						if ( strcmp(strData.c_str(),"empty") != 0 )
						{	
					     		faults[0][0]++;
					     		faults[faultrow][0]=1;
		   			     		faults[faultrow][1]=numStations+3;
					     		faults[faultrow][2]=WRONG_VOICEMAIL_FORMAT;
					     		faultrow++;
						}	
						*/
														
					}
					
				}
				//--------------------------END --Voicemail ------------------------------------------------------
				
				//----------------------------EMAIL ------------------------------------------------------				
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[11].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[11].headerrecord)!= 0
				 )  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)   )
					{	
					     tenthEmpty = true;
					}
					
					else
					{
						
						findTenth=true;	
						
						tmpNumbers = new char[strData.length()+1];  
						strcpy(tmpNumbers,strData.c_str());
						//strncpy(tmpNumbers,strData.c_str(),strData.length()-1);

						if( !checkvalidmail(tmpNumbers) )
						{	
						    faults[0][0]++;
		      				    faults[faultrow][0]=1;
	   					    faults[faultrow][1]=numStations+3;
					            faults[faultrow][2]=INVALID_EMAIL;
					            faultrow++;

						}
						else if(strData.length() >  MAX_EMAIL )
						{
						    faults[0][0]++;
		      				    faults[faultrow][0]=1;
	   					    faults[faultrow][1]=numStations+3;
					            faults[faultrow][2]=INVALID_EMAIL;
					            faultrow++;		
						}						
						delete [] tmpNumbers;
					}
					
					
				}
				//--------------------------END --EMAIL ------------------------------------------------------

				//----------------------------MOBILE  ------------------------------------------------------				
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[12].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[12].headerrecord)!= 0
				 ) )
				 //) && (strData !="empty") )

				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     eleventhEmpty = true;
					}
					else
					{
						findEleventh=true; 
						
						tmpNumbers = new char[strData.length()+1];  
						//strncpy(tmpNumbers,strData.c_str(),strData.length()-1);
						strcpy(tmpNumbers,strData.c_str());

						if( !checkvalidnumber(tmpNumbers) )
						{					    							    
						    faults[0][0]++;
		      				    faults[faultrow][0]=1;
	   					    faults[faultrow][1]=numStations+3;
					            faults[faultrow][2]=INVALID_MOBILE;
					            faultrow++;	
						}
						else if(strData.length() > MAX_MOBILE)
						{
						    faults[0][0]++;
		      				    faults[faultrow][0]=1;
	   					    faults[faultrow][1]=numStations+3;
					            faults[faultrow][2]=INVALID_MOBILE;
					            faultrow++;	
						
						}
						delete [] tmpNumbers;
					}
					
					
				}
				//--------------------------END --MOBILE  ------------------------------------------------------

				//----------------------------NODE  ------------------------------------------------------				
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[13].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[13].headerrecord)!= 0
				 ) )
				{										
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     twelvthEmpty = true;
					}
					else
					{
						findTwelvth=true; 
						if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{
							faults[0][0]++;
			      				faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=INVALID_NODEID;
						        faultrow++;
						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						        faults[0][0]++;
			      				faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=INVALID_NODEID;
						        faultrow++;
						}
						else if( strData.length() > 4 )
						{
						   	faults[0][0]++;
			      				faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=INVALID_NODEID;
						        faultrow++;
						}
					}
					
					
				}
				//--------------------------END --NODE   ------------------------------------------------------
				
				//---------------------------- SECONDARY GATEWAY  ------------------------------------------------------				
				else if( ( strcmp(strCell.c_str(),xmlStationsNameTable[14].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[14].headerrecord)!= 0 ) )
				{
					
					
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)   )
					{	
					     therteenthEmpty = true;					
					}					
					else 
					{
					    findTherteenth=true;
					    
					    if ( (atoi(strData.c_str()) == 0)  && ( (strData !="0") && (strData!="empty"))  )
					    { 
						faults[0][0]++;
			      			faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_SECGW;
						faultrow++;
					    }
				            else  if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
					    {
						faults[0][0]++;
			      			faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_SECGW;//INVALID_SECGW
						faultrow++;
					    }
					    else if( strData.length() > 4 )
 					    {
						faults[0][0]++;
			      			faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_SECGW;//INVALID_SECGW
						faultrow++;
					    }
					}


				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					/*		
					if(!findFirst)
						numStations++;
					*/

					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) && (fourthEmpty) && (fifthEmpty) && (sixthEmpty) && (seventhEmpty) && (eighthEmpty)&& (ninthEmpty)&&(tenthEmpty) &&(eleventhEmpty) &&
					(twelvthEmpty)   &&  (therteenthEmpty) )
					{
					    blStations = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
					    fourthEmpty=false;
					    fifthEmpty=false;
					    sixthEmpty=false;
					    seventhEmpty=false;
					    eighthEmpty=false;	
					    ninthEmpty=false; tenthEmpty=false; eleventhEmpty=false; twelvthEmpty=false; therteenthEmpty=false;					    
					    block =0;
					    record = 0;					    
				        }
					
					
					if( (findFirst) && (findSecond) && (findThird)  && (findFourth) && (findFifth) && (findSixth) && (findSeventh) && (findEighth) && (findNinth)&&(findTenth) &&(findEleventh) &&
					(findTwelvth)   &&  (findTherteenth) )
					{
						findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false;
						findEleventh=false; findTwelvth=false; findTherteenth=false;
					} 
					else if( (findFirst)  && (!findFourth) )
					{
						faults[0][0]++;
						faults[faultrow][0]=1;
	   					faults[faultrow][1]=numStations+2;
					        faults[faultrow][2]=STN_TYP_UNKNOWN;
					        faultrow++;	
					}
					else if( (!findFirst) &&  ((findSecond) || (findThird)  || (findFourth) || (findFifth) || (findSixth) || (findSeventh) || (findEighth) || (findNinth) || (findTenth) || (findEleventh) ||
					(findTwelvth) ||(findTherteenth)) )
					{					    
					    
					    faults[0][0]++;
			      		    faults[faultrow][0]=1;
		   			    faults[faultrow][1]=numStations+3;
					    faults[faultrow][2]=CALL_NO_MISSING;
					    faultrow++;
					}
											
					if( ((findSixth)    &&   (!findFifth))  ||    ((findTherteenth)    &&   (!findFifth))  )
					{
						faults[0][0]++;
						faults[faultrow][0]=1;
	   				        faults[faultrow][1]=numStations+3;
					        faults[faultrow][2]=MISSING_FAX_CALLNO;
					        faultrow++;
					}
					
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) && (!findFifth) && (!findSixth)  && (!findSeventh) && (!findEighth) && (!findNinth)&&(!findTenth) &&(!findEleventh) &&
					(!findTwelvth)   &&  (!findTherteenth) )
					{
					    //blStations = false;
					    numStations = numStations;
					}
					else
						numStations++;
					
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;findTherteenth=false;								
					firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;twelvthEmpty=false;therteenthEmpty=false;									
					
					//numStations++;
				}
				
								

			} // END if(blStations)
//---------------------------------------------- END STATIONS--------------------------------------------------------------------------------------------------------------			

                         




			
//----------------------------------------------- LICENSES START----------------------------------------------------------------------------------------------------------			
			else if((blLicenses)  && (block >0))
			{
				
				
				//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[0].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[0].headerrecord) != 0 ))
				//if( (strCell=="licinternumber")  &&  (strData !="Internal number") && (strData !="empty") )
				{
					
					//numLicenses++;
					
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if LIC Internal Number Is Emprty 
					{										   
					     firstEmpty = true;
					    
					}
					else // Check If Valid Call Number 
					{
					    
					    findFirst=true; 
					   
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]=LIC_TYPE_NOT_SUPPORTED;
					       faultrow++;				    
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]=LIC_TYPE_NOT_SUPPORTED;
					       faultrow++;				    
					    }

					    delete [] tmpNumbers;
					}     

				        numberoflines++;
										
					
				}
				//--------------------------------USER TYPE------------------------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[1].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[1].headerrecord) != 0 ))
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     if(findFirst)
					    {
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]=LIC_TYP_USTYP;
					       faultrow++;	
					    }
					    
					}
					else
					{ 	
     					    
					    findSecond=true; 					    					    
					    	if( !LXCheckLicenseUserType(strData.c_str()) )
					    	{						    					    
						    faults[0][0]++;
	  			      	    	    faults[faultrow][0]=2;
			   			    faults[faultrow][1]=numLicenses+3;
						    faults[faultrow][2]=LIC_TYP_USTYP;
					    	    faultrow++;
						    }					    
					
					}
					
							
				}
				
				//------------------------------VOICEMAIL -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[2].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[2].headerrecord) != 0 ))
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if LIC Internal Number Is Emprty 
					{										   
					     secondEmpty = true;
					    
					}
					else
					{ 	
					     findThird=true; 
					     
					     if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))							     
					     {
				       
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]=LIC_TYP_VCMAIL;
					       faultrow++;				    
					     }
					
					}	
								
				}
				//------------------------------GROUP WARE USER-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[3].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[3].headerrecord) != 0 ))
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     thirdEmpty = true;	
					}			
					else
					{ 	
					     findFourth=true; 
					     
					     if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					     {										
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]=LIC_TYP_GRWAREUS;
					       faultrow++;				    
					     }
					
					}					
				}
				//------------------------------UC USER-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[4].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[4].headerrecord) != 0 ))
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     fourthEmpty = true;
					    
					}
					else
					{ 	
					     findFifth=true; 
					     if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					     {
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]= LIC_TYP_UCUSER;
					       faultrow++;				    
					     }
					
					}
									
									
				}
				//------------------------------UCE FAX-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[5].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[5].headerrecord) != 0 ))
				{
					if ( strcmp(strData.c_str(),"empty") == 0 )
					{										   
					     fifthEmpty = true;
					    
					}
					else
					{ 	
					     findSixth=true; 
					     
					     if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					     {
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]= LIC_TYP_UCFAX;
					       faultrow++;				    
					     }
					
					}
									
									
				}
				//------------------------------UC CONFERENCE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[6].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[6].headerrecord) != 0 ))
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     sixthEmpty = true;
					}
					else
					{ 	
					     findSeventh=true; 
					     if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					     {
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]= LIC_TYP_UCCONF;
					       faultrow++;				    
					     }
					
					}									
				}
				//------------------------------MY ATTENDAND-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[7].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[7].headerrecord) != 0 ))
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if LIC Internal Number Is Emprty 
					{										   
					     seventhEmpty = true;
					}
					else
					{ 	
					    findEighth=true;
					    
					     if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					     {
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]= LIC_TYP_MYATTEND ;
					       faultrow++;				    
					     }
					
					}
																		
				}
				//------------------------------MY AGENT-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[8].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[8].headerrecord) != 0 ))
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if LIC Internal Number Is Emprty 
					{										   
					     eighthEmpty = true;
					}
					else
					{ 	
					     findNinth=true;
					     
					     if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					     {
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]=LIC_TYP_MYAGENT ;
					       faultrow++;				    
					     }
					
					}				
					 				
				}
				/*/------------------------------SOCIAL MEDIA -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[9].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[9].headerrecord) != 0 ))
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if LIC Internal Number Is Emprty 
					{										   
					     ninthEmpty = true;
					}
					else
					{ 	
					     findTenth=true;	
					     if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					     {
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]= LIC_TYP_SOCMEDIA ;
					       faultrow++;				    
					     }
					
					}				
					 				
				}
				*/
				//------------------------------APPLICATION LAUNCHER-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[9].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[9].headerrecord) != 0 ))
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if LIC Internal Number Is Emprty 
					{										   
					     ninthEmpty = true;
					}
					else
					{ 	
					     findEleventh=true; 

					     if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					     {
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]= LIC_TYP_APPLAUNCH;
					       faultrow++;				    
					     }
					
					}
				}

				//------------------------------TAPI-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[10].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[10].headerrecord) != 0 ))
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if LIC Internal Number Is Emprty 
					{										   
					     tenthEmpty = true;
					}
					else
					{ 	
					     findEleventh=true; 



					     if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					     {
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]= LIC_TYP_TAPI ;
					       faultrow++;				    
					     }
					
					}				
									
				}
				//-------------------------------SMART UC-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[11].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[11].headerrecord) != 0 ))
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if LIC Internal Number Is Emprty 
					{										   
					     tenthEmpty = true;
					}
					else
					{ 	
					     findTwelvth=true;
					     if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					     {
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]= LIC_TYP_SMARTUC ;
					       faultrow++;				    
					     }
					
					}
									
									
				}
				
			        //------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlLicensesNameTable[12].namedcell) == 0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[12].headerrecord) != 0 ))
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  ) // Check if LIC Internal Number Is Emprty 
					{										   
					        eleventhEmpty = true;
					}
					else 
					{
						if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{
							faults[0][0]++;
			      				faults[faultrow][0]=2;
		   					faults[faultrow][1]=numLicenses+3;
						        faults[faultrow][2]=INVALID_NODEID;
						        faultrow++;
						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						        faults[0][0]++;
			      				faults[faultrow][0]=2;
		   					faults[faultrow][1]=numLicenses+3;
						        faults[faultrow][2]=INVALID_NODEID;
						        faultrow++;
						}
						else if( strData.length() > 4 )
						{
						   	faults[0][0]++;
			      				faults[faultrow][0]=2;
		   					faults[faultrow][1]=numLicenses+3;
						        faults[faultrow][2]=INVALID_NODEID;
						        faultrow++;
						}					
						findTwelvth=true;							
					}
					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					
					
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) && (!findFifth) && (!findSixth)  && (!findSeventh) && (!findEighth) && (!findNinth) && (!findTenth) && (!findEleventh) && (!findTwelvth)  )
					{
					    //blLicenses = false;
					    numLicenses = numLicenses;
					}
					else
					   numLicenses++; 
					
					
					
					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) && (fourthEmpty) && (fifthEmpty) && (sixthEmpty) && (seventhEmpty) && (eighthEmpty) 
					&&(ninthEmpty) &&(tenthEmpty) &&(eleventhEmpty) )
					{
						blLicenses = false;
					}
					
					
					if( (findFirst) && (findSecond) && (findThird)  && (findFourth) && (findFifth) && (findSixth) && (findSeventh) && (findEighth) && (findNinth) && (findTenth) && (findEleventh) && (findTwelvth) )
					{
						findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
					} 
					else if( (!findFirst) &&  ((findSecond) || (findThird)  || (findFourth) || (findFifth) || (findSixth) || (findSeventh) || (findEighth) || (findNinth) || (findTenth) || (findEleventh) || (findTwelvth) ) )
					{	
//					       numLicenses++;
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]=CALL_NO_MISSING;
					       faultrow++;
					}					
					else if( (findFirst) &&  (!findSecond) )
					{	
					       faults[0][0]++;
				      	       faults[faultrow][0]=2;
		   			       faults[faultrow][1]=numLicenses+3;
					       faults[faultrow][2]=LIC_TYP_USTYP; //LIC_TYP_UCUSER;
					       faultrow++;	
					}
					
					
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;					
					firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;
					
				}
				

			} // END blLicenses
//----------------------------------------------- LICENSES END----------------------------------------------------------------------------------------------------------						


//-----------------------------------------------GROUPS START-----------------------------------------------------------------------------------------------------------			
			else if( blGroups )
			{				
				//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlGroupsNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[0].headerrecord)!= 0 ) )
				{
					//numGroups++;
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if GRoup Internal Number Is Emprty 
					{										   
					     firstEmpty = true;	
					     //numGroups--;			    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true; 
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {					       
					       faults[0][0]++;
				      	       faults[faultrow][0]=3;
		   			       faults[faultrow][1]=numGroups+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					       faults[0][0]++;
				      	       faults[faultrow][0]=3;
		   			       faults[faultrow][1]=numGroups+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
					    }
					    else
					    {
					    

					     

					    
					    }					    					    		

					    delete [] tmpNumbers;
					}     	
					numberoflines++;
					
					
				}
				//------------------------------DID NUMBER -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlGroupsNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[1].headerrecord)!= 0 ) )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  ) // Check if GRoup Internal Number Is Emprty 
					{										   
					     secondEmpty = true;
				    
					}
					else // Check If Valid Call Number 
					{
					    findSecond=true; 
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
				               faults[0][0]++;
				      	       faults[faultrow][0]=3;
		   			       faults[faultrow][1]=numGroups+3;
					       faults[faultrow][2]=INVALID_DUWA;
					       faultrow++;
					    }
					    else if (strData.length() > ((DID_SIZE*2) -1) )
		   			    {
				               faults[0][0]++;
				      	       faults[faultrow][0]=3;
		   			       faults[faultrow][1]=numGroups+3;
					       faults[faultrow][2]=INVALID_DUWA;
					       faultrow++;
					    }
					    else
					    {
					     	
							 
					    }
					    
					    
					    delete [] tmpNumbers;
					}    
					 	
				}
				//------------------------------DISPLAY NAME -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlGroupsNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[2].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}
					else 
					{
						if(strData.length() >  (TLN_NAME_SIZE+1))
						{
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=INVALID_NAME;
						       faultrow++;
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=INVALID_NAME;
						       faultrow++;	
						}
						findThird=true; 
					}
					
				}
				//------------------------------Voicemail -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlGroupsNameTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[3].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}
					else 
					{							
					       faults[0][0]++;
				      	       faults[faultrow][0]=3;
		   			       faults[faultrow][1]=numGroups+3;
					       faults[faultrow][2]=WRONG_VOICEMAIL_FORMAT;
					       faultrow++;

						findThird=true; 
					}
					
				}
				//------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlGroupsNameTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[4].headerrecord)!= 0)  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     fourthEmpty = true;
					}					
					else 
					{
						if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{	       
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;						       
	
						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;						       
						}
						else if ( strData.length() > 4) 
						{
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;						       
						}
					
						findFourth=true; 
					}
					
					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) )
					{
					   // blGroups = false;
					   numGroups=numGroups;
					}
					else
					   numGroups++;


					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) && (fourthEmpty) )
					{
					    blGroups = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
					    fourthEmpty=false;
				        }
					if( (findFirst) && (findSecond) && (findThird)  && (findFourth)  )
					{
						findFirst=false; findSecond=false; findThird=false; findFourth=false; 
					} 
					else if( (!findFirst) &&  ((findSecond) || (findThird)  || (findFourth) ) )
					{	
						faults[0][0]++;
				      	    	faults[faultrow][0]=3;
		   			    	faults[faultrow][1]=numGroups+3;
					    	faults[faultrow][2]=CALL_NO_MISSING;
					    	faultrow++;					
					}
					
					   
					firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;

					
				}
				
								
			}// END blGroups
			
//-----------------------------------------------GROUPS END-----------------------------------------------------------------------------------------------------------						
			
//-----------------------------------------------VIRTUAL START-----------------------------------------------------------------------------------------------------------									
			
			else if( (blVirtual)  && (block>0))
			{

	  			//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlVirtualNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[0].headerrecord)!= 0 ) )
				{
					//numVirtual++;
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     firstEmpty = true;	
					     //numVirtual--;			    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true;   
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
				           	faults[0][0]++;
				      	    	faults[faultrow][0]=4;
		   			    	faults[faultrow][1]=numVirtual+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;						       					    
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					        faults[0][0]++;
				      	    	faults[faultrow][0]=4;
		   			    	faults[faultrow][1]=numVirtual+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;	
					    
					    }
					    else
					    {

						    

					    }
					    					    
					    delete [] tmpNumbers;
					}
					   	
					numberoflines++;
				}
				//------------------------------DID NUMBER -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVirtualNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[1].headerrecord)!= 0 ) )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  ) // Check if GRoup Internal Number Is Emprty 
					{										   
					     secondEmpty = true;
				    
					}
					else // Check If Valid Call Number 
					{
					    findSecond=true;  
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
					        faults[0][0]++;
 			      	    		faults[faultrow][0]=4;
		   			    	faults[faultrow][1]=numVirtual+3;
					    	faults[faultrow][2]=INVALID_DUWA;
					    	faultrow++;
	
					    }
					    else if (strData.length() > ((DID_SIZE*2) -1) )
					    {
					        faults[0][0]++;
 			      	    		faults[faultrow][0]=4;
		   			    	faults[faultrow][1]=numVirtual+3;
					    	faults[faultrow][2]=INVALID_DUWA;
					    	faultrow++;
					    }
					    else
					    {
					    	
					    }					    					    
					    
					    delete [] tmpNumbers;
					}    
						
				}
				//------------------------------DISPLAY NAME -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVirtualNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[2].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}
					else 
					{
						klen=0;
						klen= my_strlen_utf8_c(strData.c_str());
						if( (strData.length() > (TLN_NAME_SIZE+1))     &&   (klen>TLN_NAME_SIZE ) )
						{
						   faults[0][0]++;
	 			      	    	   faults[faultrow][0]=4;
			   			   faults[faultrow][1]=numVirtual+3;
						   faults[faultrow][2]=INVALID_NAME;
						   faultrow++;	
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
						   faults[0][0]++;
	 			      	    	   faults[faultrow][0]=4;
			   			   faults[faultrow][1]=numVirtual+3;
						   faults[faultrow][2]=INVALID_NAME;
						   faultrow++;		
						}
						findThird=true;
					}
				}
				//----------------------------STATION TYPE ------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVirtualNameTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(),xmlVirtualNameTable[3].headerrecord)!=0) )
				{
					if ( strcmp(strData.c_str(),"empty") == 0 )
					{	
					     fourthEmpty = true;
					}					
					else
					{ 
						if( !CheckStationTypeVirtual(strData.c_str()) ) // ||  (strcmp(strData.c_str(),"empty") == 0) )
						{					    					    
						    faults[0][0]++;
	  			      	    	    faults[faultrow][0]=4;
			   			    faults[faultrow][1]=numVirtual+3;
						    faults[faultrow][2]=STN_TYP_UNKNOWN;
						    faultrow++;
						}
						findFourth=true;
					}
				}
				//------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVirtualNameTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[4].headerrecord)!= 0)  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     fifthEmpty = true;
					}					
					else 
					{
						if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{
						    faults[0][0]++;
  				      	    	    faults[faultrow][0]=4;
			   			    faults[faultrow][1]=numVirtual+3;
						    faults[faultrow][2]=INVALID_NODEID;
						   faultrow++;

						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						    faults[0][0]++;
	  			      	    	    faults[faultrow][0]=4;
		   				    faults[faultrow][1]=numVirtual+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;
						}
						else if(strData.length() > 4)
						{
						    faults[0][0]++;
  			      		    	    faults[faultrow][0]=4;
		   				    faults[faultrow][1]=numVirtual+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;
						}
															
						findFifth=true; 
					}
					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) && (!findFifth)  )
					{
					   // blVirtual = false;
					   numVirtual = numVirtual;
					}
					else
					   numVirtual++;
						
					
					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) && (fourthEmpty) && (fifthEmpty))
					{
					    blVirtual = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
					    fourthEmpty=false;
					    fifthEmpty=false;
				        }
				       /*
				        else if(  (firstEmpty)  && ( (!secondEmpty) || (!thirdEmpty) || (!fourthEmpty)  || (!fifthEmpty)  )  )
				        {
					    faults[0][0]++;
  			      	    	    faults[faultrow][0]=4;
		   			    faults[faultrow][1]=numVirtual+2;
					    faults[faultrow][2]=CALL_NO_MISSING;
					    faultrow++;
					    
					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
					    fourthEmpty=false;
					    fifthEmpty = false;
 				        }
					*/
					if( (findFirst) && (findSecond) && (findThird)  && (findFourth) && (findFifth)  )
					{
						findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; 
					}
					else if(  (findFirst) &&  (!findFourth) )
					{
						 faults[0][0]++;
	  			      	    	 faults[faultrow][0]=4;
			   			 faults[faultrow][1]=numVirtual+3;
						 faults[faultrow][2]=STN_TYP_UNKNOWN;
						 faultrow++;						
					} 
					else if( (!findFirst) &&  ((findSecond) || (findThird)  || (findFourth) || (findFifth)  ) )
					{		
						faults[0][0]++;
  			      	    	   	faults[faultrow][0]=4;
		   			    	faults[faultrow][1]=numVirtual+3;
					   	faults[faultrow][2]=CALL_NO_MISSING;
					   	faultrow++;	
					}
					
					firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
					//numVirtual++;
				}
			

				


			}// END If VIRTUAL
//-----------------------------------------------VIRTUAL END-----------------------------------------------------------------------------------------------------------									
			
//-----------------------------------------------TRUNK GROUPS---------------------------------------------------------------------------------------------------------			
			else if( (blTrunkGroup)  && (block>0))
			{

				//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlTrunkGrpNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlTrunkGrpNameTable[0].headerrecord)!= 0 ) )
				{
					//numTrunkGroups++;
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     firstEmpty = true;	
					    // numTrunkGroups--;			    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true; 
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
						faults[0][0]++;
  			      	    	    	faults[faultrow][0]=5;
		   			    	faults[faultrow][1]=numTrunkGroups+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
						faults[0][0]++;
  			      	    	    	faults[faultrow][0]=5;
		   			    	faults[faultrow][1]=numTrunkGroups+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;
					    }
					    else
					    {

						    
					    					    
					    }
					    
					    delete [] tmpNumbers;
					}     	
					numberoflines++;
					
				}
				//------------------------------DISPLAY NAME -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlTrunkGrpNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlTrunkGrpNameTable[1].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     secondEmpty = true;
					}
					else 
					{
						klen=0;
						klen= my_strlen_utf8_c(strData.c_str());
						if( (strData.length() > (TLN_NAME_SIZE+1))     &&   (klen>TLN_NAME_SIZE ) )
						{
						    faults[0][0]++;
  			      	    		    faults[faultrow][0]=5;
		   				    faults[faultrow][1]=numTrunkGroups+3;
						    faults[faultrow][2]=INVALID_NAME;
						    faultrow++;
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
  			      	    		    faults[faultrow][0]=5;
		   				    faults[faultrow][1]=numTrunkGroups+3;
						    faults[faultrow][2]=INVALID_NAME;
						    faultrow++;	
						}
						findSecond=true;
					}
				}
				//------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlTrunkGrpNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlTrunkGrpNameTable[2].headerrecord)!= 0)  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}					
					else 
					{
						if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{					       
						    faults[0][0]++;
  				      	    	    faults[faultrow][0]=5;
			   			    faults[faultrow][1]=numTrunkGroups+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;					       					       
						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						    faults[0][0]++;
  				      	    	    faults[faultrow][0]=5;
			   			    faults[faultrow][1]=numTrunkGroups+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;					       					       
						}
						else if (strData.length() > 4)
						{
						    faults[0][0]++;
  				      	    	    faults[faultrow][0]=5;
			   			    faults[faultrow][1]=numTrunkGroups+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;					       					       
						}
						findThird=true; 
					}
						
					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) && (!findFifth) && (!findSixth)  && (!findSeventh) && (!findEighth) && (!findNinth) && (!findTenth) && (!findEleventh) && (!findTwelvth)  )
					{
					    numTrunkGroups=numTrunkGroups;
					}
					else
						numTrunkGroups++;
					
					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) )
					{
					    blTrunkGroup = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
				        }
				        /*else if(  (firstEmpty)  && ( (!secondEmpty) || (!thirdEmpty)  )  )
				        {
					    faults[0][0]++;
  			      	    	    faults[faultrow][0]=5;
		   			    faults[faultrow][1]=numTrunkGroups+2;
					    faults[faultrow][2]=CALL_NO_MISSING;
					    faultrow++;					       					       
					    					    
					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
 				        }	
					*/
					if( (findFirst) && (findSecond) && (findThird)  )
					{
						findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
					} 
					else if( (!findFirst) &&  ((findSecond) || (findThird)  ) )
					{	
						faults[0][0]++;
  			      	    	    	faults[faultrow][0]=5;
		   			    	faults[faultrow][1]=numTrunkGroups+3;
					    	faults[faultrow][2]=CALL_NO_MISSING;
					    	faultrow++;					       					       					    				
					}
					
					
					firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
					
				}				
				

			}
			else if( (blVoicemail)  && (block>0))
			{


				//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlVoiceMailNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVoiceMailNameTable[0].headerrecord)!= 0 ) )
				{
					//numVoicemail++;
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     firstEmpty = true;	
					     //numVoicemail--;			    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true; 
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {					       
					       faults[0][0]++;
	  			      	       faults[faultrow][0]=6;
			   		       faults[faultrow][1]=numVoicemail+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					       faults[0][0]++;
	  			      	       faults[faultrow][0]=6;
			   		       faults[faultrow][1]=numVoicemail+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
				            }
					    else
					    {

						    

					    }
					    delete [] tmpNumbers;
					}     	
					numberoflines++;
					
				}
				//------------------------------DISPLAY NAME -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVoiceMailNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVoiceMailNameTable[1].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     secondEmpty = true;
					}
					else
					{
						klen=0;
						klen= my_strlen_utf8_c(strData.c_str());
						if( (strData.length() > (TLN_NAME_SIZE+1))     &&   (klen>TLN_NAME_SIZE ) )
						{
					       		faults[0][0]++;
	  			      	       		faults[faultrow][0]=6;
				   		       	faults[faultrow][1]=numVoicemail+3;
						       	faults[faultrow][2]=INVALID_NAME;
						       faultrow++;
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
	  			      	       		faults[faultrow][0]=6;
				   		       	faults[faultrow][1]=numVoicemail+3;
						       	faults[faultrow][2]=INVALID_NAME;
						       faultrow++;
						}
						findSecond=true; 
					}
				}
				//------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVoiceMailNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVoiceMailNameTable[2].headerrecord)!= 0)  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}					
					else
					{
						 if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{					       
					       		faults[0][0]++;
		  			      	       	faults[faultrow][0]=6;
				   		       faults[faultrow][1]=numVoicemail+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;
						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						       faults[0][0]++;
		  			      	       faults[faultrow][0]=6;
				   		       faults[faultrow][1]=numVoicemail+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;
						}
						else if(strData.length() > 4)
						{
						       faults[0][0]++;
		  			      	       faults[faultrow][0]=6;
				   		       faults[faultrow][1]=numVoicemail+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;
						}
						
						findThird=true; 
					}					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					
					if( (!findFirst) && (!findSecond) && (!findThird) )
					{
						numVoicemail = numVoicemail;
						
					} 
					else
						numVoicemail++;
						
					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) )
					{
					    blVoicemail = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
				        }										
					
					else if( (!findFirst) &&  ((findSecond) || (findThird) ) )
					{		
						faults[0][0]++;
	  			      	  	faults[faultrow][0]=6;
			   		    	faults[faultrow][1]=numVoicemail+3;
					    	faults[faultrow][2]=CALL_NO_MISSING;
					    	faultrow++;		
					}
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;	
					firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;
									
			
						//numVoicemail++;
				}
				
			} // end if voicemail
//-----------------------------------------------SipConfig-----------------------------------------------------------------------------------------------------------									
			
			else if( (blSipConfig)  && (block>0))
			{

	  			//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlSipConfigTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[0].headerrecord)!= 0 ) )
				{
					
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     firstEmpty = true;	
					     		    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true;   
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
				           	faults[0][0]++;
				      	    	faults[faultrow][0]=7;
		   			    	faults[faultrow][1]=numSipConfig+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;						       					    
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					        faults[0][0]++;
				      	    	faults[faultrow][0]=7;
		   			    	faults[faultrow][1]=numSipConfig+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;	
					    
					    }
					    else
					    {
						    
					    }
					    					    
					    delete [] tmpNumbers;
					}
					   	
					numberoflines++;
				}
				//------------------------------Password Sip -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlSipConfigTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[1].headerrecord)!= 0 ) )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  ) // Check if GRoup Internal Number Is Emprty 
					{										   
					     secondEmpty = true;
				    
					}
					else // Check If Valid Call Number 
					{
					    findSecond=true;  
					    klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						   faults[0][0]++;
	 			      	    	   faults[faultrow][0]=7;
			   			   faults[faultrow][1]=numSipConfig+3;
						   faults[faultrow][2]=44;
						   faultrow++;	
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
	 			      	    	   	faults[faultrow][0]=7;
			   			   	faults[faultrow][1]=numSipConfig+3;
						   	faults[faultrow][2]=44;
						   	faultrow++;		
						}
					    // Here will check the type of password					    
					}    
						
				}
				//------------------------------UserId/Username  -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlSipConfigTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[2].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}
					else 
					{

						klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						   faults[0][0]++;
	 			      	    	   faults[faultrow][0]=7;
			   			   faults[faultrow][1]=numSipConfig+3;
						   faults[faultrow][2]=11;
						   faultrow++;	
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
	 			      	    	   	faults[faultrow][0]=7;
			   			   	faults[faultrow][1]=numSipConfig+3;
						   	faults[faultrow][2]=11;
						   	faultrow++;		
						}
						findThird=true;
					}
				}
				//----------------------------Realm ------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlSipConfigTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(),xmlSipConfigTable[3].headerrecord)!=0) )
				{
					if ( strcmp(strData.c_str(),"empty") == 0 )
					{	
					     fourthEmpty = true;
					}					
					else
					{ 						
						klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						   faults[0][0]++;
	 			      	    	   faults[faultrow][0]=7;
			   			   faults[faultrow][1]=numSipConfig+3;
						   faults[faultrow][2]=11;
						   faultrow++;	
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
	 			      	    	   	faults[faultrow][0]=7;
			   			   	faults[faultrow][1]=numSipConfig+3;
						   	faults[faultrow][2]=11;
						   	faultrow++;		
						}   
					  findFourth=true;						
					}
				}
				//------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlSipConfigTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[4].headerrecord)!= 0)  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     fifthEmpty = true;
					}					
					else 
					{
						if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{
						    faults[0][0]++;
  				      	    	    faults[faultrow][0]=7;
			   			    faults[faultrow][1]=numSipConfig+3;
						    faults[faultrow][2]=INVALID_NODEID;
						   faultrow++;

						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						    faults[0][0]++;
	  			      	    	    faults[faultrow][0]=7;
		   				    faults[faultrow][1]=numSipConfig+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;
						}
						else if(strData.length() > 4)
						{
						    faults[0][0]++;
  			      		    	    faults[faultrow][0]=7;
		   				    faults[faultrow][1]=numSipConfig+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;
						}
															
						findFifth=true; 
					}
					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) && (!findFifth)  )
					{
					   // blVirtual = false;
					   numSipConfig = numSipConfig;
					}
					else
					   numSipConfig++;
						
					
					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) && (fourthEmpty) && (fifthEmpty))
					{
					    blSipConfig = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
					    fourthEmpty=false;
					    fifthEmpty=false;
				        }
				       
				}
			

				


			}// END If SipConfig
//-----------------------------------------------SipConfig-----------------------------------------------------------------------------------------------------------			
			
			
		
		}  // END // If the Record is OK
		
	//} //  END BLSTATION 

	
	countLine++;//increase countLines number to numberring Lines   
	
    }// ----end while read lines-------
    
    //delete [] tmpNumbers;
    
    
    type[0] = numStations; // Licenses Number
    type[1] = numLicenses; // Licenses Number
    type[2] = numGroups;   // Group Number
    type[3] = numVirtual;   //  Virtual Number
    type[4] = numTrunkGroups; // Trunk number
    type[5] = numVoicemail;   // Voicemail Number 
	type[6] = numSipConfig;   // Voicemail Number 
    
    if(corXml==0)
    {
	    faults[0][0]++;
	    faults[faultrow][0]=1;
	    faults[faultrow][1]= 0; // invalid Xml with no contents 
	    faults[faultrow][2]=INVALID_FILE_FORMAT;
	    faultrow++;	
    }
    /*
    cout << " ilias numStations= " <<type[0] << endl;     cout << " ilias numLicenses= " <<  type[1]<< endl;    cout << " ilias numGroups= " <<  type[2]<< endl;    cout << " ilias numVirtual= " <<  type[3]<< endl;    cout << " ilias numTrunkGroups= " <<  type[4]<< endl;
    cout << " ilias numVoicemail= " <<  type[5] << endl;         cout << " ilias aults[0][0]= " <<  faults[0][0] << endl;     */

    errorCount = faultrow; 

    fclose(fxml);

    if(faults[0][0]==0)
    return  0; 
    else 
    return errorCount;

}


bool LXwriteXmlStations(char* fname, int numStations)
{
    
char line [128]; 
    FILE *fxml = fopen(fname,"r");
    int fLast,fFirst,intLen,wksFound,findNameCell=0,findCell=0,countLine=0,wksRowFound,fFiltDb=0;
    string tempstr,totalstr,strData,strCell ;  
    bool blStations=false,blCallFun=false;
    int i=0,pos=0,curRecord=0,curNodeAtoi=0;	
    char **stnNumber,**stnDuwa,**stnDisplay,**stnStation,**stnEmail,**stnMobile,**stnNode,**stnGw,**stnFaxCallno,**stnFaxDid, **stnCos, **stnCallPick,**stnFaxName;
    bool  firstEmpty=false,blCellEnd=false,blEndRecord=false;
    int  stSipCounter=0, stUp0Counter=0, stIpCounter=0, stRasCounter=0, stDeskCounter=0, stAnalogIndex=0, stIsdnCounter=0, stDectCounter=0, stRasAdminCounter=0, stRasLicCounter=0;
    long filter=0;	
    RD_KDS_RETURN   kdsreturn;
   // WR_KDS_RETURN   wrreturn;
    char stnrufnr[50];
    int tblSize = 50;// RUFNR_SIZE*2;
    RD_KDS_RETURN	kdsretNode;
    int startIndexSip=0, startIndexIp=0,startIndexRas=0,startIndexDesk=0,wFaxPort=-1;
    bool findFirst=false,findSecond=false,findThird=false,findFourth=false,findFifth=false,findSixth=false,findSeventh=false,findEighth=false,findNinth=false,findTenth=false,findEleventh=false,findTwelvth=false;
  //  DB_OSO_PORTS    write_data; 
    RD_KDS_RETURN   uc_buffer;
   // DB_INHALT_T grp;

        
    stnNumber = new char*[numStations];
    stnDuwa = new char*[numStations];
    stnDisplay = new char*[numStations];
    stnStation = new char*[numStations];
    stnEmail = new char*[numStations];
    stnMobile = new char*[numStations];
    stnNode = new char*[numStations];
    stnGw = new char*[numStations];
    stnFaxCallno= new char*[numStations];
    stnFaxDid= new char*[numStations];
    stnCos=new char*[numStations];
    stnCallPick=new char*[numStations];
    stnFaxName=new char*[numStations]; 
  
    
    for(i=0; i<numStations; i++)
    {	 
	stnNumber[i]= new char[tblSize];
	stnDuwa[i] =new char[tblSize];
    	stnDisplay[i] = new char[tblSize];
    	stnStation[i] = new char[tblSize];
    	stnEmail[i] = new char[MAX_EMAIL];
    	stnMobile[i] = new char[tblSize];
    	stnNode[i] = new char[tblSize];
    	stnGw[i] = new char[tblSize];
	stnFaxCallno[i] = new char[tblSize];
        stnFaxDid[i] = new char[tblSize];
	stnCos[i]=new char[tblSize];
	stnCallPick[i]=new char[tblSize];
	stnFaxName[i]=new char[tblSize];
    }
    
   
  
    for(i=0; i<numStations; i++)
    {	
	for(pos=0; pos<tblSize; pos++)
	{
		stnNumber[i][pos]='\0';
		stnDuwa[i][pos]='\0';
    		stnDisplay[i][pos]='\0';
	    	stnStation[i][pos]='\0';	    	
	    	stnMobile[i][pos]='\0';
	    	stnNode[i][pos]='\0';
	    	stnGw[i][pos]='\0';
		stnFaxCallno[i][pos]='\0';
		stnFaxDid[i][pos]='\0';
		stnCos[i][pos]='\0';
		stnCallPick[i][pos]='\0';
		stnFaxName[i][pos]='\0';
	}
	for(pos=0; pos<MAX_EMAIL; pos++)
	{
	    stnEmail[i][pos]='\0';
	}
    }
    
    
    
    //Db_rddtb(KDS_NODE_ID,KEINE_ZEILE,KEINE_SPALTE,(RD_KDS_RETURN*)&kdsretNode);
    
    while(fgets ( line,128,fxml ) != NULL ) // read a line by line
    {
	
	tempstr=line; // this temp str contains the current line
	intLen = strlen(line);

	//---1-find----WorkSheet name ------------------------------
	wksFound= tempstr.find("Worksheet ss:Name");
	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
	        fFirst= tempstr.find("\"");
	        fLast=tempstr.find_last_of("\"");   
	        tempstr = tempstr.substr(fFirst+1,(fLast-(fFirst+1)));		

		if(tempstr == "Stations")
		{
	   	   blStations = true;
		}
    	}// end worksheet search 

	//---2 find the End of WorkSheet-------------
	wksFound= tempstr.find("</Worksheet>");
	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
		if(blStations)
		{
			blStations = false;
			break;
			//return true;
		}
	}
	
	blEndRecord = false;

	wksFound = tempstr.find("</Data>");
	findNameCell = tempstr.find("<NamedCell");
	findCell = tempstr.find("</Cell>");
	wksRowFound = tempstr.find("</Row>");
	fFiltDb = tempstr.find("FilterDatabase");

	//  CASE  A -- Check if the line is empty, has no data, only namedcell
	if((findNameCell > -1) && (wksFound == -1)  && (fFiltDb==-1) ) 
	{
		fLast = tempstr.find("</Cell>");
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		strData = "empty";
		blEndRecord = true;
	}
	// CASE B scenario we had Data and NameCell Filled in the Same Line 		
	else if( (wksFound > -1) && (findNameCell > -1)  && (findCell >-1) )
	{			
		fLast = tempstr.find("</Cell>");
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		fLast = wksFound;  //tempstr.find("</Data>");
		fFirst = tempstr.rfind("\">");
		strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));
		blEndRecord = true;
	}
	// CASE C -- Has Data and NameCell but the Cell END is in the next Line
	else if( (wksFound > -1) && (findNameCell > -1)  && (findCell == -1) )
	{
		fLast = wksFound;  //tempstr.find("</Data>");
		fFirst = tempstr.rfind("\">");
		strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));
		if(strData.length() == 0 )
				strData = "empty";
		blCellEnd = true; // wait the end of the Cell		
	}
	else if( (findCell > -1) &&  (blCellEnd)  ) // find the end of Cell
	{
		blCellEnd = false;
		fLast = tempstr.find("</Cell>"); 
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		blEndRecord = true;	
	}
	else if(wksRowFound > -1)	
	{
		blEndRecord = true;
		strData = "</Row>";
		strCell="";
	}

	// If the Record is OK
	if(blEndRecord)
	{
//-----------------------STATIONS------------------------------------------------------------------------------------------	    
	    if(blStations)
	    {
		
		
		//---- internal numbers 0 //		//if( (strCell=="internumber")  &&  (strData !="Internal number") && (strData !="empty") )
		if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[0].headerrecord)!= 0 )  )			
		{
			if (strData =="empty")
			{
				firstEmpty=true;
				blStations = false;
			}
			else
			{
				firstEmpty=false;
				strcpy(stnNumber[curRecord],strData.c_str());
				findFirst=true; 
			 }				 
			 		
		}
		//-- DID duwa numbers 1
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[1].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{
			if(findFirst)
			{

				if((strcmp(strData.c_str(),"empty") ==0) ||  (strcmp(strData.c_str(),"-") == 0)    )
					strcpy(stnDuwa[curRecord],"-");
				else	
					strcpy(stnDuwa[curRecord],strData.c_str());
					
				findSecond=true; 
			}
		}
		
		//---Display Numbers	2	
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[2].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{
			if(findFirst)
			{

				if( (strcmp(strData.c_str(),"empty") ==0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					strcpy(stnDisplay[curRecord],"-");
				else			
				        strcpy(stnDisplay[curRecord],strData.c_str());		
				
				findThird=true;
			}
		}		
		
		//------Station Type   3 -----------------------------------
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[3].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				strcpy(stnStation[curRecord],strData.c_str());	
			
				findFourth=true;
			}
		}
		//-----FAX  call  no 4
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[4].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				strcpy(stnFaxCallno[curRecord],strData.c_str());	
			
				findFifth=true;
			}
		}
		//-----FAX DID     5
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[5].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[5].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				strcpy(stnFaxDid[curRecord],strData.c_str());				
			}
		}
		//---FAX NAME
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[6].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[6].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					strcpy(stnFaxName[curRecord],"-");
				else			
				        strcpy(stnFaxName[curRecord],strData.c_str());		
				
			}
		}
		

		//---Class of Service 7
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[7].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[7].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if((strcmp(strData.c_str(),"empty") ==0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					strcpy(stnCos[curRecord],"-1");				
				else
					strcpy(stnCos[curRecord],strData.c_str());				
			}
		}
		
		//---Call PickUp    8
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[8].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[8].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if((strcmp(strData.c_str(),"empty") ==0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					strcpy(stnCos[curRecord],"-1");				
				else
					strcpy(stnCallPick[curRecord],strData.c_str());				
			}
		}
		
		
		//---- ACCESS LEAVE BLANK NO IMPORT DATA FOR LX
		//----VOICEMAIL LEAVE BLANK NO  IMPORT FOR LX
		
		//---Email Address     11
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[11].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[11].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{

				if((strcmp(strData.c_str(),"empty") ==0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					strcpy(stnEmail[curRecord],"");	
				else
				        strcpy(stnEmail[curRecord],strData.c_str());	
				findSixth=true;			
			}
		}
		//---Mobile number     12
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[12].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[12].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if((strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") == 0)  )
					strcpy(stnMobile[curRecord],"");	
				else
					strcpy(stnMobile[curRecord],strData.c_str());	
				findSeventh=true;			
			}
		}
		//---NODE ID  13
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[13].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[13].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{

				if ( (strcmp( strData.c_str(),"empty") ==0) || ( (strcmp(strData.c_str(),"-") == 0) ) )
				  strcpy(stnNode[curRecord],"0");
				else
				 strcpy(stnNode[curRecord],strData.c_str());
	
				findEighth=true; 		 
			}
		}
		//---Secondary Gateway    14
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[14].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[14].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			
			if(findFirst)
			{
				if((strcmp(strData.c_str(),"empty") ==0) || ( (strcmp(strData.c_str(),"-") == 0) ) )
					strcpy(stnGw[curRecord],"");
				else
				
				strcpy(stnGw[curRecord],strData.c_str());							
												
				findNinth=true; 
			}
			
		}
		//------Else if End Row--- The Current Record Finished---------------------------
		else if( strcmp(strData.c_str(),"</Row>")  == 0  )
		{
			if( findFirst) // If has Call Number 
			{
				if(!findSecond) // DID
				   strcpy(stnDuwa[curRecord],"-");
				if(!findThird)   
				   strcpy(stnDisplay[curRecord],"-");
				if(! findSixth)   
				  strcpy(stnEmail[curRecord],"");	
				if(! findSeventh)   
				  strcpy(stnMobile[curRecord],"");	
				if(!findEighth)
				  strcpy(stnNode[curRecord],"0");
				//if(!findEighth)
				//  strcpy(stnGw[curRecord],"0");
				if(!findFifth)
				strcpy(stnFaxCallno[curRecord],"empty");	
							
				
				curRecord++; 
			}			
			findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
		}
	


	      }//  END BLSTATION 
//-----------------------END STATIONS------------------------------------------------------------------------------------------	    

	      	
	} //end If blEndRecord
		

	countLine++;//increase countLines number to numberring Lines   
	
    }  // ----end while read lines-------
    
    cout << "  ilias diavase ta Stations Go to write " <<endl;
    fclose(fxml);
    int k=0;

	for(i=0;  i<numStations;  i++)
	{

	    //
	}
	
	// delete memories
	
    
    	for(i=0;i<numStations;i++)
   	{
		delete []stnNumber[i];
		delete []stnDuwa[i];
		delete []stnDisplay[i];
		delete []stnStation[i];
		delete []stnEmail[i];
		delete []stnMobile[i];
		delete []stnNode[i];
		delete []stnGw[i];	
		delete []stnFaxCallno[i];	
		delete []stnFaxDid[i];	
		delete []stnCos[i];
		delete []stnCallPick[i];
		delete []stnFaxName[i];
	}

    	
        
	delete []stnNumber;
	delete []stnDuwa;
	delete []stnDisplay;
	delete []stnStation;
	delete []stnEmail;
	delete []stnMobile;
	delete []stnNode;
	delete []stnGw;	    
	delete []stnFaxCallno;
	delete []stnFaxDid;
	delete []stnCos;
        delete []stnCallPick;	
	delete []stnFaxName;

	return true;

}
       

void LXfpreadxml(char* fname, int faults[21][3])
{

    char line [128]; 
    FILE *fxml = fopen(fname,"r");
    int fLast,fFirst,intLen,wksFound,findNameCell=0,findCell=0,countLine=0,wksRowFound,fFiltDb=0;
    string tempstr,totalstr,strData,strCell ;  
    bool blStations=false,blLicenses=false,blGroups=false,blVirtual=false,blTrunkGroup=false,blVoicemail=false,blCellEnd=false,blEndRecord=false,firstEmpty=false,blSipConfig=false,blwritexmlSipConfig=false;
    int i=0,pos=0,numberoflines=0,returnvalue=0,isumNodeStVir=0;	
    char **stnNumber,**stnDuwa,**stnNode,**stnLicnum, **stnStType,**stnStTypeNode, **stnFaxCallno, **stnFaxDid,**stnAllStations, **stnAllFaxes,**stnSipStations,**stnSipConfig;
    int dublicatepos[20];
    int faultrow=0;
    int arrayNumRecords[7];   
    int num_count=0, duwa_count=0, node_count=0,lic_count=0,stType_count=0, stTypeNode_count=0, ifaxCallnoCount=0, ifaxDidCount=0,icountAllst=0,icountAllFax=0,icountSip=0,icountSipConfig=0;  
    int numStation=0,numLic=0,numGroup=0,numVirtual=0,numTrnk=0,numVoicemail=0,numSipConfig=0;
    int curNode=0, countNodeTrunksGr=0,countNodeVoicemail=0,countNodeGroups=0;
    RD_KDS_RETURN	kdsretNode;
    int  stSipCounter=0, stSipFaxCounter=0, stUp0Counter=0, stIpCounter=0, stRasCounter=0, stDeskCounter=0, stabFaxCounter=0, stabCounter=0, stIsdnCounter=0, stDectCounter=0, stRasAdminCounter=0, stRasLicCounter=0;
    int syscountUp0=0,syscountAn=0,syscountDect=0,syscountIsdn=0; 
    int syscountPark=0, syscountConf=0,syscountAutoAt=0, syscountCCFax=0, sysCountFaxGroup=0,sysCountVirtual=0,sysCountMeetMe=0;
    bool findFirst=false,findSecond=false,findThird=false,findFourth=false,findFifth=false,findSixth=false,findSeventh=false,findEighth=false,findNinth=false,findTenth=false,findEleventh=false,findTwelvth=false;
    double div=0;
    
    // Test The Function 
    /* The Function Find the Numbers of Record Per Worksheet, then will Fill the Table Type with corresponding data
    Type    	search string     returns Number Of Entries
    [0]		"Stations"     
    [1]		"Licenses"
    [2]		"Groups"
    [3]		"Virtual"
    [4]		"Trunk Groups"
    [5]		"Voicemail"      
         

*/    

  
   
    for(i=0;i<21;i++)
    {
	for(pos=0;pos<3;pos++)
		faults[i][pos]=0;
    }

   //--- Check if The File Extension Is .xml
   

   returnvalue = compare_extension(fname,".xml" );
   if(returnvalue ==0)
   {  	
	faults[0][0]++;
	faults[faultrow+1][0]=1;	// invalid file format 
	faults[faultrow+1][1]=999;	
	faults[faultrow+1][2]=INVALID_FILE_FORMAT;	
	faultrow++;
	fclose(fxml);
			
	return;			
    }
    else 
       returnvalue = 0;
   
   
 
  //-------------------------CHECK THE NUMER OF RECORDS AND THE VALIDATION-------------------	
    returnvalue = LXWorkSheetRecords(fname,arrayNumRecords,faultrow,faults); // ) no fault , 1 there are faults

    if(returnvalue > 1)
    {    	
	fclose(fxml);
	return;
    }    
    else 
    faultrow++;

   	
   // 	faultrow++; // ++ the faultrow in order to start with the next error
    /*	
    printf("\n ilias Station (arrayNumRecords[%d])=%d",0,arrayNumRecords[0]);
    printf("\n ilias Licenses(arrayNumRecords[%d])=%d",1,arrayNumRecords[1]);
    printf("\n ilias Groups(arrayNumRecords[%d])=%d",2,arrayNumRecords[2]);
    printf("\n ilias Virtual(arrayNumRecords[%d])=%d",3,arrayNumRecords[3]);
    printf("\n ilias Trunk Groups(arrayNumRecords[%d])=%d",4,arrayNumRecords[4]);
    printf("\n ilias Voicemail(arrayNumRecords[%d])=%d",5,arrayNumRecords[5]);
    */
    
    //Db_rddtb(KDS_NODE_ID,KEINE_ZEILE,KEINE_SPALTE,(RD_KDS_RETURN*)&kdsretNode);
    
    numStation = arrayNumRecords[0] ;
    numLic = arrayNumRecords[1] ; 
    numGroup = arrayNumRecords[2];
    numVirtual = arrayNumRecords[3];
    numTrnk = arrayNumRecords[4];
    numVoicemail = arrayNumRecords[5];
    numSipConfig = arrayNumRecords[6];
    //printf("\n ilias numStation=%d, numLic=%d, numGroup=%d,  numVirtual=%d,numTrnk=%d,  numVoicemail=%d ",numStation,numLic,numGroup,numVirtual,numTrnk,numVoicemail);
    //printf("\n ilias SumNumber=%d , Sum_Lic=%d ",(numStation+numGroup+numVirtual+numTrnk+numVoicemail), numLic);
   
      
    stnNumber = new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic]; 
    stnDuwa   = new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic];
    stnNode   = new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic];
    stnLicnum = new char*[numLic];
    stnStType = new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic]; 
    stnStTypeNode= new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic]; 
    stnFaxCallno= new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic]; 
    stnFaxDid= new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic]; 
    
    stnAllStations=new char*[numStation*2];
    stnAllFaxes=new char*[numStation*2];
    
    /*----------------------sip config --------------------*/
    stnSipStations=new char*[numStation+1];
    stnSipConfig=new char*[numSipConfig+1];
    
    
    for(i=0;  i<numStation+1; i++)
    {
    	stnSipStations[i]=new char[(RUFNR_SIZE*2)+1];
    }
    for(i=0;  i<numSipConfig+1; i++)
    {
    	stnSipConfig[i]=new char[(RUFNR_SIZE*2)+1];
    }
    /*-----------------------------------------------*/
	
    
    for(i=0; i<(numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic); i++)
    {
	stnNumber[i]=new char[(RUFNR_SIZE*2)+1];
	stnDuwa[i]=new char[(RUFNR_SIZE*2)+1];
	stnNode[i]=new char[(RUFNR_SIZE*2)+1];
	stnStType[i]=new char[(RUFNR_SIZE*2)+1];
	stnStTypeNode[i]=new char[(RUFNR_SIZE*2)+1];
	stnFaxCallno[i]=new char[(RUFNR_SIZE*2)+1];
	stnFaxDid[i]=new char[(RUFNR_SIZE*2)+1];
    }
    
     for(i=0; i<numStation*2; i++)
    {
    stnAllStations[i]=new char[(RUFNR_SIZE*2)+1];
    stnAllFaxes[i]=new char[(RUFNR_SIZE*2)+1];
    }
    
    
    
    for(i=0; i<numLic; i++)
    {
        stnLicnum[i] = new char[(RUFNR_SIZE*2)+1];	
    }
    
    
    for(i=0;i<(numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic);i++)
    {
	for(pos=0;pos<RUFNR_SIZE*2;pos++)
	{
		stnNumber[i][pos]='\0';
		stnDuwa[i][pos]='\0';
		stnNode[i][pos]='\0';
		stnStType[i][pos]='\0';
		stnStTypeNode[i][pos]='\0';
		stnFaxCallno[i][pos]='\0';
		stnFaxDid[i][pos]='\0';
	}
    }
    
    for(i=0; i<numStation*2; i++)
    {
	stnAllStations[i][pos]='\0';
	stnAllFaxes[i][pos]='\0';
    }
    
    
    for(i=0;i<numLic;i++)
    {
	for(pos=0;pos<RUFNR_SIZE*2;pos++)
	{
		stnLicnum[i][pos]='\0';
	}
    }
    
    
    for(i=0;i<(numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic);i++)
    {
	strcpy(stnNumber[i],"empty");
	strcpy(stnDuwa[i],"empty");
	strcpy(stnNode[i],"empty");
	strcpy(stnStType[i],"empty");	
	strcpy(stnStTypeNode[i],"empty");
	strcpy(stnFaxCallno[i],"empty");	
	strcpy(stnFaxDid[i],"empty");	
    }
    
    for(i=0; i<numStation*2; i++)
    {
	strcpy(stnAllStations[i],"");
	strcpy(stnAllFaxes[i],"");
    }
    
  //-------------------------CHECK THE NUMER OF RECORDS AND THE VALIDATION-------------------	
    
    // -- Prepei na mpoun edo kai Safe Conditions an Skasei        
    while(fgets ( line,128,fxml ) != NULL ) // read a line by line
    {
	
	tempstr=line; // this temp str contains the current line
	intLen = strlen(line);

	//---1-find----WorkSheet name ------------------------------
	wksFound= tempstr.find("Worksheet ss:Name");
	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
	        fFirst= tempstr.find("\"");
	        fLast=tempstr.find_last_of("\"");   
	        tempstr = tempstr.substr(fFirst+1,(fLast-(fFirst+1)));		


		if(tempstr == "Stations")
	   	   blStations = true;
		else if(tempstr =="Licenses")
		   blLicenses = true; 	
		else if(tempstr =="Groups")		
		   blGroups = true;		    
		else if(tempstr =="Virtual")		
		   blVirtual = true;
		else if(tempstr =="Trunk Groups")
		   blTrunkGroup = true;		
		else if(tempstr =="Voicemail")	
		   blVoicemail = true;		
		else if(tempstr == "SipConfig")
		  blSipConfig = true;		      
    	}// end worksheet search 

	//---2 find the End of WorkSheet-------------
	wksFound= tempstr.find("</Worksheet>");
	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
		if(blStations)
		{
			blStations = false;
		}
		else if(blLicenses)
		{
			blLicenses = false;
		}
		else if(blGroups)
		{
			blGroups = false;
		}
		else if(blVirtual)
		{
			blVirtual = false;
		}
		else if(blTrunkGroup)
		{
			blTrunkGroup = false;
		}
		else if(blVoicemail)
		{
			blVoicemail = false;
		}
		else if(blSipConfig)
		{
		    blSipConfig = false;
		}
	}

	// We read the Xml file Line to Line 	
	// We search for the following KLeywords in order to Find the Data and the Name of these.
	// "</Data>"  means that the Cell in Xml file has data it's  not empty
	// "</NamedCell>"  is the name of the Cell   e.x Didnumber
	// "</Cell>"  end of Cell 
	
	// CASE  A no data only namecell	
	// 	<Cell ss:StyleID="s38"><NamedCell ss:Name="gateway"/></Cell>  
	
        // CASE B in same Line all Data	
	//  	<Cell ss:Index="2" ss:StyleID="s30"><Data ss:Type="Number">102</Data><NamedCell ss:Name="stinternalnum"/></Cell> 
	
	/// CASE C we have the Data but the Name of the Cell ends in the Next Line
	//   <Cell ss:StyleID="s38"><Data ss:Type="String">ilias.mamalis@siemens-enterprise.com</Data><NamedCell 
	//        ss:Name="emailaddr"/></Cell>
	
	blEndRecord = false;

	wksFound = tempstr.find("</Data>");
	findNameCell = tempstr.find("<NamedCell");
	findCell = tempstr.find("</Cell>");
	wksRowFound =  tempstr.find("</Row>");
	fFiltDb = tempstr.find("FilterDatabase");

	//  CASE  A -- Check if the line is empty, has no data, only namedcell
	if((findNameCell > -1) && (wksFound == -1)  && (fFiltDb==-1)  ) 
	{
		fLast = tempstr.find("</Cell>");
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		strData = "empty";
		blEndRecord = true;
	}
	// CASE B scenario we had Data and NameCell Filled in the Same Line 		
	else if( (wksFound > -1) && (findNameCell > -1)  && (findCell >-1) )
	{			
		fLast = tempstr.find("</Cell>");
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		fLast = wksFound;  //tempstr.find("</Data>");
		fFirst = tempstr.rfind("\">");
		strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));
		blEndRecord = true;
	}
	// CASE C -- Has Data and NameCell but the Cell END is in the next Line
	else if( (wksFound > -1) && (findNameCell > -1)  && (findCell == -1) )
	{
		fLast = wksFound;  //tempstr.find("</Data>");
		fFirst = tempstr.rfind("\">");
		strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));
		if(strData.length() == 0 )
		    strData = "empty";
		blCellEnd = true; // wait the end of the Cell		
	}
	else if( (findCell > -1) &&  (blCellEnd)  ) // find the end of Cell
	{
		blCellEnd = false;
		//cell name
		fLast = tempstr.find("</Cell>"); 
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		blEndRecord = true;	
	}
	else if(wksRowFound > -1)	
	{
		blEndRecord = true;
		strData = "</Row>";
		blEndRecord = true;
		strCell="";	
	}


	// If the Record is OK
	if(blEndRecord)
	{
//--------------SIP CONFIG -----------------------------------------------
	
 if((blSipConfig)   &&  (numSipConfig > 0) )
 {
 
		 if ( ( strcmp(strCell.c_str(),xmlSipConfigTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[0].headerrecord)!= 0 )  )			
		{
			if (strData =="empty")
			{
				firstEmpty=true;
				blSipConfig = false;
			}
			else
			{
				firstEmpty=false;
				strcpy(stnSipConfig[icountSipConfig],strData.c_str());
				icountSipConfig++;							
			 }
			  			
		}
 
 
 
 }	
		
//-----------------------STATIONS------------------------------------------------------------------------------------------	    
	  
	    if((blStations)   &&  (numStation > 0) )
	    {
		
		
		//---- internal numbers //		//if( (strCell=="internumber")  &&  (strData !="Internal number") && (strData !="empty") )
		if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[0].headerrecord)!= 0 )  )			
		{
			if (strData =="empty")
			{
				firstEmpty=true;
				blStations = false;
			}
			else
			{
				firstEmpty=false;
				strcpy(stnNumber[num_count],strData.c_str());
				num_count++;			
				findFirst=true;
	
				strcpy( stnAllStations[icountAllst] , strData.c_str() );
				icountAllst++;

				
			 }
			  			
		}
		//-- DID duwa numbers 
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[1].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
					strcpy(stnDuwa[duwa_count],"-");
				else
				{	strcpy(stnDuwa[duwa_count],strData.c_str());
			
					duwa_count++;
					findSecond=true; 
				
					strcpy( stnAllStations[icountAllst] , strData.c_str() );
					icountAllst++;
				}
			}
			
			
		}
		
		//------Station Type-----------------------------------
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[3].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{						
			if(findFirst)
			{			
				
				if( !strcmp(strData.c_str(),xmlStationTypes[0].name) )
				{
					stSipCounter++;
					// sip for sipconfig compare 
					strcpy(stnSipStations[icountSip],stnNumber[num_count-1]);	
					icountSip++;	
				}
				else if( !strcmp(strData.c_str(),xmlStationTypes[1].name) )
				{
					stSipFaxCounter++;
					// sip for sipconfig compare 
					strcpy(stnSipStations[icountSip],stnNumber[num_count-1]);	
					icountSip++;	
				}
				else if( !strcmp(strData.c_str(),xmlStationTypes[2].name) )
				{
					stUp0Counter++;
				}
				else if( !strcmp(strData.c_str(),xmlStationTypes[3].name) )
				{
					stIpCounter++;
				}
				else if( !strcmp(strData.c_str(),xmlStationTypes[4].name) )
				{
					stRasCounter++;
				}
				else if( !strcmp(strData.c_str(),xmlStationTypes[5].name) )
				{
					stDeskCounter++;
				}
				else if( !strcmp(strData.c_str(),xmlStationTypes[6].name) )
				{
					stabFaxCounter++;
				}
				else if( !strcmp(strData.c_str(),xmlStationTypes[7].name) )
				{
					stabCounter++;
				}
				else if( !strcmp(strData.c_str(),xmlStationTypes[8].name) )
				{
					stIsdnCounter++;
				}
				else if( !strcmp(strData.c_str(),xmlStationTypes[9].name) )
				{
					stDectCounter++;
				}			
				findThird=true; 
				strcpy(stnStType[stType_count],strData.c_str());
				stType_count++;
			}						
		}
		//---------------Fax Callno
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[4].headerrecord)!= 0 )	&& (firstEmpty==false) )			
		{
		        if(findFirst)
			{
					if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
					{
					//
					}
					else
					{
					strcpy( stnFaxCallno[ifaxCallnoCount] , strData.c_str() );
					ifaxCallnoCount++;

					strcpy( stnAllFaxes[icountAllFax] , strData.c_str() );
					icountAllFax++;
					
					findFourth=true; 
					}

			}	
		}
		//---------------Fax DID
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[5].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[5].headerrecord)!= 0 )	&& (firstEmpty==false) )			
		{
		        if(findFirst)
			{
					if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
					{
					//
					}
					else
					{
					
					strcpy( stnFaxDid[ifaxDidCount] , strData.c_str() );
					ifaxDidCount++;
					
					strcpy( stnAllFaxes[icountAllFax] , strData.c_str() );
					icountAllFax++;
					
					findFifth=true;
					}
			}	
		}

		//---------------Fax  Name
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[6].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[6].headerrecord)!= 0 )	&& (firstEmpty==false) )			
		{
		}
		
		//---------------Class of service
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[7].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[7].headerrecord)!= 0 )	&& (firstEmpty==false) )			
		{
		}
		
		//---------------Call pickup
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[8].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[8].headerrecord)!= 0 )	&& (firstEmpty==false) )			
		{
		}
		
		
		
		//---Access 4
		//---Display Numbers		
		//---Email Address
		//---Mobile number
		
		//---NODE ID 
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[13].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[13].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
  				  strcpy(stnNode[node_count],"0");
				else	
				  strcpy(stnNode[node_count],strData.c_str());
			
				strcpy(stnStTypeNode[stTypeNode_count] ,stnNode[node_count]);
				stTypeNode_count++;
				
				node_count++;
				findSixth=true; 								
			}
		}

		else if( strcmp(strData.c_str(),"</Row>")  == 0  )
		{
		
			if(findFirst)
			{						
				if(!findSecond) // DUWA DID
				{
					strcpy(stnDuwa[duwa_count],"");
					duwa_count++;
				}
				if(!findSixth)// NODE 
				{
					strcpy(stnNode[node_count],"0");
					node_count++;
				}
				
				if(!findFourth) // fax callno
				{
					/*strcpy( stnFaxCallno[ifaxCallnoCount] , "empty");
					ifaxCallnoCount++;

					strcpy( stnAllFaxes[icountAllFax] , "empty" );
					icountAllFax++;*/
					
				}
				if(!findFifth) // fax did
				{
					/*strcpy( stnFaxDid[ifaxDidCount] ,  "empty"  );
					ifaxDidCount++;
					
					strcpy( stnAllFaxes[icountAllFax] ,  "empty"  );
					icountAllFax++;*/
				}			
				
				findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
			
			}
			
			findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
			
		}		
		
		numberoflines++;
	      }//  END BLSTATION 
//-----------------------END STATIONS------------------------------------------------------------------------------------------	    
//------------------------LICENSES-----------------------------------------------------------------------------------------------
	      else if((blLicenses)  && (numLic > 0) )
	      {
		
		if ( ( strcmp(strCell.c_str(),xmlLicensesNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[0].headerrecord)!= 0 )  )			
		{
			if (strData =="empty")
			{
				firstEmpty=true;
				blLicenses = false;
			}
			else
			{
				firstEmpty=false;
				strcpy(stnLicnum[lic_count],strData.c_str());
				lic_count++;
				
				findFirst=true; 
			 }
		}
		
		//---NODE ID 
		else if ( ( strcmp(strCell.c_str(),xmlLicensesNameTable[12].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[12].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{									
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
  				  strcpy(stnNode[node_count],"0");
				else	
				  strcpy(stnNode[node_count],strData.c_str());
				node_count++;
			
				findSecond=true; 
			}
		}
		else if( strcmp(strData.c_str(),"</Row>")  == 0  )
		{
		
			if(findFirst)
			{						
				if(!findSecond)// NODE 
				{
					strcpy(stnNode[node_count],"0");
					node_count++;
				}
	
		 	}
			findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
		}		
		
		
	      
	      }// END LICENSES	      	
//-----------------------------GROUPS---------------------------------------------------------------------------------------------------	      
	      else if((blGroups)  && (numGroup > 0) )
	      {
							
		
		if ( ( strcmp(strCell.c_str(),xmlGroupsNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[0].headerrecord)!= 0 )  )			
		{			
			//if (strData =="empty")
			if ( strcmp(strData.c_str(),"empty") == 0 ) 
			{
				firstEmpty=true;
				blGroups = false;
			}
			else
			{
				firstEmpty=false;
				strcpy(stnNumber[num_count],strData.c_str());				
				num_count++;
				
				findFirst=true; 
			 }			
		}
		//-- DID duwa numbers 
		else if ( ( strcmp(strCell.c_str(),xmlGroupsNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[1].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
					strcpy(stnDuwa[duwa_count],"-");
				else
					   strcpy(stnDuwa[duwa_count],strData.c_str());
			
				duwa_count++;
				findSecond=true; 
			}
			
		}
		//---NODE ID 
		else if ( ( strcmp(strCell.c_str(),xmlGroupsNameTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[4].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
  				  strcpy(stnNode[node_count],"0");
				else	
				strcpy(stnNode[node_count],strData.c_str());
			
				node_count++;
			
				if ( (strData.length() ==0) || (strData=="empty") )
				   curNode = 0;
				else			
				   curNode = atoi(strData.c_str());						
				/*		
				if(curNode == 0)		
				{
					countNodeGroups++;			
					if( countNodeGroups >22)
					{
						   faults[0][0]++;
			      			   faults[faultrow][0]=3;
			   			   faults[faultrow][1]=num_count - numStation-numGroup+ 2;
						   faults[faultrow][2]=22;
						   faultrow++;		
					   }
				   }
				   */
				   findThird=true; 
			}
						
		}
		else if( strcmp(strData.c_str(),"</Row>")  == 0  )
		{
		
			if(findFirst)
			{						
				if(!findSecond) // DUWA DID
				{
					strcpy(stnDuwa[duwa_count],"");
					duwa_count++;
				}
				if(!findThird)// NODE 
				{
					strcpy(stnNode[node_count],"0");
					node_count++;
				}							
			}

		 	findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
		}	
		

		numberoflines++;
	      
	      }	      
//---------------------------VIRTUALS-------------------------------------------------------------------------------------------------------	      
	      else if((blVirtual)  &&  (numVirtual>0) )
	      {
	      
		
		if ( ( strcmp(strCell.c_str(),xmlVirtualNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[0].headerrecord)!= 0 )  )			
		{			
			if ( strcmp(strData.c_str(),"empty") == 0 ) 
			{
				firstEmpty=true;
				blVirtual = false;
			}
			else
			{
				firstEmpty=false;
				strcpy(stnNumber[num_count],strData.c_str());
				num_count++;
				findFirst=true; 
			 }			
		}
		//-- DID duwa numbers 
		else if ( ( strcmp(strCell.c_str(),xmlVirtualNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[1].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
					strcpy(stnDuwa[duwa_count],"");
				else
					strcpy(stnDuwa[duwa_count],strData.c_str());
				duwa_count++;
				findSecond=true; 
			}
		}
		
		//------Station Type-----------------------------------
		else if ( ( strcmp(strCell.c_str(),xmlVirtualNameTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[3].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if( !strcmp(strData.c_str(),xmlVirtualStationTypes[0].name) )
				{
					syscountAutoAt++;
				}
				else if( !strcmp(strData.c_str(),xmlVirtualStationTypes[1].name) )
				{
					syscountCCFax++;
				}
				else if( !strcmp(strData.c_str(),xmlVirtualStationTypes[2].name) )
				{
					syscountPark++;
				}
				else if( !strcmp(strData.c_str(),xmlVirtualStationTypes[3].name) )
				{
					syscountConf++;
				}									
				else if( !strcmp(strData.c_str(),xmlVirtualStationTypes[4].name) )
				{
					sysCountFaxGroup++;
				}	
				else if( !strcmp(strData.c_str(),xmlVirtualStationTypes[5].name) )
				{
					sysCountVirtual++;
				}
				else if( !strcmp(strData.c_str(),xmlVirtualStationTypes[6].name) )
				{
					sysCountMeetMe++;
				}
				
				
				strcpy(stnStType[stType_count],strData.c_str());
				stType_count++;

																	

			}
		}
		//---NODE ID 
		else if ( ( strcmp(strCell.c_str(),xmlVirtualNameTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[4].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
  				  strcpy(stnNode[node_count],"0");
				else	
				strcpy(stnNode[node_count],strData.c_str());	
				strcpy(stnStTypeNode[stTypeNode_count] ,stnNode[node_count]);
				stTypeNode_count++;

				node_count++;	
				findThird=true; 
			}
		}
		//---Secondary Gateway
		
		else if( strcmp(strData.c_str(),"</Row>")  == 0  )
		{
		
			if(findFirst)
			{						
				if(!findSecond) // DUWA DID
				{
					strcpy(stnDuwa[duwa_count],"");
					duwa_count++;
				}
				if(!findThird)// NODE 
				{
					strcpy(stnNode[node_count],"0");
					node_count++;
				}
			}
		 	findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
		}		

		numberoflines++;
	      
	      }//END VIRTUAL
      
//---------------------------TRUNKS-------------------------------------------------------------------------------------------------------	        	      	      
	      else if((blTrunkGroup) && (numTrnk>0))
	      {

		if ( ( strcmp(strCell.c_str(),xmlTrunkGrpNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlTrunkGrpNameTable[0].headerrecord)!= 0 )  )			
		{			
			if ( strcmp(strData.c_str(),"empty") == 0 ) 
			{
				firstEmpty=true;
				blTrunkGroup = false;
			}
			else
			{
				firstEmpty=false;
				strcpy(stnNumber[num_count],strData.c_str());				
				num_count++;
				findFirst=true; 
			 }			
		}
		//---NODE ID 
		else if ( ( strcmp(strCell.c_str(),xmlTrunkGrpNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlTrunkGrpNameTable[2].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
  				  strcpy(stnNode[node_count],"0");
				else				
				strcpy(stnNode[node_count],strData.c_str());
			
				node_count++;
			
				if ( (strData.length() ==0) || (strData=="empty") )
				   curNode = 0;
				else			
				   curNode = atoi(strData.c_str());
			
		
				if(curNode ==  kdsretNode.inhalt[3] )
				{
					countNodeTrunksGr++;			
					if(countNodeTrunksGr >4)
					{
						   faults[0][0]++;
			      			   faults[faultrow][0]=5;
		   				   faults[faultrow][1]=num_count - numStation-numGroup-numVirtual+ 2;
						   faults[faultrow][2]=22;
						   faultrow++;
	  					//blTrunkGroup = false;
					}
				}
				findSecond=true;
			}
							
		}
		else if( strcmp(strData.c_str(),"</Row>")  == 0  )
		{
		
			if(findFirst)
			{						
				if(!findSecond)// NODE 
				{
					strcpy(stnNode[node_count],"0");
					node_count++;
				}
						
			}
		 	findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
		}	

		numberoflines++;

	      }
//---------------------------VOICEMAIL-------------------------------------------------------------------------------------------------------	      	      
	      else if((blVoicemail) && (numVoicemail>0) )
	      {

		
      		if ( ( strcmp(strCell.c_str(),xmlVoiceMailNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVoiceMailNameTable[0].headerrecord)!= 0 )  )			
		{			
			if ( strcmp(strData.c_str(),"empty") == 0 ) 
			{
				firstEmpty=true;
				blVoicemail = false;
			}
			else
			{
				firstEmpty=false;
				strcpy(stnNumber[num_count],strData.c_str());
				num_count++;
				findFirst=true; 
			 }			
		}
		//---NODE ID 
		else if ( ( strcmp(strCell.c_str(),xmlVoiceMailNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVoiceMailNameTable[2].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
  				  strcpy(stnNode[node_count],"0");
				else	
				strcpy(stnNode[node_count],strData.c_str());

				node_count++;			
			
				if ( (strData.length() ==0) || (strData=="empty") )
				   curNode = 0;
				else			
				   curNode = atoi(strData.c_str());						
						
				if(curNode == 0)		
				{
					countNodeVoicemail++;			
					if( countNodeVoicemail >1)
					{
						faults[0][0]++;
			      			   faults[faultrow][0]=6;
			   			   faults[faultrow][1]=num_count - numStation-numGroup-numVirtual-numTrnk+ 2;
						   faults[faultrow][2]=22;
						   faultrow++;		
					   }
				   }
				   findSecond=true; 
			}
			
		}
		else if( strcmp(strData.c_str(),"</Row>")  == 0  )
		{
		
			if(findFirst)
			{						
				if(!findSecond)// NODE 
				{
					strcpy(stnNode[node_count],"0");
					node_count++;
				}
			}
		 	findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
		}	
		
		numberoflines++;
	      } // END VOICE MAIL
	      	
	} //end If blEndRecord
		
	countLine++;//increase countLines number to numberring Lines   
	
    }// ----end while read lines-------

    fclose(fxml);

	
	for(i=0; i<20; i++)
    	{
           dublicatepos[i]=0;	
    	}	

	//-------------------Check Double Records In INTERNAL NUMBERS -------------------------------------------
//	faults[0][0]= faultrow - 1;
	// Check the Duplicates Numbers in Internal Numbers
	if(num_count > 0)
	{
		if(!checkdouble(stnNumber,num_count,dublicatepos))
		{
			for(i=0;i<20;i++)
			{
				if(faultrow!=21 && dublicatepos[i])
				{
				//numStation+numGroup+numVirtual+numTrnk+numVoicemail
					faults[0][0]++;								
					if (dublicatepos[i] <= numStation)
					{
					   faults[faultrow][0]=1;
					   faults[faultrow][1]=dublicatepos[i]+2;
					}
					else if( (dublicatepos[i] > numStation) && (dublicatepos[i] <= (numStation+numGroup) )  )
					{
					   faults[faultrow][0]=3;
					   faults[faultrow][1]=dublicatepos[i]-numStation+2;
					}
					else if(  (dublicatepos[i] > (numStation+numGroup) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual) ))  
					{
	 					faults[faultrow][0]=4;	
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup+ 2;									
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk) ))  
					{
	 					faults[faultrow][0]=5;						
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual+ 2;														
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual+numTrnk) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk+numVoicemail) ))  
					{
 						faults[faultrow][0]=6;		
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual-numTrnk+ 2;			
					}
					faults[faultrow][2]=CALL_NO_NOT_UNIQUE;
						faultrow++;			
				}
			}
		}
	}

    	for(i=0;i<20;i++)
    	{
           dublicatepos[i]=0;	
    	}	
	// Check the double digits
	if(num_count > 0)
	{
		if(!checkdoubledigits(stnNumber,num_count,dublicatepos))
		{
			for(i=0;i<20;i++)
			{
				if(faultrow!=21 && dublicatepos[i])
				{
				//numStation+numGroup+numVirtual+numTrnk+numVoicemail
					faults[0][0]++;								
					if (dublicatepos[i] <= numStation)
					{
					   faults[faultrow][0]=1;
					   faults[faultrow][1]=dublicatepos[i]+2;
					}
					else if( (dublicatepos[i] > numStation) && (dublicatepos[i] <= (numStation+numGroup) )  )
					{
					   faults[faultrow][0]=3;
					   faults[faultrow][1]=dublicatepos[i]-numStation+2;
					}
					else if(  (dublicatepos[i] > (numStation+numGroup) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual) ))  
					{
	 					faults[faultrow][0]=4;	
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup+ 2;									
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk) ))  
					{
	 					faults[faultrow][0]=5;						
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual+ 2;														
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual+numTrnk) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk+numVoicemail) ))  
					{
 						faults[faultrow][0]=6;		
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual-numTrnk+ 2;			
					}
					faults[faultrow][2]=CALL_NO_NOT_UNIQUE;
						faultrow++;			
				}
			}
		}
	}

    	for(i=0;i<20;i++)
    	{
           dublicatepos[i]=0;	
    	}	
	//-------------------Check Double Records In DID Numbers -------------------------------------------
	// Check the Did Numbers  for Doule records 
	if(duwa_count > 0)
	{
		if(!checkdouble(stnDuwa,duwa_count,dublicatepos))
		{
				for(i=0;i<20;i++)
				{
					if(faultrow!=21 && dublicatepos[i])
					{				
					//numStation+numGroup+numVirtual+numTrnk+numVoicemail	
					faults[0][0]++;								
					if (dublicatepos[i] <= numStation)
					{
					   faults[faultrow][0]=1;
					   faults[faultrow][1]=dublicatepos[i]+2;
					}
					else if( (dublicatepos[i] > numStation) && (dublicatepos[i] <= (numStation+numGroup) )  )
					{
					   faults[faultrow][0]=3;
					   faults[faultrow][1]=dublicatepos[i]-numStation+2;
					}
					else if(  (dublicatepos[i] > (numStation+numGroup) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual) ))  
					{
	 					faults[faultrow][0]=4;	
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup+ 2;									
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk) ))  
					{
	 					faults[faultrow][0]=5;					
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual+ 2;														
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual+numTrnk) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk+numVoicemail) ))  
					{
	 					faults[faultrow][0]=6;		
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual-numTrnk+ 2;			
					}
					faults[faultrow][2]=DUWA_NOT_UNIQUE;
					faultrow++;							
				}
			}
		}
	}


	for(i=0;i<20;i++)
    	{
           dublicatepos[i]=0;	
    	}
	
	//------------sipConfig check double -------------------------
	for(i=0;i<20;i++)
    	{
           dublicatepos[i]=0;	
    	}
	// Check the Did digits  for Doule 
	if(icountSipConfig > 0)
	{
		if(!checkdoubledigits(stnSipConfig,icountSipConfig,dublicatepos))
		{
				for(i=0;i<20;i++)
				{
					if(faultrow!=21 && dublicatepos[i])
					{				
						
					faults[0][0]++;								
					if (dublicatepos[i] <= icountSipConfig)
					{
					   faults[faultrow][0]=7;/* tab index for sipconfig */
					   faults[faultrow][1]=dublicatepos[i]+2;
					}					
					faults[faultrow][2]=CALL_NO_NOT_UNIQUE; /*new error definition */
					faultrow++;
				}
			}
		}
	}

	for(i=0;i<20;i++)
    	{
           dublicatepos[i]=0;	
    	}
	//-------------------Check Double Records In DID Numbers -------------------------------------------
	// Check the Did Numbers  for Doule records 
	if(duwa_count > 0)
	{
		if(!checkdoubledigits(stnDuwa,duwa_count,dublicatepos))
		{
				for(i=0;i<20;i++)
				{
					if(faultrow!=21 && dublicatepos[i])
					{				
					//numStation+numGroup+numVirtual+numTrnk+numVoicemail	
					faults[0][0]++;								
					if (dublicatepos[i] <= numStation)
					{
					   faults[faultrow][0]=1;
					   faults[faultrow][1]=dublicatepos[i]+2;
					}
					else if( (dublicatepos[i] > numStation) && (dublicatepos[i] <= (numStation+numGroup) )  )
					{
					   faults[faultrow][0]=3;
					   faults[faultrow][1]=dublicatepos[i]-numStation+2;
					}
					else if(  (dublicatepos[i] > (numStation+numGroup) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual) ))  
					{
	 					faults[faultrow][0]=4;	
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup+ 2;									
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk) ))  
					{
	 					faults[faultrow][0]=5;					
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual+ 2;														
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual+numTrnk) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk+numVoicemail) ))  
					{
	 					faults[faultrow][0]=6;		
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual-numTrnk+ 2;			
					}
					faults[faultrow][2]=DUWA_NOT_UNIQUE;
					faultrow++;							
				}
			}
		}
	}


	for(i=0;i<20;i++)
    	{
           dublicatepos[i]=0;	
    	}
	//------------Check Node Type If is valid or Mixed Up----------------------
	if(node_count > 0 )
	{
		if(!checkNodeType(stnNode,node_count,dublicatepos))
		{
		        for(i=0;i<20;i++)
			{
			 if(faultrow!=21 && dublicatepos[i])
			 {
				//numStation+numGroup+numVirtual+numTrnk+numVoicemail
				faults[0][0]++;								
				if (dublicatepos[i] <= numStation)
				{
				   faults[faultrow][0]=1;
				   faults[faultrow][1]=dublicatepos[i]+2;
					}
					else if( (dublicatepos[i] > numStation) && (dublicatepos[i] <= (numStation+numGroup) )  )
					{
					   faults[faultrow][0]=3;
					   faults[faultrow][1]=dublicatepos[i]-numStation+2;
					}
					else if(  (dublicatepos[i] > (numStation+numGroup) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual) ))  
					{
	 					faults[faultrow][0]=4;	
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup+ 2;									
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk) ))  
					{
 						faults[faultrow][0]=5;					
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual+ 2;														
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual+numTrnk) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk+numVoicemail) ))  
					{
	 					faults[faultrow][0]=6;		
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual-numTrnk+ 2;			
					}
					faults[faultrow][2]=NODE_ID_MIXUP;
					faultrow++;			
					
				}
			}
		}
	}
	
	
	//----Check Licenses Numbers-----------------------------
	//if(!checkLicensesNumbers(stnNumber,stnLicnum,num_count, lic_count,dublicatepos))
	if(stnLicnum>0)
	{
		if(!checkLicensesNumbers(stnNumber,stnLicnum,numStation, lic_count,dublicatepos))
		{
			for(i=0;i<20;i++)
				{
				if(faultrow!=21 && dublicatepos[i])
				{
					//numStation+numGroup+numVirtual+numTrnk+numVoicemail
					faults[0][0]++;								
					faults[faultrow][0]=2;
					faults[faultrow][1]=dublicatepos[i]+2;								
					faults[faultrow][2]= LIC_NOT_EXISTS; // ENUM 42
					faultrow++;	
				}
			}	
		
		}
	}
	
	
	
	
	/*----------------------------Faxes Checks--------------------------------------------------------*/
	
	if(ifaxCallnoCount > 0)
	{
		if(!checkdouble(stnFaxCallno,ifaxCallnoCount,dublicatepos))
		{
			for(i=0;i<20;i++)
			{
				if(faultrow!=21 && dublicatepos[i])
				{
				//numStation+numGroup+numVirtual+numTrnk+numVoicemail
					faults[0][0]++;								
				        faults[faultrow][0]=1;
					faults[faultrow][1]=dublicatepos[i]+2;				
					faults[faultrow][2]=FAX_CALL_NOT_UNIQUE;
				        faultrow++;			
				}
			}
		}
		if(!checkdoubledigits(stnFaxCallno,ifaxCallnoCount,dublicatepos))
		{
			for(i=0;i<20;i++)
			{
				if(faultrow!=21 && dublicatepos[i])
				{
				//numStation+numGroup+numVirtual+numTrnk+numVoicemail
					faults[0][0]++;								
				        faults[faultrow][0]=1;
					faults[faultrow][1]=dublicatepos[i]+2;				
					faults[faultrow][2]=FAX_CALL_NOT_UNIQUE;
				        faultrow++;			
				}
			}
		}
		
	}

	if(ifaxDidCount > 0)
	{
		if(!checkdouble(stnFaxDid,ifaxDidCount,dublicatepos))
		{
			for(i=0;i<20;i++)
			{
				if(faultrow!=21 && dublicatepos[i])
				{
					faults[0][0]++;								
				        faults[faultrow][0]=1;
					faults[faultrow][1]=dublicatepos[i]+2;				
					faults[faultrow][2]=FAX_DID_NOT_UNIQUE;
				        faultrow++;			
				}
			}
		}
		if(!checkdoubledigits(stnFaxDid,ifaxDidCount,dublicatepos))
		{
			for(i=0;i<20;i++)
			{
				if(faultrow!=21 && dublicatepos[i])
				{
					faults[0][0]++;								
				        faults[faultrow][0]=1;
					faults[faultrow][1]=dublicatepos[i]+2;				
					faults[faultrow][2]=FAX_DID_NOT_UNIQUE;
				        faultrow++;			
				}
			}
		}
	}
	
	
	     		
	/*Check if The Fax Did  Exist*/
	if(ifaxDidCount>0)
	{
		if(!checkFaxDuplicate(stnAllStations,stnFaxDid,icountAllst, ifaxDidCount,dublicatepos))
		{
			for(i=0;i<20;i++)
				{
				if(faultrow!=21 && dublicatepos[i])
				{
					//numStation+numGroup+numVirtual+numTrnk+numVoicemail
					faults[0][0]++;								
					faults[faultrow][0]=1;
					faults[faultrow][1]=dublicatepos[i]+2;								
					faults[faultrow][2]= FAX_DID_NOT_UNIQUE; // ENUM 42
					faultrow++;	
				}
			}	
		
		}
	}
	
	if(ifaxCallnoCount>0)
	{
		if(!checkFaxDuplicate(stnAllStations,stnFaxCallno,icountAllst, ifaxCallnoCount,dublicatepos))
		{
			for(i=0;i<20;i++)
				{
				if(faultrow!=21 && dublicatepos[i])
				{
					//numStation+numGroup+numVirtual+numTrnk+numVoicemail
					faults[0][0]++;								
					faults[faultrow][0]=1;
					faults[faultrow][1]=dublicatepos[i]+2;								
					faults[faultrow][2]= FAX_CALL_NOT_UNIQUE; // ENUM 42
					faultrow++;	
				}
			}	
		
		}
	}
	if(icountSipConfig > 0)
	{
	
		if(!checkSipConfigInStations(stnSipStations,stnSipConfig,icountSip,icountSipConfig, dublicatepos))
		{
			for(i=0;i<20;i++)
				{
				if(faultrow!=21 && dublicatepos[i])
				{					
					faults[0][0]++;								
					faults[faultrow][0]=7; // tabshett SIpConfig
					faults[faultrow][1]=dublicatepos[i]+2;								
					faults[faultrow][2]= 222; // new enum duplicate SipConfig
					faultrow++;	
				}
			}	
		
		}
	
	}


  
   //--------------CHECK THE NUMBER OF RECORDS------------------------------------------------
   
   
  /*  NO CHECK IN LX    THE STATION TYPES DO NOT EXIST
   checkNumberOfStations(syscountUp0,syscountAn,syscountDect,syscountIsdn);/*  Count he Number Of System Available Stations Ports
 */

   //LXsumNodeStationsType(stnStType,stnStTypeNode, stType_count , stSipCounter, stIpCounter, stDeskCounter, syscountAutoAt, syscountCCFax, syscountPark, syscountConf ,sysCountFaxGroup , sysCountVirtual,stRasAdminCounter, stRasLicCounter,sysCountMeetMe);

  
  isumNodeStVir = stSipCounter+stUp0Counter+stIpCounter+stRasCounter+stDeskCounter+stabCounter+stIsdnCounter+stDectCounter+syscountAutoAt+syscountCCFax+syscountPark+syscountConf+sysCountFaxGroup+sysCountVirtual+sysCountMeetMe;
   
   if(!stIpCounter)
   {
	if(faultrow!=21)
	{
		faults[0][0]++;
		faults[faultrow][0]=1;	
		faults[faultrow][1]=1;	
		faults[faultrow][2]=IP_CLIENT_MISSING;  
		faultrow++;	
	}
   }

   if(ifaxCallnoCount>111   ||  ifaxDidCount>111 )
   {
   
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=1;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_FAXES;
		faultrow++;			   	
	}
   }
   
   
   if( isumNodeStVir > 111 )
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=1;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_STATIONS;
		faultrow++;			   	
	}
    }
  
   if(  stDeskCounter >  AMOUNT_OF_IP_PORTS_V2_S) 
   {
	if(faultrow!=21)
	{
		faults[0][0]++;
		faults[faultrow][0]=1;	
		faults[faultrow][1]=999;	
		faults[faultrow][2]= TOO_MANY_DESK;/*48*/  
		faultrow++;	
	}
   }
    
   
   if( stIpCounter > AMOUNT_OF_IP_PORTS_V2_S)
   {
	if(faultrow!=21)
	{
		faults[0][0]++;
		faults[faultrow][0]=1;	
		faults[faultrow][1]=999;	
		faults[faultrow][2]=TOO_MANY_IP;  
		faultrow++;	
	}
   }
   
   
   if( stSipCounter > AMOUNT_OF_IP_PORTS_V2_S )
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=1;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_SIP;
		faultrow++;	
	}
   }

   if( syscountAutoAt > 111 )
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=4;
		faults[faultrow][1]=999;								
		faults[faultrow][2]= TOO_MANY_VP_AUTO_ATTENDANT; 
		faultrow++;	
	}
   
   }
   if( syscountCCFax > 111 )
   {	
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=4;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_VP_AUTO_ATTENDANT; 
		faultrow++;
	}
   }
   
   if( syscountConf > 111 )
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=4;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_OSO_CONFERENCE; 
		faultrow++;	
	}
   }

   if( syscountPark > 111 )
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=4;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_PARK;
		faultrow++;			   	
	}
   }
   

   if( sysCountFaxGroup > 11 )
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=4;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_FAXGROUPS;
		faultrow++;			   	
	}
   }
   
   
   if(sysCountMeetMe  > 11) 
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=1;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_MEET_ME;
		faultrow++;			   	
	}         
   }

   
   for(i=0;i<(numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic);i++)
   {
	delete []stnNumber[i];
	delete []stnDuwa[i];
	delete []stnNode[i];
	delete []stnStType[i];
	delete []stnStTypeNode[i];

   }
   for(i=0; i<numLic; i++)
   {
   	delete []stnLicnum[i];
   }
   
    for(i=0;  i<numStation+1; i++)
    {
    	delete []stnSipStations[i];
    }
    for(i=0;  i<numSipConfig+1; i++)
    {
    	delete []stnSipConfig[i];
    }
    
    
    
   for(i=0;i<numStation*2; i++)
   {

         delete []stnAllStations[i];
	 delete []stnAllFaxes[i];
   }
	
   delete []stnNumber;
   delete []stnDuwa;
   delete []stnNode;
   delete []stnLicnum;
   delete []stnStType;
   delete []stnStTypeNode;
   delete []stnAllStations;
   delete []stnAllFaxes;
   delete []stnSipStations;
   delete []stnSipConfig;

   
   
  if( faultrow <2 )
  {
     

     if(numStation > 0)
	LXwriteXmlStations(fname, numStation);    
	  
     if(numVirtual >0 )
      	//LXwriteXmlVirtuals(fname, numVirtual);   
	
     if(numTrnk >0 )
      	//LXwriteXmlTrunkGroups(fname, numTrnk);
	
     if(numVoicemail >0 ) 
    //  LXwriteXmlVoiceMail(fname, numVoicemail);
      
     if(numGroup >0) 
     // LXwriteXmlGroups(fname, numGroup);
      
      if(stnSipConfig>0)
     {
       
       LXwriteXmlSipConfig(fname,numSipConfig);
       
     }
      
     if(numLic >0)  
     {

	// LXwriteXmlLicenses(fname,numLic,1);

      
     }
     
     
  }
    
  }
void fpreadxml(char* fname, int faults[21][3])
{

    char line [128]; 
    FILE *fxml = fopen(fname,"r");
    int fLast,fFirst,intLen,wksFound,findNameCell=0,findCell=0,countLine=0,wksRowFound,fFiltDb=0;
    string tempstr,totalstr,strData,strCell ;  
    bool blStations=false,blLicenses=false,blGroups=false,blVirtual=false,blTrunkGroup=false,blVoicemail=false,blCellEnd=false,blEndRecord=false,firstEmpty=false,blSipConfig=false;
    bool blwriteXmlStations=false, blwriteXmlLicenses=false,  blwriteXmlGroups=false, blwriteXmlVirtual=false, blwriteXmlTrunks=false, blwriteXmlVoicemail=false,blwritexmlSipConfig=false;
    int i=0,pos=0,numberoflines=0,returnvalue=0,isumNodeStVir=0;	
    char **stnNumber,**stnDuwa,**stnNode,**stnLicnum, **stnStType,**stnStTypeNode,**stnAccessUP0,**stnAccessAnalog,**stnVoicemail, **stnFaxCallno, **stnFaxDid ,**stnAllStations, **stnAllFaxes,**stnSipStations,**stnSipConfig;
    int dublicatepos[20];
    int faultrow=0,ievmCounter=0;
    int arrayNumRecords[7];   
    int num_count=0, duwa_count=0, node_count=0,lic_count=0,stType_count=0, stTypeNode_count=0,countAccessUP0=0,countAccessAnalog=0,ifaxCallnoCount=0, ifaxDidCount=0,icountAllst=0,icountAllFax=0,icountSip=0,icountSipConfig=0; 
    int numStation=0,numLic=0,numGroup=0,numVirtual=0,numTrnk=0,numVoicemail=0, numSipConfig=0;
    int curNode=0, countNodeTrunksGr=0,countNodeVoicemail=0,countNodeGroups=0;
    RD_KDS_RETURN	kdsretNode;
    int  stSipCounter=0, stSipFaxCounter=0, stUp0Counter=0, stIpCounter=0, stRasCounter=0, stDeskCounter=0, stabFaxCounter=0, stabCounter=0, stIsdnCounter=0, stDectCounter=0, stRasAdminCounter=0, stRasLicCounter=0;
    int syscountUp0=0,syscountAn=0,syscountDect=0,syscountIsdn=0; 
    int syscountPark=0, syscountConf=0,syscountAutoAt=0, syscountCCFax=0, sysCountFaxGroup=0,sysCountVirtual=0,sysCountMeetMe=0;
    bool findFirst=false,findSecond=false,findThird=false,findFourth=false,findFifth=false,findSixth=false,findSeventh=false,findEighth=false,findNinth=false,findTenth=false,findEleventh=false,findTwelvth=false,blX1=false;
    double div=0;   
    
    RD_KDS_RETURN           kdsreturnX1;
    

    
    // Test The Function 
    //    
   //  Db_rddtb(KDS_AUSBAU_VAR,KDS_ANLAGEN_AUSBAU,KEINE_SPALTE,(RD_KDS_RETURN*)&kdsreturnX1);   // takes System type 

    //if(kdsreturnX1.inhalt[0]== DS_BPL_ONE_X1)  //DS_BPL_ONE
  	blX1=false; // means system is X1

   
   
   
    for(i=0;i<21;i++)
    {
	for(pos=0;pos<3;pos++)
		faults[i][pos]=0;
    }

   //--- Check if The File Extension Is .xml
   
   
   returnvalue = compare_extension(fname,".xml" );
   if(returnvalue ==0)
   {  	
	faults[0][0]++;
	faults[faultrow+1][0]=1;	// invalid file format 
	faults[faultrow+1][1]=999;	
	faults[faultrow+1][2]=INVALID_FILE_FORMAT;	
	faultrow++;	
	return;			
    }
    else 
       returnvalue = 0;
   
 
  //-------------------------CHECK THE NUMER OF RECORDS AND THE VALIDATION-------------------	
    returnvalue = WorkSheetRecords(fname,arrayNumRecords,faultrow,faults); // ) no fault , 1 there are faults

    
    
    
    if(returnvalue > 1)
    {    	
	fclose(fxml);
	return;
    }    
    else 
    faultrow++;

   	
   // 	faultrow++; // ++ the faultrow in order to start with the next error
  
    
    //Db_rddtb(KDS_NODE_ID,KEINE_ZEILE,KEINE_SPALTE,(RD_KDS_RETURN*)&kdsretNode);
    
    
    numStation = arrayNumRecords[0] ;
    numLic = arrayNumRecords[1] ; 
    numGroup = arrayNumRecords[2];
    numVirtual = arrayNumRecords[3];
    numTrnk = arrayNumRecords[4];
    numVoicemail = arrayNumRecords[5];
    numSipConfig = arrayNumRecords[6];
    
    //printf("\n ilias numStation=%d, numLic=%d, numGroup=%d,  numVirtual=%d,numTrnk=%d,  numVoicemail=%d ",numStation,numLic,numGroup,numVirtual,numTrnk,numVoicemail);
    //printf("\n ilias SumNumber=%d , Sum_Lic=%d ",(numStation+numGroup+numVirtual+numTrnk+numVoicemail), numLic);
   
      
    stnNumber = new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic]; 
    stnDuwa   = new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic];
    stnNode   = new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic];
    stnLicnum = new char*[numLic];
    stnStType = new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic]; 
    stnStTypeNode= new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic]; 
    stnAccessAnalog = new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic]; 
    stnAccessUP0 = new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic]; 
    stnVoicemail= new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic]; 
    stnFaxCallno= new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic]; 
    stnFaxDid= new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic]; 
    stnAllStations=new char*[numStation*2];
    stnAllFaxes=new char*[numStation*2];
    
    /*----------------------sip config --------------------*/
    stnSipStations=new char*[numStation+1];
    stnSipConfig=new char*[numSipConfig+1];
    
    
    for(i=0;  i<numStation+1; i++)
    {
    	stnSipStations[i]=new char[(RUFNR_SIZE*2)+1];
    }
    for(i=0;  i<numSipConfig+1; i++)
    {
    	stnSipConfig[i]=new char[(RUFNR_SIZE*2)+1];
    }
    /*-----------------------------------------------*/
    
    
    for(i=0; i<(numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic); i++)
    {
	stnNumber[i]=new char[(RUFNR_SIZE*2)+1];
	stnDuwa[i]=new char[(RUFNR_SIZE*2)+1];
	stnNode[i]=new char[(RUFNR_SIZE*2)+1];
	stnStType[i]=new char[(RUFNR_SIZE*2)+1];
	stnStTypeNode[i]=new char[(RUFNR_SIZE*2)+1];
	stnAccessAnalog[i] =new char[(RUFNR_SIZE*2)+1]; 
	stnAccessUP0[i] =new char[(RUFNR_SIZE*2)+1];
	stnVoicemail[i] =new char[(RUFNR_SIZE*2)+1];
	stnFaxCallno[i] =new char[(RUFNR_SIZE*2)+1];
	stnFaxDid[i] =new char[(RUFNR_SIZE*2)+1];
    }
    
    for(i=0; i<numLic; i++)
    {
        stnLicnum[i] = new char[(RUFNR_SIZE*2)+1];	
    }
    
   for(i=0; i<numStation*2; i++)
    {
    	stnAllStations[i]=new char[(RUFNR_SIZE*2)+1];
	    stnAllFaxes[i]=new char[(RUFNR_SIZE*2)+1];
    }
    
    for(i=0;i<(numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic);i++)
    {
	for(pos=0;pos<RUFNR_SIZE*2;pos++)
	{
		stnNumber[i][pos]='\0';
		stnDuwa[i][pos]='\0';
		stnNode[i][pos]='\0';
		stnStType[i][pos]='\0';
		stnStTypeNode[i][pos]='\0';
		stnAccessAnalog[i][pos]='\0';
		stnAccessUP0[i][pos]='\0';
		stnVoicemail[i][pos]='\0';
		stnFaxCallno[i][pos]='\0';
		stnFaxDid[i][pos]='\0';
	}
    }
    
    for(i=0;i<numLic;i++)
    {
	for(pos=0;pos<RUFNR_SIZE*2;pos++)
	{
		stnLicnum[i][pos]='\0';
	}
    }
    
    for(i=0; i<numStation*2; i++)
    {
	stnAllStations[i][pos]='\0';
	stnAllFaxes[i][pos]='\0';
    }
    
    
    for(i=0;i<(numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic);i++)
    {
	strcpy(stnNumber[i],"empty");
	strcpy(stnDuwa[i],"empty");
	strcpy(stnNode[i],"empty");
	strcpy(stnStType[i],"empty");	
	strcpy(stnStTypeNode[i],"empty");	 
	strcpy(stnAccessAnalog[i],"empty");	 
	strcpy(stnAccessUP0[i],"empty");
	strcpy(stnVoicemail[i],"empty");
	strcpy(stnFaxCallno[i],"empty");
	strcpy(stnFaxDid[i],"empty");		 
    }
    
    for(i=0; i<numStation*2; i++)
    {
	strcpy(stnAllStations[i],"");
	strcpy(stnAllFaxes[i],"");
    }
 
  //-------------------------CHECK THE NUMER OF RECORDS AND THE VALIDATION-------------------	
    
    // -- Prepei na mpoun edo kai Safe Conditions an Skasei        
    while(fgets ( line,128,fxml ) != NULL ) // read a line by line
    {
	
	tempstr=line; // this temp str contains the current line
	intLen = strlen(line);


	//---1-find----WorkSheet name ------------------------------
	wksFound= tempstr.find("Worksheet ss:Name");
	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
	        fFirst= tempstr.find("\"");
	        fLast=tempstr.find_last_of("\"");   
	        tempstr = tempstr.substr(fFirst+1,(fLast-(fFirst+1)));		

		if(tempstr == "Stations")
	   	   blStations = true;
		else if(tempstr =="Licenses")
		   blLicenses = true; 	
		else if(tempstr =="Groups")		
		   blGroups = true;		    
		else if(tempstr =="Virtual")		
		   blVirtual = true;
		else if(tempstr =="Trunk Groups")
		   blTrunkGroup = true;		
		else if(tempstr =="Voicemail")	
		   blVoicemail = true;
		else if(tempstr == "SipConfig")
		  blSipConfig = true;
    	}// end worksheet search 

	//---2 find the End of WorkSheet-------------
	wksFound= tempstr.find("</Worksheet>");
	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
		if(blStations)
		{
			blStations = false;
		}
		else if(blLicenses)
		{
			blLicenses = false;
		}
		else if(blGroups)
		{
			blGroups = false;
		}
		else if(blVirtual)
		{
			blVirtual = false;
		}
		else if(blTrunkGroup)
		{
			blTrunkGroup = false;
		}
		else if(blVoicemail)
		{
			blVoicemail = false;
		}
		else if(blSipConfig)
		{
		    blSipConfig = false;
		}
	}

	// We read the Xml file Line to Line 	
	// We search for the following KLeywords in order to Find the Data and the Name of these.
	// "</Data>"  means that the Cell in Xml file has data it's  not empty
	// "</NamedCell>"  is the name of the Cell   e.x Didnumber
	// "</Cell>"  end of Cell 
	
	// CASE  A no data only namecell	
	// 	<Cell ss:StyleID="s38"><NamedCell ss:Name="gateway"/></Cell>  
	
        // CASE B in same Line all Data	
	//  	<Cell ss:Index="2" ss:StyleID="s30"><Data ss:Type="Number">102</Data><NamedCell ss:Name="stinternalnum"/></Cell> 
	
	/// CASE C we have the Data but the Name of the Cell ends in the Next Line
	//   <Cell ss:StyleID="s38"><Data ss:Type="String">ilias.mamalis@siemens-enterprise.com</Data><NamedCell 
	//        ss:Name="emailaddr"/></Cell>
	
	blEndRecord = false;

	wksFound = tempstr.find("</Data>");
	findNameCell = tempstr.find("<NamedCell");
	findCell = tempstr.find("</Cell>");
	wksRowFound =  tempstr.find("</Row>");
	fFiltDb = tempstr.find("FilterDatabase");


	//  CASE  A -- Check if the line is empty, has no data, only namedcell
	if((findNameCell > -1) && (wksFound == -1) && (fFiltDb==-1)   ) 
	{
		fLast = tempstr.find("</Cell>");
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		strData = "empty";
		blEndRecord = true;
	}
	// CASE B scenario we had Data and NameCell Filled in the Same Line 		
	else if( (wksFound > -1) && (findNameCell > -1)  && (findCell >-1) )
	{			
		fLast = tempstr.find("</Cell>");
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		fLast = wksFound;  //tempstr.find("</Data>");
		fFirst = tempstr.rfind("\">");
		strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));
		blEndRecord = true;
	}
	// CASE C -- Has Data and NameCell but the Cell END is in the next Line
	else if( (wksFound > -1) && (findNameCell > -1)  && (findCell == -1) )
	{
		fLast = wksFound;  //tempstr.find("</Data>");
		fFirst = tempstr.rfind("\">");
		strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));
		if(strData.length() == 0 )
		    strData = "empty";
		blCellEnd = true; // wait the end of the Cell		
	}
	else if( (findCell > -1) &&  (blCellEnd)  ) // find the end of Cell
	{
		blCellEnd = false;
		//cell name
		fLast = tempstr.find("</Cell>"); 
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		blEndRecord = true;	
	}
	else if(wksRowFound > -1)	
	{
		blEndRecord = true;
		strData = "</Row>";
		blEndRecord = true;
		strCell="";	
	}


	// If the Record is OK
	if(blEndRecord)
	{
	
	
	
	
//--------------SIP CONFIG -----------------------------------------------
	
 if((blSipConfig)   &&  (numSipConfig > 0) )
 {
 
		 if ( ( strcmp(strCell.c_str(),xmlSipConfigTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[0].headerrecord)!= 0 )  )			
		{
			if (strData =="empty")
			{
				firstEmpty=true;
				blSipConfig = false;
			}
			else
			{
				firstEmpty=false;
				strcpy(stnSipConfig[icountSipConfig],strData.c_str());
				icountSipConfig++;							
			 }
			  			
		}
 
 
 
 }	
	
	
//-----------------------STATIONS------------------------------------------------------------------------------------------	    
	  

	    if((blStations)   &&  (numStation > 0) )
	    {
		//---- internal numbers //		//if( (strCell=="internumber")  &&  (strData !="Internal number") && (strData !="empty") )
		if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[0].headerrecord)!= 0 )  )			
		{
			if (strData =="empty")
			{
				firstEmpty=true;
				blStations = false;
			}
			else
			{
				firstEmpty=false;
				strcpy(stnNumber[num_count],strData.c_str());
				num_count++;			
				findFirst=true;
				
				strcpy(stnAllStations[icountAllst],strData.c_str());
				icountAllst++;
				
			 }
			  			
		}
		//-- DID duwa numbers 
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[1].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
					strcpy(stnDuwa[duwa_count],"-");
				else
				{
					strcpy(stnDuwa[duwa_count],strData.c_str());
			
				duwa_count++;
				findSecond=true; 
					
					strcpy(stnAllStations[icountAllst],strData.c_str());
					icountAllst++;
				}
			}
			
			
		}
		
		//------Station Type-----------------------------------
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[3].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{						
			if(findFirst)
			{
				if( !strcmp(strData.c_str(),xmlStationTypes[0].name) )
				{
					stSipCounter++;
					// sip for sipconfig compare 
					strcpy(stnSipStations[icountSip],stnNumber[num_count-1]);	
					icountSip++;									
				}
				else if( !strcmp(strData.c_str(),xmlStationTypes[1].name) )
				{
					stSipFaxCounter++;
				}
				else if( !strcmp(strData.c_str(),xmlStationTypes[2].name) )
				{
					stUp0Counter++;
				}
				else if( !strcmp(strData.c_str(),xmlStationTypes[3].name) )
				{
					stIpCounter++;
				}
				else if( !strcmp(strData.c_str(),xmlStationTypes[4].name) )
				{
					stRasCounter++;
				}
				else if( !strcmp(strData.c_str(),xmlStationTypes[5].name) )
				{
					stDeskCounter++;
				}
				else if( !strcmp(strData.c_str(),xmlStationTypes[6].name) )
				{
					stabFaxCounter++;
				}
				else if( !strcmp(strData.c_str(),xmlStationTypes[7].name) )
				{
					stabCounter++;
				}
				else if( !strcmp(strData.c_str(),xmlStationTypes[8].name) )
				{
					stIsdnCounter++;
				}
				else if( !strcmp(strData.c_str(),xmlStationTypes[9].name) )
				{
					stDectCounter++;
				}						
			
				findThird=true; 
				
				strcpy(stnStType[stType_count],strData.c_str());
				stType_count++;
			}						
		}
		
		//---------------Fax Callno

		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[4].headerrecord)!= 0 )	&& (firstEmpty==false) )			
		{
		        if(findFirst)
			{
				strcpy( stnFaxCallno[ifaxCallnoCount] , strData.c_str() );
				ifaxCallnoCount++;
				
				strcpy(stnAllFaxes[icountAllFax],strData.c_str());
				icountAllFax++;
				
				findFourth = true;
			}	
		}
		//---------------Fax DID
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[5].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[5].headerrecord)!= 0 )	&& (firstEmpty==false) )			
		{
		        if(findFirst)
			{
				strcpy( stnFaxDid[ifaxDidCount] , strData.c_str() );
				ifaxDidCount++;
				
				strcpy(stnAllFaxes[icountAllFax],strData.c_str());
				icountAllFax++;
				
				findFifth = true;
			}	
		}
		/*
		//---------------Class of service
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[7].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[7].headerrecord)!= 0 )	&& (firstEmpty==false) )			
		{
		}
		
		//---------------Call pickup
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[8].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[8].headerrecord)!= 0 )	&& (firstEmpty==false) )			
		{
		}
		
		*/
		// --------------ACCESS----------------------------
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[9].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[9].headerrecord)!= 0 )	&& (firstEmpty==false) )			
		{
			if(findFirst)
			{/*
				int k =  num_count-1;
				string str_k ="";
				sprintf(str_k.c ,"%d",k);
				

				if( strcmp( stnStType[stType_count-1] , xmlStationTypes[2].name ) == 0 ) // UP0
				{
					strcpy( stnAccessUP0[countAccessUP0], strData.c_str()) ;
					strcat( stnAccessUP0[countAccessUP0], "," );
					strcat( stnAccessUP0[countAccessUP0] , str_k.c_str() );
					countAccessUP0++;
				}
				else if ( (strcmp( stnStType[stType_count-1] , xmlStationTypes[7].name ) == 0)   ||   (strcmp( stnStType[stType_count-1] , xmlStationTypes[6].name ) == 0) ) // Analog -Analog Fax
				{								        	
					strcpy( stnAccessAnalog[countAccessAnalog] ,  strData.c_str());					
					strcat( stnAccessAnalog[countAccessAnalog] , ",");
					strcat( stnAccessAnalog[countAccessAnalog] , str_k.c_str() );
					countAccessAnalog++;
				}*/
			}						

		}
		//--VoiceMail
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[10].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[10].headerrecord)!= 0 )	&& (firstEmpty==false) )			
		{
			if(findFirst)
			{
				strcpy( stnVoicemail[num_count-1] , strData.c_str() );
			}						

		}
		
		//---Email Address
		//---Mobile number
		
		//---NODE ID 
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[13].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[13].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
  				  strcpy(stnNode[node_count],"0");
				else	
				  strcpy(stnNode[node_count],strData.c_str());
			
				strcpy(stnStTypeNode[stTypeNode_count] ,stnNode[node_count]);
				stTypeNode_count++;
				
				node_count++;
				findSixth=true; 								
			}
		}

		else if( strcmp(strData.c_str(),"</Row>")  == 0  )
		{
		
			if(findFirst)
			{						
				if(!findSecond) // DUWA DID
				{
					strcpy(stnDuwa[duwa_count],"");
					duwa_count++;
				}
				if(!findSixth)// NODE 
				{
					strcpy(stnNode[node_count],"0");
					node_count++;
				}
				
				if(!findFourth) // fax callno
				{
					strcpy( stnFaxCallno[ifaxCallnoCount] , "empty");
					ifaxCallnoCount++;

					strcpy( stnAllFaxes[icountAllFax] , "empty" );
					icountAllFax++;
					
				}
				if(!findFifth) // fax did
				{
					strcpy( stnFaxDid[ifaxDidCount] ,  "empty"  );
					ifaxDidCount++;
					
					strcpy( stnAllFaxes[icountAllFax] ,  "empty"  );
					icountAllFax++;
				}	
				
				findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
			
			}
			
			findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
			
		}
		
		numberoflines++;
	      }//  END BLSTATION 
//-----------------------END STATIONS------------------------------------------------------------------------------------------	    
//------------------------LICENSES-----------------------------------------------------------------------------------------------
	      else if((blLicenses)  && (numLic > 0) )
	      {
		
		if ( ( strcmp(strCell.c_str(),xmlLicensesNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[0].headerrecord)!= 0 )  )			
		{
			if (strData =="empty")
			{
				firstEmpty=true;
				blLicenses = false;

			}
			else
			{
				firstEmpty=false;
				strcpy(stnLicnum[lic_count],strData.c_str());
				lic_count++;
				
				findFirst=true; 
			 }
		}
		
		//---NODE ID 
		else if ( ( strcmp(strCell.c_str(),xmlLicensesNameTable[12].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[12].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{									
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
  				  strcpy(stnNode[node_count],"0");
				else	
				  strcpy(stnNode[node_count],strData.c_str());
				node_count++;
			
				findSecond=true; 
			}
		}
		else if( strcmp(strData.c_str(),"</Row>")  == 0  )
		{
		
			if(findFirst)
			{						
				if(!findSecond)// NODE 
				{
					strcpy(stnNode[node_count],"0");
					node_count++;
				}
	
		 	}
			findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
		}		
		
		
	      
	      }// END LICENSES	      	
//-----------------------------GROUPS---------------------------------------------------------------------------------------------------	      
	      else if((blGroups)  && (numGroup > 0) )
	      {
							
		
		if ( ( strcmp(strCell.c_str(),xmlGroupsNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[0].headerrecord)!= 0 )  )			
		{			
			//if (strData =="empty")
			if ( strcmp(strData.c_str(),"empty") == 0 ) 
			{
				firstEmpty=true;
				blGroups = false;
			}
			else
			{
				firstEmpty=false;
				strcpy(stnNumber[num_count],strData.c_str());				
				num_count++;
				
				findFirst=true; 
			 }			
		}
		//-- DID duwa numbers 
		else if ( ( strcmp(strCell.c_str(),xmlGroupsNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[1].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
					strcpy(stnDuwa[duwa_count],"-");
				else
					   strcpy(stnDuwa[duwa_count],strData.c_str());
			
				duwa_count++;
				findSecond=true; 
			}
			
		}
		// Voicemail
		else if ( ( strcmp(strCell.c_str(),xmlGroupsNameTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[3].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{

			if(findFirst)
			{
				strcpy( stnVoicemail[num_count-1] , strData.c_str() );
			}						
		}
		
		//---NODE ID 
		else if ( ( strcmp(strCell.c_str(),xmlGroupsNameTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[4].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
  				  strcpy(stnNode[node_count],"0");
				else	
				strcpy(stnNode[node_count],strData.c_str());
			
				node_count++;
			
				if ( (strData.length() ==0) || (strData=="empty") )
				   curNode = 0;
				else			
				   curNode = atoi(strData.c_str());						
						
				/*
				if(curNode == 0)		
				{
					countNodeGroups++;			
					if( countNodeGroups >22)
					{
						   faults[0][0]++;
			      			   faults[faultrow][0]=3;
			   			   faults[faultrow][1]=num_count - numStation-numGroup+ 2;
						   faults[faultrow][2]=22;
						   faultrow++;	
					   }
				   }
				   */
				   findThird=true; 
			}
						
		}
		else if( strcmp(strData.c_str(),"</Row>")  == 0  )
		{
		
			if(findFirst)
			{						
				if(!findSecond) // DUWA DID
				{
					strcpy(stnDuwa[duwa_count],"");
					duwa_count++;
				}
				if(!findThird)// NODE 
				{
					strcpy(stnNode[node_count],"0");
					node_count++;
				}							
			}

		 	findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
		}	
		

		numberoflines++;
	      
	      }	      
//---------------------------VIRTUALS-------------------------------------------------------------------------------------------------------	      
	      else if((blVirtual)  &&  (numVirtual>0) )
	      {
	      	
		if ( ( strcmp(strCell.c_str(),xmlVirtualNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[0].headerrecord)!= 0 )  )			
		{			
			if ( strcmp(strData.c_str(),"empty") == 0 ) 
			{
				firstEmpty=true;
				blVirtual = false;
			}
			else
			{
				firstEmpty=false;
				strcpy(stnNumber[num_count],strData.c_str());
				num_count++;
				findFirst=true; 
			 }			
		}
		//-- DID duwa numbers 
		else if ( ( strcmp(strCell.c_str(),xmlVirtualNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[1].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
					strcpy(stnDuwa[duwa_count],"");
				else
					strcpy(stnDuwa[duwa_count],strData.c_str());
				duwa_count++;
				findSecond=true; 
			}
		}
		
		//------Station Type-----------------------------------
		else if ( ( strcmp(strCell.c_str(),xmlVirtualNameTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[3].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if( !strcmp(strData.c_str(),xmlVirtualStationTypes[0].name) )
				{
					syscountAutoAt++;
				}
				else if( !strcmp(strData.c_str(),xmlVirtualStationTypes[1].name) )
				{
					syscountCCFax++;
				}
				else if( !strcmp(strData.c_str(),xmlVirtualStationTypes[2].name) )
				{
					syscountPark++;
				}
				else if( !strcmp(strData.c_str(),xmlVirtualStationTypes[3].name) )
				{
					syscountConf++;
				}									
				else if( !strcmp(strData.c_str(),xmlVirtualStationTypes[4].name) )
				{
					sysCountFaxGroup++;
				}	
				else if( !strcmp(strData.c_str(),xmlVirtualStationTypes[5].name) )
				{
					sysCountVirtual++;
				}
				else if( !strcmp(strData.c_str(),xmlVirtualStationTypes[6].name) )
				{
					sysCountMeetMe++;
				}
				strcpy(stnStType[stType_count],strData.c_str());
				stType_count++;
			}
		}
		//---NODE ID 
		else if ( ( strcmp(strCell.c_str(),xmlVirtualNameTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[4].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
  				  strcpy(stnNode[node_count],"0");
				else	
				strcpy(stnNode[node_count],strData.c_str());	
				strcpy(stnStTypeNode[stTypeNode_count] ,stnNode[node_count]);
				stTypeNode_count++;


				node_count++;	
				findThird=true; 
			}
		}
		//---Secondary Gateway
		
		else if( strcmp(strData.c_str(),"</Row>")  == 0  )
		{
		
			if(findFirst)
			{						
				if(!findSecond) // DUWA DID
				{
					strcpy(stnDuwa[duwa_count],"");
					duwa_count++;
				}
				if(!findThird)// NODE 
				{
					strcpy(stnNode[node_count],"0");
					node_count++;
				}
			}
		 	findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
		}		

		numberoflines++;
	      
	      }//END VIRTUAL
      
//---------------------------TRUNKS-------------------------------------------------------------------------------------------------------	        	      	      
	      else if((blTrunkGroup) && (numTrnk>0))
	      {
		if ( ( strcmp(strCell.c_str(),xmlTrunkGrpNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlTrunkGrpNameTable[0].headerrecord)!= 0 )  )			
		{			
			if ( strcmp(strData.c_str(),"empty") == 0 ) 
			{
				firstEmpty=true;
				blTrunkGroup = false;
			}
			else
			{
				firstEmpty=false;
				strcpy(stnNumber[num_count],strData.c_str());				
				num_count++;
				findFirst=true; 
			 }			
		}
		//---NODE ID 
		else if ( ( strcmp(strCell.c_str(),xmlTrunkGrpNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlTrunkGrpNameTable[2].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
  				  strcpy(stnNode[node_count],"0");
				else				
				strcpy(stnNode[node_count],strData.c_str());
			
				node_count++;
			
				if ( (strData.length() ==0) || (strData=="empty") )
				   curNode = 0;
				else			
				   curNode = atoi(strData.c_str());
			
		
				if(curNode == 0 )
				{
					countNodeTrunksGr++;			
					if(countNodeTrunksGr >4)
					{
						   faults[0][0]++;
			      			   faults[faultrow][0]=5;
		   				   faults[faultrow][1]=num_count - numStation-numGroup-numVirtual+ 2;
						   faults[faultrow][2]=22;
						   faultrow++;
	  					//blTrunkGroup = false;
					}
				}
				findSecond=true;
			}
							
		}
		else if( strcmp(strData.c_str(),"</Row>")  == 0  )
		{
		
			if(findFirst)
			{						
				if(!findSecond)// NODE 
				{
					strcpy(stnNode[node_count],"0");
					node_count++;
				}
						
			}
		 	findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
		}	

		numberoflines++;

	      }
//---------------------------VOICEMAIL-------------------------------------------------------------------------------------------------------	      	      
	      else if((blVoicemail) && (numVoicemail>0) )
	      {
		
      		if ( ( strcmp(strCell.c_str(),xmlVoiceMailNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVoiceMailNameTable[0].headerrecord)!= 0 )  )			
		{			
			if ( strcmp(strData.c_str(),"empty") == 0 ) 
			{
				firstEmpty=true;
				blVoicemail = false;
			}
			else
			{
				firstEmpty=false;
				strcpy(stnNumber[num_count],strData.c_str());
				num_count++;
				findFirst=true; 
			 }			
		}
		//---NODE ID 
		else if ( ( strcmp(strCell.c_str(),xmlVoiceMailNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVoiceMailNameTable[2].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
  				  strcpy(stnNode[node_count],"0");
				else	
				strcpy(stnNode[node_count],strData.c_str());

				node_count++;			
			
				if ( (strData.length() ==0) || (strData=="empty") )
				   curNode = 0;
				else			
				   curNode = atoi(strData.c_str());						
						
				if(curNode == 0)		
				{
					countNodeVoicemail++;			
					if( countNodeVoicemail >1)
					{
						faults[0][0]++;
			      			   faults[faultrow][0]=6;
			   			   faults[faultrow][1]=num_count - numStation-numGroup-numVirtual-numTrnk+ 2;
						   faults[faultrow][2]=22;
						   faultrow++;	
					   }
				   }
				   findSecond=true; 
			}
			
		}
		else if( strcmp(strData.c_str(),"</Row>")  == 0  )
		{
		
			if(findFirst)
			{						
				if(!findSecond)// NODE 
				{
					strcpy(stnNode[node_count],"0");
					node_count++;
				}
			}
		 	findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
		}	
		
		numberoflines++;
	      } // END VOICE MAIL
	      	
	} //end If blEndRecord
		
	countLine++;//increase countLines number to numberring Lines   
	
    }// ----end while read lines-------

    fclose(fxml);

   	
	for(i=0; i<20; i++)
    	{
           dublicatepos[i]=0;	
    	}	

	//-------------------Check Double Records In INTERNAL NUMBERS -------------------------------------------
	// Check the Duplicates Numbers in Internal Numbers
	if(num_count > 0)
	{
		if(!checkdouble(stnNumber,num_count,dublicatepos))
		{
			for(i=0;i<20;i++)
			{
				if(faultrow!=21 && dublicatepos[i])
				{
				//numStation+numGroup+numVirtual+numTrnk+numVoicemail
					faults[0][0]++;								
					if (dublicatepos[i] <= numStation)
					{
					   faults[faultrow][0]=1;
					   faults[faultrow][1]=dublicatepos[i]+2;
					}
					else if( (dublicatepos[i] > numStation) && (dublicatepos[i] <= (numStation+numGroup) )  )
					{
					   faults[faultrow][0]=3;
					   faults[faultrow][1]=dublicatepos[i]-numStation+2;
					}
					else if(  (dublicatepos[i] > (numStation+numGroup) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual) ))  
					{
	 					faults[faultrow][0]=4;	
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup+ 2;									
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk) ))  
					{
	 					faults[faultrow][0]=5;						
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual+ 2;														
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual+numTrnk) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk+numVoicemail) ))  
					{
 						faults[faultrow][0]=6;		
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual-numTrnk+ 2;			
					}
					faults[faultrow][2]=CALL_NO_NOT_UNIQUE;
					faultrow++;	
				}
			}
		}
	}
    	for(i=0;i<20;i++)
    	{
           dublicatepos[i]=0;	
    	}
	
	/* Check doubledigits */
	if(num_count > 0)
	{
		if(!checkdoubledigits(stnNumber,num_count,dublicatepos))
		{
			for(i=0;i<20;i++)
			{
				if(faultrow!=21 && dublicatepos[i])
				{
				//numStation+numGroup+numVirtual+numTrnk+numVoicemail
					faults[0][0]++;								
					if (dublicatepos[i] <= numStation)
					{
					   faults[faultrow][0]=1;
					   faults[faultrow][1]=dublicatepos[i]+2;
					}
					else if( (dublicatepos[i] > numStation) && (dublicatepos[i] <= (numStation+numGroup) )  )
					{
					   faults[faultrow][0]=3;
					   faults[faultrow][1]=dublicatepos[i]-numStation+2;
					}
					else if(  (dublicatepos[i] > (numStation+numGroup) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual) ))  
					{
	 					faults[faultrow][0]=4;	
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup+ 2;									
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk) ))  
					{
	 					faults[faultrow][0]=5;						
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual+ 2;														
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual+numTrnk) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk+numVoicemail) ))  
					{
 						faults[faultrow][0]=6;		
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual-numTrnk+ 2;			
					}
					faults[faultrow][2]=CALL_NO_NOT_UNIQUE;
					faultrow++;	
				}
			}
		}
	}
    	for(i=0;i<20;i++)
    	{
           dublicatepos[i]=0;	
    	}	
	
	
	//-------------------Check Double Records In DID Numbers -------------------------------------------
	// Check the Did Numbers  for Doule records 
	if(duwa_count > 0)
	{
		if(!checkdouble(stnDuwa,duwa_count,dublicatepos))
		{
				for(i=0;i<20;i++)
				{
					if(faultrow!=21 && dublicatepos[i])
					{				
					//numStation+numGroup+numVirtual+numTrnk+numVoicemail	
					faults[0][0]++;								
					if (dublicatepos[i] <= numStation)
					{
					   faults[faultrow][0]=1;
					   faults[faultrow][1]=dublicatepos[i]+2;
					}
					else if( (dublicatepos[i] > numStation) && (dublicatepos[i] <= (numStation+numGroup) )  )
					{
					   faults[faultrow][0]=3;
					   faults[faultrow][1]=dublicatepos[i]-numStation+2;
					}
					else if(  (dublicatepos[i] > (numStation+numGroup) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual) ))  
					{
	 					faults[faultrow][0]=4;	
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup+ 2;									
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk) ))  
					{
	 					faults[faultrow][0]=5;					
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual+ 2;														
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual+numTrnk) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk+numVoicemail) ))  
					{
	 					faults[faultrow][0]=6;		
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual-numTrnk+ 2;			
					}
					faults[faultrow][2]=DUWA_NOT_UNIQUE;
					faultrow++;
				}
			}
		}
	}


	for(i=0;i<20;i++)
    	{
           dublicatepos[i]=0;	
    	}
	// Check the Did digits  for Doule 
	if(duwa_count > 0)
	{
		if(!checkdoubledigits(stnDuwa,duwa_count,dublicatepos))
		{
				for(i=0;i<20;i++)
				{
					if(faultrow!=21 && dublicatepos[i])
					{				
					//numStation+numGroup+numVirtual+numTrnk+numVoicemail	
					faults[0][0]++;								
					if (dublicatepos[i] <= numStation)
					{
					   faults[faultrow][0]=1;
					   faults[faultrow][1]=dublicatepos[i]+2;
					}
					else if( (dublicatepos[i] > numStation) && (dublicatepos[i] <= (numStation+numGroup) )  )
					{
					   faults[faultrow][0]=3;
					   faults[faultrow][1]=dublicatepos[i]-numStation+2;
					}
					else if(  (dublicatepos[i] > (numStation+numGroup) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual) ))  
					{
	 					faults[faultrow][0]=4;	
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup+ 2;									
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk) ))  
					{
	 					faults[faultrow][0]=5;					
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual+ 2;														
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual+numTrnk) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk+numVoicemail) ))  
					{
	 					faults[faultrow][0]=6;		
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual-numTrnk+ 2;			
					}
					faults[faultrow][2]=DUWA_NOT_UNIQUE;
					faultrow++;
				}
			}
		}
	}

	//------------sipConfig check double -------------------------
	for(i=0;i<20;i++)
    	{
           dublicatepos[i]=0;	
    	}
	// Check the Did digits  for Doule 
	if(icountSipConfig > 0)
	{
		if(!checkdoubledigits(stnSipConfig,icountSipConfig,dublicatepos))
		{
				for(i=0;i<20;i++)
				{
					if(faultrow!=21 && dublicatepos[i])
					{				
						
					faults[0][0]++;								
					if (dublicatepos[i] <= icountSipConfig)
					{
					   faults[faultrow][0]=5;/* tab index for sipconfig */
					   faults[faultrow][1]=dublicatepos[i]+2;
					}					
					faults[faultrow][2]=8888; /*new error definition */
					faultrow++;
				}
			}
		}
	}

	for(i=0;i<20;i++)
    	{
           dublicatepos[i]=0;	
    	}
	
	//------------Check Node Type If is valid or Mixed Up----------------------
	if(node_count > 0 )
	{
		if(!checkNodeType(stnNode,node_count,dublicatepos))
		{
		        for(i=0;i<20;i++)
			{
			 if(faultrow!=21 && dublicatepos[i])
			 {
				//numStation+numGroup+numVirtual+numTrnk+numVoicemail
				faults[0][0]++;								
				if (dublicatepos[i] <= numStation)
				{
				   faults[faultrow][0]=1;
				   faults[faultrow][1]=dublicatepos[i]+2;
					}
					else if( (dublicatepos[i] > numStation) && (dublicatepos[i] <= (numStation+numGroup) )  )
					{
					   faults[faultrow][0]=3;
					   faults[faultrow][1]=dublicatepos[i]-numStation+2;
					}
					else if(  (dublicatepos[i] > (numStation+numGroup) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual) ))  
					{
	 					faults[faultrow][0]=4;	
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup+ 2;									
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk) ))  
					{
 						faults[faultrow][0]=5;					
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual+ 2;														
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual+numTrnk) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk+numVoicemail) ))  
					{
	 					faults[faultrow][0]=6;		
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual-numTrnk+ 2;			
					}
					faults[faultrow][2]=NODE_ID_MIXUP;
					faultrow++;
					
				}
			}
		}
	}
	


       bool fre =   checkVoicemailNumbers( stnVoicemail, stnNode, num_count);
       if (!fre)
       {
       		faults[0][0]++;		 						
		faults[faultrow][0]=1;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANYVOICEMAIL_EVM;// ENUM 68 wrong format all filled or all empty
		faultrow++;	
       }
       
	//----Check Licenses Numbers-----------------------------
	//if(!checkLicensesNumbers(stnNumber,stnLicnum,num_count, lic_count,dublicatepos))
	if(stnLicnum>0)
	{
		if(!checkLicensesNumbers(stnNumber,stnLicnum,numStation, lic_count,dublicatepos))
		{
			for(i=0;i<20;i++)
				{
				if(faultrow!=21 && dublicatepos[i])
				{
					//numStation+numGroup+numVirtual+numTrnk+numVoicemail
					faults[0][0]++;								
					faults[faultrow][0]=2;
					faults[faultrow][1]=dublicatepos[i]+2;								
					faults[faultrow][2]= LIC_NOT_EXISTS; // ENUM 42
					faultrow++;	
				}
			}	
		
		}
	}

//     fclose(fwr);
 if(num_count > 0)
 {
       bool blCheckAccResult=false;
       
       	for(i=0;i<20;i++)
    	{
           dublicatepos[i]=0;	
    	}	
       
       
     if(countAccessAnalog > 0)
     {
       // -----------------Analog--------------------Check if All the Analog have Filled or Empty ------------------------------------------------------
       blCheckAccResult = checkAccessType(stnAccessAnalog, countAccessAnalog,dublicatepos,0,0); // Check Analog  Format Access Type
       if(!blCheckAccResult)
       {
	       for(i =0; i<20; i++)
	       {
			if(faultrow!=21 && dublicatepos[i])
			{
				faults[0][0]++;								
				faults[faultrow][0]=1;
				faults[faultrow][1]=dublicatepos[i]+3;								
				faults[faultrow][2]=WRONG_ACCESS_TYPE; // ENUM 66 wrong format all filled or all empty
				faultrow++;	
			}
		}
	}
       if(blCheckAccResult) 
       {
	       checkAccessType(stnAccessAnalog, countAccessAnalog,dublicatepos,0,1); // Check Analog  Slots
	       for(i =0; i<20; i++)
	       {
			if(faultrow!=21 && dublicatepos[i])
			{
				faults[0][0]++;								
				faults[faultrow][0]=1;
				faults[faultrow][1]=dublicatepos[i]+3;								
				faults[faultrow][2]=NO_ANALOG_SLOT; //  63 enum
				faultrow++;	
			}

       		}

	}
     }
	for(i=0;i<20;i++)
    	{
           dublicatepos[i]=0;	
    	}	

       //-----------------------UP0---------------------------- Check if All the UP0 have Filled or Empty --------------------------------------------------
      if(countAccessUP0 > 0 )
      {
        blCheckAccResult = checkAccessType(stnAccessUP0, countAccessUP0,dublicatepos,1,0); // Check UP0  Access Type Format 
       if(!blCheckAccResult)
       {
	       for(i =0; i<20; i++)
	       {
			if(faultrow!=21 && dublicatepos[i])
			{
				faults[0][0]++;								
				faults[faultrow][0]=1;
				faults[faultrow][1]=dublicatepos[i]+3;								
				faults[faultrow][2]=WRONG_ACCESS_TYPE; // ENUM 65 wrong format all filled or all empty
				faultrow++;	
			}
		}
       }

       if(blCheckAccResult)
       {      
	       checkAccessType(stnAccessUP0, countAccessUP0,dublicatepos,1,1); // Check UP0 Slot exists
	       for(i =0; i<20; i++)
	       {
			if(faultrow!=21 && dublicatepos[i])
			{
				faults[0][0]++;								
				faults[faultrow][0]=1;
				faults[faultrow][1]=dublicatepos[i]+3;								
				faults[faultrow][2]=NO_UP0_SLOT; //  64 enum	
				faultrow++;	
			}
	
	       }
	}
     }//if(countAccessUP0 > 0 )
     
     /*----------------------------Faxes Checks--------------------------------------------------------*/
	
	if(ifaxCallnoCount > 0)
	{
		if(!checkdouble(stnFaxCallno,ifaxCallnoCount,dublicatepos))
		{
			for(i=0;i<20;i++)
			{
				if(faultrow!=21 && dublicatepos[i])
				{
				//numStation+numGroup+numVirtual+numTrnk+numVoicemail
					faults[0][0]++;								
				        faults[faultrow][0]=1;
					faults[faultrow][1]=dublicatepos[i]+2;				
					faults[faultrow][2]=FAX_CALL_NOT_UNIQUE;
				        faultrow++;			
				}
			}
		}
		
		if(!checkdoubledigits(stnFaxCallno,ifaxCallnoCount,dublicatepos))
		{
			for(i=0;i<20;i++)
			{
				if(faultrow!=21 && dublicatepos[i])
				{
				//numStation+numGroup+numVirtual+numTrnk+numVoicemail
					faults[0][0]++;								
				        faults[faultrow][0]=1;
					faults[faultrow][1]=dublicatepos[i]+2;				
					faults[faultrow][2]=FAX_CALL_NOT_UNIQUE;
				        faultrow++;			
				}
			}
		}

		
	}

	if(ifaxDidCount > 0)
	{
		if(!checkdouble(stnFaxDid,ifaxDidCount,dublicatepos))
		{
			for(i=0;i<20;i++)
			{
				if(faultrow!=21 && dublicatepos[i])
				{
					faults[0][0]++;								
				        faults[faultrow][0]=1;
					faults[faultrow][1]=dublicatepos[i]+2;				
					faults[faultrow][2]=FAX_DID_NOT_UNIQUE;
				        faultrow++;			
				}
			}
		}
		if(!checkdoubledigits(stnFaxDid,ifaxDidCount,dublicatepos))
		{
			for(i=0;i<20;i++)
			{
				if(faultrow!=21 && dublicatepos[i])
				{
					faults[0][0]++;								
				        faults[faultrow][0]=1;
					faults[faultrow][1]=dublicatepos[i]+2;				
					faults[faultrow][2]=FAX_DID_NOT_UNIQUE;
				        faultrow++;			
				}
			}
		}
	}
	
	if(!checkFaxDuplicate(stnAllStations,stnFaxCallno,icountAllst, ifaxCallnoCount,dublicatepos))
	{
		for(i=0;i<20;i++)
		{
			if(faultrow!=21 && dublicatepos[i])
			{
				//numStation+numGroup+numVirtual+numTrnk+numVoicemail
				faults[0][0]++;								
				faults[faultrow][0]=1;
				faults[faultrow][1]=dublicatepos[i]+2;								
				faults[faultrow][2]= FAX_CALL_NOT_UNIQUE; 
				faultrow++;	
			}
		}			
	}
		
	
     
	     		
	if(ifaxDidCount>0)
	{
		if(!checkFaxDuplicate(stnAllStations,stnFaxDid,icountAllst, ifaxDidCount,dublicatepos))
		{
			for(i=0;i<20;i++)
				{
				if(faultrow!=21 && dublicatepos[i])
				{
					//numStation+numGroup+numVirtual+numTrnk+numVoicemail
					faults[0][0]++;								
					faults[faultrow][0]=1;
					faults[faultrow][1]=dublicatepos[i]+2;								
					faults[faultrow][2]= FAX_DID_NOT_UNIQUE; // ENUM 42
					faultrow++;	
				}
			}	
		
		}
	}
	
	
	if(ifaxDidCount>0)
	{
		if(!checkFaxDuplicate(stnAllStations,stnFaxDid,icountAllst, ifaxDidCount,dublicatepos))
		{
			for(i=0;i<20;i++)
				{
				if(faultrow!=21 && dublicatepos[i])
				{					
					faults[0][0]++;								
					faults[faultrow][0]=1;
					faults[faultrow][1]=dublicatepos[i]+2;								
					faults[faultrow][2]= FAX_DID_NOT_UNIQUE; // ENUM 42
					faultrow++;	
				}
			}	
		
		}
	}
	if(icountSipConfig > 0)
	{
	//bool checkSipConfigInStations(char **strStation, char **strSipConfig,int countStation, int countSipConfig, int* dubentries)
		if(!checkSipConfigInStations(stnSipStations,stnSipConfig,icountSip,icountSipConfig,dublicatepos))
		{
			for(i=0;i<20;i++)
				{
				if(faultrow!=21 && dublicatepos[i])
				{					
					faults[0][0]++;								
					faults[faultrow][0]=5; // tabshett SIpConfig
					faults[faultrow][1]=dublicatepos[i]+2;								
					faults[faultrow][2]= 8888; // new enum duplicate SipConfig
					faultrow++;	
				}
			}	
		
		}
	
	}
 
 }
  
   //--------------CHECK THE NUMBER OF RECORDS------------------------------------------------

   if(!blX1)
   checkNumberOfStations(syscountUp0,syscountAn,syscountDect,syscountIsdn);/*  Count he Number Of System Available Stations Ports*/
   

   
   
   sumNodeStationsType(stnStType,stnStTypeNode, stType_count , stSipCounter, stUp0Counter, stIpCounter, stRasCounter, stDeskCounter, stabCounter, stIsdnCounter, stDectCounter,syscountAutoAt, syscountCCFax, syscountPark, syscountConf ,sysCountFaxGroup , sysCountVirtual,stRasAdminCounter, stRasLicCounter,sysCountMeetMe);

  
  isumNodeStVir = stSipCounter+stUp0Counter+stIpCounter+stRasCounter+stDeskCounter+stabCounter+stIsdnCounter+stDectCounter+syscountAutoAt+syscountCCFax+syscountPark+syscountConf+sysCountFaxGroup+sysCountVirtual+sysCountMeetMe;

    
   if (blX1)	
   {   
     
     
     if(stSipCounter  > AMOUNT_IP_X1  )
     {
	faults[0][0]++;								
	faults[faultrow][0]=1;
	faults[faultrow][1]=999;								
	faults[faultrow][2]=TOO_MANY_SIP;
	faultrow++;
     }
     if(stUp0Counter > AMOUNT_UP0_X1)
     {
	faults[0][0]++;								
	faults[faultrow][0]=1;
	faults[faultrow][1]=999;								
	faults[faultrow][2]=TOO_MANY_UP0;
	faultrow++;
     
     }
     if(stIpCounter > AMOUNT_IP_X1 )
     {
	faults[0][0]++;								
	faults[faultrow][0]=1;
	faults[faultrow][1]=999;								
	faults[faultrow][2]=TOO_MANY_IP;
	faultrow++;
     }
     if(stRasCounter > AMAOUNT_RAS_X1) // TOO_MANY_RAS_REMOTE
     {
	faults[0][0]++;								
	faults[faultrow][0]=1;
	faults[faultrow][1]=999;								
	faults[faultrow][2]=TOO_MANY_RAS_REMOTE;
	faultrow++;

     }
     if(stDeskCounter>AMOUNT_IP_X1) // TOO_MANY_DESK
     {
	faults[0][0]++;								
	faults[faultrow][0]=1;
	faults[faultrow][1]=999;								
	faults[faultrow][2]=TOO_MANY_DESK;
	faultrow++;  
     }
     if(stabCounter > AMOUNT_ANALOG_X1) // TOO_MANY_ANALOG
     {
	faults[0][0]++;								
	faults[faultrow][0]=1;
	faults[faultrow][1]=999;								
	faults[faultrow][2]=TOO_MANY_ANALOG;
	faultrow++;     
     }     
     if(stIsdnCounter > AMOUNT_ISDN_X1) // TOO_MANY_ISDN
     {
	faults[0][0]++;								
	faults[faultrow][0]=1;
	faults[faultrow][1]=999;								
	faults[faultrow][2]=TOO_MANY_ISDN;
	faultrow++;     
     }
     if(stDectCounter > AMOUNT_DECT_X1 )//TOO_MANY_DECT
     {
	faults[0][0]++;								
	faults[faultrow][0]=1;
	faults[faultrow][1]=999;								
	faults[faultrow][2]=TOO_MANY_DECT;
	faultrow++;     
     }
     if(sysCountVirtual > AMAOUNT_VIRTUAL_X1)
     {
	faults[0][0]++;								
	faults[faultrow][0]=4;
	faults[faultrow][1]=253;								
	faults[faultrow][2]=TOO_MANY_STATIONS;
	faultrow++;
     }
     
     if( stSipCounter +stIsdnCounter+ stIpCounter >  AMOUNT_IP_X1)
     {	
     	faults[0][0]++;								
	faults[faultrow][0]=1;
	faults[faultrow][1]=999;								
	faults[faultrow][2]=TOO_MANY_STATIONS;
	faultrow++;	
     }
     if(numGroup > AMOUNT_GROUPS_X1)
     {
     	faults[0][0]++;								
	faults[faultrow][0]=3;
	faults[faultrow][1]=800;								
	faults[faultrow][2]=TOO_MANY_GROUPS;
	faultrow++;	
     
     }
     
   
    
				

   }
   else ///    In System X3x5x8
   {
   if(ifaxCallnoCount>500   ||  ifaxDidCount>500 )
   {
   
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=4;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_FAXES;
		faultrow++;			   	
	}
   }
   
   
   
   if( isumNodeStVir > 500 )
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=1;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_STATIONS;
		faultrow++;			   	
	}
    }
  
   
   if(  stRasAdminCounter >  1) // RAS-ADMIN
   {
	if(faultrow!=21)
	{
		faults[0][0]++;
		faults[faultrow][0]=1;	
		faults[faultrow][1]=999;	
		faults[faultrow][2]=TOO_MANY_RAS_ADMIN; 
		faultrow++;	
	}
   }
   
   if(  stRasLicCounter >  1)  // RAS-LIC
   {
	if(faultrow!=21)
	{	
		faults[0][0]++;
		faults[faultrow][0]=1;	
		faults[faultrow][1]=999;	
		faults[faultrow][2]=TOO_MANY_RAS_LIC; 
		faultrow++;	
	}
   }

   if(  stDectCounter >  syscountDect) 
   {
	if(faultrow!=21)
	{	
		faults[0][0]++;
		faults[faultrow][0]=1;	
		faults[faultrow][1]=999;	
		faults[faultrow][2]=TOO_MANY_DECT; /*42*/
		faultrow++;	
	}
   }


   if(  stDeskCounter >  AMOUNT_OF_IP_PORTS) 
   {
	if(faultrow!=21)
	{
		faults[0][0]++;
		faults[faultrow][0]=1;	
		faults[faultrow][1]=999;	
		faults[faultrow][2]= TOO_MANY_DESK;/*48*/  
		faultrow++;	
	}
   }
   
   
   if( stRasCounter > AMOUNT_OF_RAS_TOTAL)
   {			   	
	if(faultrow!=21)
	{		
		faults[0][0]++;
		faults[faultrow][0]=1;	
		faults[faultrow][1]=999;	
		faults[faultrow][2]=TOO_MANY_RAS_REMOTE;  
		faultrow++;		
	}
   }
   
   if( stIpCounter > AMOUNT_OF_IP_PORTS)
   {
	if(faultrow!=21)
	{
		faults[0][0]++;
		faults[faultrow][0]=1;	
		faults[faultrow][1]=999;	
		faults[faultrow][2]=TOO_MANY_IP;  
		faultrow++;	
	}
   }
   

   
   if( stUp0Counter > syscountUp0) // from system Card 
   {	
	if(faultrow!=21)
	{		
		faults[0][0]++;
		faults[faultrow][0]=1;	
		faults[faultrow][1]=999;	
		faults[faultrow][2]=TOO_MANY_UP0;  
		faultrow++;				   	
	}
   }

   if( stabCounter > syscountAn )
   {
	if(faultrow!=21)
	{	
		faults[0][0]++;
		faults[faultrow][0]=1;	
		faults[faultrow][1]=999;	
		faults[faultrow][2]=TOO_MANY_ANALOG;
		faultrow++;
	}
   }
   
   
   if( stIsdnCounter > syscountIsdn)
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=1;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_ISDN;
		faultrow++;	
	}
   }
   
   if( stSipCounter > AMOUNT_OF_IP_PORTS )
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=1;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_SIP;
		faultrow++;	
	}
   }

   if( syscountAutoAt > 500 )
   {
	if(faultrow!=21)
	{	
		faults[0][0]++;								
		faults[faultrow][0]=4;
		faults[faultrow][1]=999;								
		faults[faultrow][2]= TOO_MANY_VP_AUTO_ATTENDANT; 
		faultrow++;	
	}
   
   }
   if( syscountCCFax > 500 )
   {	
	if(faultrow!=21)
	{	
		faults[0][0]++;								
		faults[faultrow][0]=4;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_VP_AUTO_ATTENDANT; 
		faultrow++;
	}
   }
   
   if( syscountConf > 5000 )
   {

	if(faultrow!=21)	
	{
		faults[0][0]++;								
		faults[faultrow][0]=4;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_OSO_CONFERENCE; 
		faultrow++;	
	}
   }

   if( syscountPark > 500 )
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=4;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_PARK;
		faultrow++;			   	
	}
   }
   

   if( sysCountFaxGroup > 500 )
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=4;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_FAXGROUPS;
		faultrow++;			   	
	}
   }
   
   
   if(sysCountMeetMe  > 500) 
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=1;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_MEET_ME;
		faultrow++;			   	
	}         
   }
    
   
   /*
   if( sysCountVirtual > NUM_OF_LOG_TLN_PORT )
   {
	faults[0][0]++;								
	faults[faultrow][0]=4;
	faults[faultrow][1]=999;								
	faults[faultrow][2]=TOO_MANY_VIRTUAL;
	faultrow++;			   	
    }
   */
   
   } // end if no X1
   for(i=0;i<(numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic);i++)
   {
	delete []stnNumber[i];
	delete []stnDuwa[i];
	delete []stnNode[i];
	delete []stnStType[i];
	delete []stnStTypeNode[i];
	delete []stnAccessAnalog[i];
	delete []stnAccessUP0[i];
	delete []stnVoicemail[i];
	delete []stnFaxCallno[i];
	delete []stnFaxDid[i];
   }
   for(i=0; i<numLic; i++)
   {
   	delete []stnLicnum[i];
   }
   
   
    for(i=0;  i<numStation+1; i++)
    {
    	delete []stnSipStations[i];
    }
    for(i=0;  i<numSipConfig+1; i++)
    {
    	delete []stnSipConfig[i];
    }
   
   delete []stnNumber;
   delete []stnDuwa;
   delete []stnNode;
   delete []stnLicnum;
   delete []stnStType;
   delete []stnStTypeNode;
   delete []stnAccessAnalog;
   delete []stnAccessUP0;
   delete []stnVoicemail;
   delete []stnFaxCallno;
   delete []stnFaxDid;
   delete []stnSipStations;
   delete []stnSipConfig;
   
 
   
  if( faultrow <2 )
  {
     

     if(numStation > 0)
     {
	 blwriteXmlStations = writeXmlStations(fname, numStation, ievmCounter);   
     }
	  
     if(numVirtual >0 )
     {      	
	//blwriteXmlVirtual = writeXmlVirtuals(fname, numVirtual);   
     }
     
     if(numTrnk >0 )
     {
 //     	blwriteXmlTrunks = writeXmlTrunkGroups(fname, numTrnk);
     }	
     
     if(numVoicemail >0 ) 
     {
	//   blwriteXmlVoicemail = writeXmlVoiceMail(fname, numVoicemail);
     }
     
     if(numGroup >0) 
     {
   //    blwriteXmlGroups = writeXmlGroups(fname, numGroup, ievmCounter);
     }
     
     if(stnSipConfig>0)
     {
       blwritexmlSipConfig = writeXmlSipConfig(fname,numSipConfig);
     }
    
     
      if(numLic >0)  
     {
      div  = numLic/30;
      for(i=0; i <= div; i++)
      {
//	 writeXmlLicenses(fname,numLic,i);
      }
      
     }
     
	


  }
    
       
}
int retpos(char **input, const char *spick, int num)
{
  int i=0;
  for(i=0; i<num; i++)
  {
    if( strcmp( input[i], spick)  == 0)
    {
      return i;
    }
  }
  
  return -1;

}
bool writeXmlCustomer(char* fname, int numStations, int &voicemailCounter)
{
    
   char line [128]; 
    FILE *fxml = fopen(fname,"r");
    int fLast,fFirst,intLen,wksFound,findNameCell=0,findCell=0,countLine=0,wksRowFound,fFiltDb=0;
    string tempstr,totalstr,strData,strCell,tmpStrAccess ;  
    bool blStations=false,blCallFun=false;
    int i=0,pos=0,curRecord=0,curNodeAtoi=0,iSlot=0,iPort=0,iLogId=0,icurElement=0;	
    int phyPort;
    char **stnNumber,**stnDuwa,**stnDisplay,**stnStation,**stnEmail,**stnMobile,**stnNode,**stnGw,**stnAccessSlot,**stnAccessPort,**stnAccessLogId,**stnVoicemail, **stnFaxCallno, **stnFaxDid, **stnCos, **stnCallPick, **stnFaxName;
    char **logPorts,**sEmails,**sMobiles, **stnUCtype, **stnCallPickGr, **stnLastName,**stnFirstName, **stnOutlk, **stnUCclient,**stnUCfax, **stnConfServ,**stnMyAttend, **stnMyAgent, **stnAppLaunch,**stnTapi ;
     bool firstEmpty=false,secondEmpty=false,thirdEmpty=false,fourthEmpty=false,fifthEmpty=false,sixthEmpty=false,seventhEmpty=false,eighthEmpty=false,ninthEmpty=false,tenthEmpty=false,eleventhEmpty=false
    ,twelvthEmpty=false,therteenthEmpty=false,fourteenthEmpty=false,fifteenthEmpty=false,sixteenthEmpty=false,seventeenthEmpty=false,eighteenthEmpty=false,nineteenthEmpty=false,twentyteenthEmpty=false;
    bool findFirst=false,findSecond=false,findThird=false,findFourth=false,findFifth=false,findSixth=false,findSeventh=false,findEighth=false,findNinth=false,findTenth=false,findEleventh=false,findTwelvth=false,findTherteenth=false;
    bool findFourteenth=false,findFifteenth=false,findSixteenth=false,findSeventeenth=false,findEighteenth=false,findNingteenth=false,findtwenteenth=false;
    bool twentyoneEmpty=false,twentytwoEmpty=false,twentythreeEmpty=false,twentyfourEmpty=false,twentyfiveEmpty=false,twentysixEmpty=false,twentysevenEmpty=false,twentyEightEmpty=false,twentynineEmpty=false;
    bool findtwentyone=false,findtwentytwo=false,findtwentythree=false,findtwentyfour=false,findtwentyfive=false,findtwentysix=false,findtwentyseven=false,findtwentyEight=false,findtwentynine=false;       
    bool  blCellEnd=false,blEndRecord=false,search_only_free_ip=false;
    int  stSipCounter=0, stUp0Counter=0, stIpCounter=0, stRasCounter=0, stDeskCounter=0, stAnalogIndex=0, stIsdnCounter=0, stDectCounter=0, stRasAdminCounter=0, stRasLicCounter=0,iVslCounter=0;
    long filter=0;	
    RD_KDS_RETURN   kdsreturn,rdrecflag,rdgrp1evm,rdgrp2evm;;
    //WR_KDS_RETURN   wrreturn;
    char stnrufnr[50];
    int tblSize = 50,curp1=0;// RUFNR_SIZE*2;
    RD_KDS_RETURN	kdsretNode;
    int startIndexSip=0, startIndexIp=0,startIndexRas=0,startIndexDesk=0,icurNodeRecords=0,evmCounter=0,wFaxPort=-1;    
    int inhalt[500];
    int s0_idx; 
    char *tmpNumbers;
    //DB_OSO_PORTS    write_data; 
    RD_KDS_RETURN   uc_buffer;
    int grp;
    int retport = -1; 

	int STN_SINGLE_SET = 111;
                    
    numStations  = numStations+2;
    
    stnUCtype = new char*[numStations];
    stnCallPickGr = new char*[numStations];
    stnLastName = new char*[numStations];
    stnFirstName = new char*[numStations];
    stnOutlk = new char*[numStations];
    stnUCclient = new char*[numStations];
    stnUCfax = new char*[numStations];
    stnConfServ = new char*[numStations];
    stnMyAttend = new char*[numStations];
    stnMyAgent = new char*[numStations];
    stnAppLaunch = new char*[numStations];
    stnTapi = new char*[numStations];
    
        
    stnNumber = new char*[numStations];
    stnDuwa = new char*[numStations];
    stnDisplay = new char*[numStations];
    stnStation = new char*[numStations];
    stnEmail = new char*[numStations];
    stnMobile = new char*[numStations];
    stnNode = new char*[numStations];
    stnGw = new char*[numStations];
    stnAccessSlot= new char*[numStations];
    stnAccessPort= new char*[numStations];
    stnAccessLogId= new char*[numStations];
    stnVoicemail= new char*[numStations];
    stnFaxCallno= new char*[numStations];
    stnFaxDid= new char*[numStations];
    stnCos= new char*[numStations];
    stnCallPick= new char*[numStations];
    stnFaxName = new char*[numStations];
    
    for(i=0; i<numStations; i++)
    {	 
	stnNumber[i]= new char[tblSize];
	stnDuwa[i] =new char[tblSize];
    	stnDisplay[i] = new char[tblSize];
    	stnStation[i] = new char[tblSize];
    	stnEmail[i] = new char[MAX_EMAIL];
    	stnMobile[i] = new char[tblSize];
    	stnNode[i] = new char[tblSize];
    	stnGw[i] = new char[tblSize];
	stnAccessSlot[i] = new char[tblSize];
	stnAccessPort[i] = new char[tblSize];
	stnAccessLogId[i] = new char[tblSize];
	stnVoicemail[i] = new char[tblSize];
	stnFaxCallno[i] = new char[tblSize];
    	stnFaxDid[i] = new char[tblSize];
    	stnCos[i] = new char[tblSize];
    	stnCallPick[i] = new char[tblSize];
	stnFaxName[i] = new char[tblSize];
	
	stnUCtype[i] = new char[tblSize];
	stnCallPickGr[i] = new char[tblSize];
	stnLastName[i] = new char[tblSize];
	stnFirstName[i] = new char[tblSize];
	stnOutlk[i] = new char[tblSize];
	stnUCclient[i] = new char[tblSize];
	stnUCfax[i] = new char[tblSize];
	stnConfServ[i] = new char[tblSize];
	stnMyAttend[i] = new char[tblSize];
	stnMyAgent[i] = new char[tblSize];
	stnAppLaunch[i] = new char[tblSize];
	stnTapi[i] = new char[tblSize];
    }
  
    for(i=0; i<numStations; i++)
    {	
	for(pos=0; pos<tblSize; pos++)
	{
		stnNumber[i][pos]='\0';
		stnDuwa[i][pos]='\0';
    		stnDisplay[i][pos]='\0';
	    	stnStation[i][pos]='\0';	    	
	    	stnMobile[i][pos]='\0';
	    	stnNode[i][pos]='\0';
	    	stnGw[i][pos]='\0';
		stnAccessSlot[i][pos]='\0';
		stnAccessPort[i][pos]='\0';
		stnAccessLogId[i][pos]='\0';
		stnVoicemail[i][pos]='\0';
		stnFaxCallno[i][pos]='\0';
	    	stnFaxDid[i][pos]='\0';
    		stnCos[i][pos]='\0';
	    	stnCallPick[i][pos]='\0';
		stnFaxName[i][pos]='\0';
		
		stnUCtype[i][pos]='\0';
		stnCallPickGr[i][pos]='\0';
		stnLastName[i][pos]='\0';
		stnFirstName[i][pos]='\0';
		stnOutlk[i][pos]='\0';
		stnUCclient[i][pos]='\0';
		stnUCfax[i][pos]='\0';
		stnConfServ[i][pos]='\0';
		stnMyAttend[i][pos]='\0';
		stnMyAgent[i][pos]='\0';
		stnAppLaunch[i][pos]='\0';
		stnTapi[i][pos]='\0';
	}
	for(pos=0; pos<MAX_EMAIL; pos++)
	{
		stnEmail[i][pos]='\0';
	}
    }
    
//    Db_rddtb(KDS_NODE_ID,KEINE_ZEILE,KEINE_SPALTE,(RD_KDS_RETURN*)&kdsretNode);
    curNodeAtoi ==  1;// kdsretNode.inhalt[3] ;
    
    while(fgets ( line,128,fxml ) != NULL ) // read a line by line
    {
	
	tempstr=line; // this temp str contains the current line
	intLen = strlen(line);

	//---1-find----WorkSheet name ------------------------------
	wksFound= tempstr.find("Worksheet ss:Name");
	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
	        fFirst= tempstr.find("\"");
	        fLast=tempstr.find_last_of("\"");   
	        tempstr = tempstr.substr(fFirst+1,(fLast-(fFirst+1)));		

		if(tempstr == "Customer")
		{
	   	   blStations = true;
		}
    	}// end worksheet search 

	//---2 find the End of WorkSheet-------------
	wksFound= tempstr.find("</Worksheet>");
	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
		if(blStations)
		{
			blStations = false;
			break;
			//return true;
		}
	}
	
	blEndRecord = false;

	wksFound = tempstr.find("</Data>");
	findNameCell = tempstr.find("<NamedCell");
	findCell = tempstr.find("</Cell>");
	wksRowFound = tempstr.find("</Row>");
	fFiltDb = tempstr.find("FilterDatabase");
	//  CASE  A -- Check if the line is empty, has no data, only namedcell
	if((findNameCell > -1) && (wksFound == -1)  && (fFiltDb==-1) ) 
	{
		fLast = tempstr.find("</Cell>");
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		strData = "empty";
		blEndRecord = true;
	}
	// CASE B scenario we had Data and NameCell Filled in the Same Line 		
	else if( (wksFound > -1) && (findNameCell > -1)  && (findCell >-1) )
	{			
		fLast = tempstr.find("</Cell>");
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		fLast = wksFound;  //tempstr.find("</Data>");
		fFirst = tempstr.rfind("\">");
		strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));
		blEndRecord = true;
	}
	// CASE C -- Has Data and NameCell but the Cell END is in the next Line
	else if( (wksFound > -1) && (findNameCell > -1)  && (findCell == -1) )
	{
		fLast = wksFound;  //tempstr.find("</Data>");
		fFirst = tempstr.rfind("\">");
		strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));
		if(strData.length() == 0 )
				strData = "empty";
		blCellEnd = true; // wait the end of the Cell		
	}
	else if( (findCell > -1) &&  (blCellEnd)  ) // find the end of Cell
	{
		blCellEnd = false;
		fLast = tempstr.find("</Cell>"); 
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		blEndRecord = true;	
	}
	else if(wksRowFound > -1)	
	{
		blEndRecord = true;
		strData = "</Row>";
		strCell="";
	}
	
	if(blEndRecord)
	{
	  if(strCell != "_FilterDatabase")
	  icurElement++;
	 }

	// If the Record is OK
	if(blEndRecord)
	{
//-----------------------STATIONS------------------------------------------------------------------------------------------	    
	    if(blStations   &&  icurElement>35)
	    {				
		//---------------------------ID---nodeid------------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[0].element ) == 0 )  )				  
		{														
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    firstEmpty = true; 			    
			}
			else
			{
			  firstEmpty=false;
			  strcpy(stnNode[curRecord],strData.c_str());
			  findFirst = true;					    
			}					  
		}
		//------------------------UC TYPE---------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[2].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    secondEmpty  = true; 
			    
			    strcpy(stnUCtype[curRecord],"empty");
			}
			else
			{
			    secondEmpty = false;
			    findSecond = true;
			    strcpy(stnUCtype[curRecord],strData.c_str());
			}				
		}	
		//------------------------Call PickUp Groups---------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[3].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			     thirdEmpty = true; 
			      strcpy(stnCallPickGr[curRecord],"-1");
			}
			else
			{
			     thirdEmpty = false; 
			     findThird = true;
			     strcpy(stnCallPickGr[curRecord],strData.c_str());
			}					
		}	
		//--------------------LAST NAME-------------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[4].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    fourthEmpty = true; 
			    strcpy(stnLastName[curRecord],"");
			}
			else
			{
			    findFourth = true;					    
			    fourthEmpty = false;
			    strcpy(stnLastName[curRecord],strData.c_str());
			}
		}
		//--------------------FIRST NAME-------------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[5].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{				    
			    fifthEmpty = true;
			    strcpy(stnFirstName[curRecord],"");
			}
			else
			{			    
			    fifthEmpty = false;
			    findFifth = true;
			    strcpy(stnFirstName[curRecord],strData.c_str());
			}
		}
		//--------------------DISPLAY NAME-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[6].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    sixthEmpty = true; 
			    strcpy(stnDisplay[curRecord],"");
			}
			else
			{
			    findSixth = true;
			    sixthEmpty = false;
			    strcpy(stnDisplay[curRecord],strData.c_str());
			    						    
			    
			}
			
			if(sixthEmpty) //  If it is empty and has first or last name please fill the full name.
			{
				if(findFifth    ||  findFourth)
				{
				  if(findFifth  && findFourth )
				  {
					  strcpy(stnDisplay[curRecord], stnLastName[curRecord]);
					  strcat(stnDisplay[curRecord], ", ");
					  strcat(stnDisplay[curRecord], stnFirstName[curRecord]);
					  findSixth = true;
					  sixthEmpty = false;
				  }
				  else
				  {
					  strcpy(stnDisplay[curRecord], stnLastName[curRecord]);
					  strcat(stnDisplay[curRecord], " ");
					  strcat(stnDisplay[curRecord], stnFirstName[curRecord]);
					  findSixth = true;
					  sixthEmpty = false;
				  }
				  
				  
				  
				}
			
			}
								
		}
		//--------------------INTERNAL NUMBER-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[7].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    seventhEmpty = true;	
			    blStations = false;
			}
			else
			{
			    seventhEmpty = false;			    
			    findSeventh = true;
			    strcpy(stnNumber[curRecord],strData.c_str());
			}					
		}
		//--------------------DID-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[8].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    eighthEmpty = true;	
			    strcpy(stnDuwa[curRecord],"empty");
			}
			else
			{
			    eighthEmpty = false;			    
			    findEighth = true;
			    strcpy(stnDuwa[curRecord],strData.c_str());
			}					
		}
		
		//--------------------EMAIL-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[9].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    ninthEmpty = true;
			    strcpy(stnEmail[curRecord],"");
			}
			else
			{
			    ninthEmpty = false;			    
			    findNinth = true;
			    strcpy(stnEmail[curRecord],strData.c_str());
			}					
		}
		//--------------------MOBILE-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[10].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    tenthEmpty = true;		
			   strcpy(stnMobile[curRecord],"");
			}
			else
			{
			    tenthEmpty = false;			    
			    findTenth = true;
			    strcpy(stnMobile[curRecord],strData.c_str());
			}					
		}
		//--------------------DEVTYPE-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[11].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    eleventhEmpty = true;	
			    strcpy(stnStation[curRecord],"empty");
			}
			else
			{
			    eleventhEmpty = false;			    
			    findEleventh = true;
			    strcpy(stnStation[curRecord],strData.c_str());
			}					
		}
		
		//-------------------VOICEMAIL-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[12].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    twelvthEmpty = true;			    
			    strcpy(stnVoicemail[curRecord],"empty");
			}
			else
			{
			    twelvthEmpty = false;			    
			    findTwelvth = true;
			    strcpy(stnVoicemail[curRecord],strData.c_str());
			}					
		}
		
		//-------------------OUTLOOK ADDIN-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[13].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    therteenthEmpty = true;	
			    strcpy(stnOutlk[curRecord],"empty");
			}
			else
			{
			    therteenthEmpty = false;			    
			    findTherteenth = true;
			    strcpy(stnOutlk[curRecord],strData.c_str());
			}					
		}
		
		//-------------------UC client-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[14].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    fourteenthEmpty = true;			   
			    strcpy(stnUCclient[curRecord],"empty");
			}
			else
			{
			    fourteenthEmpty = false;			    
			    findFourteenth = true;
			    strcpy(stnUCclient[curRecord],strData.c_str());
			}					
		}
		
		//-------------------UC faxc-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[15].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    fifteenthEmpty = true;	
			    strcpy(stnUCfax[curRecord],"empty");
			}
			else
			{
			    fifteenthEmpty = false;			    
			    findFifteenth = true;
			    strcpy(stnUCfax[curRecord],strData.c_str());
			}					
		}
		
		//-------------------FAx callno-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[16].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    sixteenthEmpty = true;			    
			    strcpy(stnFaxCallno[curRecord],"empty");
			}
			else
			{
			    sixteenthEmpty = false;			    
			    findSixteenth = true;
			    strcpy(stnFaxCallno[curRecord],strData.c_str());
			}					
		}
		
		//-------------------FAx DID-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[17].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    seventeenthEmpty = true;	
			    strcpy(stnFaxDid[curRecord],"empty");
			}
			else
			{
			    seventeenthEmpty = false;			    
			    findSeventeenth = true;
			    strcpy(stnFaxDid[curRecord],strData.c_str());
			}					
		}
		
		//-------------------FAx NAme-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[18].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    eighteenthEmpty = true;			  
			    strcpy(stnFaxName[curRecord],"empty");
			}
			else
			{
			    eighteenthEmpty = false;			    
			    findEighteenth = true;
			    strcpy(stnFaxName[curRecord],strData.c_str());
			}					
		}
		
		
		//-------------------Conference Server-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[19].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    nineteenthEmpty = true;			   
			    strcpy(stnConfServ[curRecord],"empty");
			}
			else
			{
			    nineteenthEmpty = false;			    
			    findNingteenth = true;
			    strcpy(stnConfServ[curRecord],strData.c_str());
			}					
		}
		
		//-------------------MyAttendant-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[20].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    twentyteenthEmpty = true;
			    strcpy(stnMyAttend[curRecord],"empty");
			}
			else
			{
			    twentyteenthEmpty = false;			    
			    findtwenteenth = true;
			    strcpy(stnMyAttend[curRecord],strData.c_str());
			}					
		}
		
		//-------------------Myagent-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[21].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    twentyoneEmpty = true;
			    strcpy(stnMyAgent[curRecord],"empty");
			}
			else
			{
			    twentyoneEmpty = false;			    
			    findtwentyone = true;
			    strcpy(stnMyAgent[curRecord],strData.c_str());
			}					
		}
		
		//-------------------Application Launcher-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[22].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    twentytwoEmpty = true;	
			    strcpy(stnAppLaunch[curRecord],"empty");
			}
			else
			{
			    twentytwoEmpty = false;			    
			    findtwentytwo = true;
			    strcpy(stnAppLaunch[curRecord],strData.c_str());
			}					
		}
		
		//-------------------TAPI-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[23].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    twentythreeEmpty = true;			
			    strcpy(stnTapi[curRecord],"empty");
			}
			else
			{
			    twentythreeEmpty = false;			    
			    findtwentythree = true;
			    strcpy(stnTapi[curRecord],strData.c_str());
			}					
		}
		
		//-------------------COS-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[24].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    twentyfourEmpty = true;			
			    strcpy(stnCos[curRecord],"-1");
			}
			else
			{
			    twentyfourEmpty = false;			    
			    findtwentyfour = true;
			    strcpy(stnCos[curRecord],strData.c_str());
			}					
		}
		
		//-------------------CAllPickUp-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[25].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    twentyfiveEmpty = true;
			    strcpy(stnCallPick[curRecord],"-1");
			}
			else
			{
			    twentyfiveEmpty = false;			    
			    findtwentyfive = true;
			    /*curp1 = retpos(stnCallPickGr,strData.c_str());
			    string cxr = "";
			    cxr = curp1;
			    strcpy(stnCallPick[curRecord],cxr.c_str());
			    */
			    strcpy(stnCallPick[curRecord],strData.c_str());
			}					
		}
		
		//-------------------Secondary GW-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[27].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    twentysevenEmpty = true;			
			    strcpy(stnGw[curRecord],"empty");
			}
			else
			{
			    twentysevenEmpty = false;			    
			    findtwentyseven = true;
			    strcpy(stnGw[curRecord],strData.c_str());
			}					
		}
		
		//-------------------Access-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[28].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    twentyEightEmpty = true;			    
			}
			else
			{
			    twentyEightEmpty = false;			    
			    findtwentyEight = true;			    
			}
			
			if(findSeventh)
			{
				 
				tmpStrAccess = "";
				
				if((strcmp(strData.c_str(),"empty") ==0) ||  (strcmp(strData.c_str(),"-") == 0)  )
				{
					strcpy(stnAccessSlot[curRecord],"empty");
					strcpy(stnAccessPort[curRecord],"empty");
					strcpy(stnAccessLogId[curRecord],"empty"); 
				}
				else
				{
					string stra="";
					string strb="";
					string strc="";
					tmpStrAccess = strData.substr(0,strData.find(" "));
					
					stra = tmpStrAccess.substr(0,tmpStrAccess.find("-"));
					strb = tmpStrAccess.substr(tmpStrAccess.find("-")+1);
					//stra = strData.substr(0,strData.find("-"));
					//strb = strData.substr(strData.find("-")+ 1);
					tmpStrAccess = strData.substr(strData.find(" ")+1);

					strc = tmpStrAccess;
										
					strcpy( stnAccessSlot[curRecord] ,stra.c_str()); //strData.substr(0,strData.find("-").c_str(); // from Starto to the Position char '-'
					strcpy( stnAccessPort[curRecord] ,strb.c_str()); // strData.substr(strData.find("-")+ 1).c_str(); // from the position to the end
					strcpy( stnAccessLogId[curRecord] ,strc.c_str()); 												
				}
			}
		}
		
	     
		//------Else if End Row--- The Current Record Finished---------------------------
		else if( strcmp(strData.c_str(),"</Row>")  == 0  )
		{
			if( findSeventh) // If has Call Number 
			{       
			      if(!findFirst)// node Id entry
			      {
				  string snd="";
				  snd = curNodeAtoi;
				  strcpy(stnNode[curRecord],snd.c_str());
				  sprintf(stnNode[curRecord],"  %d ",kdsretNode.inhalt[3]);				  
				  
			      }
				
				if(!findtwentyEight)
				{
					strcpy(stnAccessSlot[curRecord],"empty");
					strcpy(stnAccessPort[curRecord],"empty");
					strcpy(stnAccessLogId[curRecord],"empty");
				}				
				
				curRecord++; 				
			}
			else
			{
			  blStations = false;
			}  
			
			findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; 
			findNinth=false; findTenth=false; findEleventh=false;	findTwelvth=false; findTherteenth =false; 
			findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;findTherteenth=false;				
			findFourteenth=false; findFifteenth=false; findSixteenth=false; findSeventeenth=false; findEighteenth=false; findNingteenth=false; findtwenteenth=false;
			findtwentyone=false; findtwentytwo=false; findtwentythree=false; findtwentyfour=false; findtwentyfive=false; findtwentysix=false; findtwentyseven=false; findtwentyEight=false; findtwentynine=false;
	
			firstEmpty=false; secondEmpty=false; thirdEmpty=false;   fourthEmpty=false;   fifthEmpty=false; sixthEmpty=false; seventhEmpty=false;   eighthEmpty=false;	
			ninthEmpty=false; tenthEmpty=false; eleventhEmpty=false; twelvthEmpty=false; therteenthEmpty=false;fourteenthEmpty=false; fifteenthEmpty=false; 
			sixteenthEmpty=false; seventeenthEmpty=false; eighteenthEmpty=false; nineteenthEmpty=false; twentyteenthEmpty=false;twentyoneEmpty=false; twentytwoEmpty=false;
			twentythreeEmpty=false; twentyfourEmpty=false; twentyfiveEmpty=false; twentysixEmpty=false; twentysevenEmpty=false; twentyEightEmpty=false; twentynineEmpty=false;
		}
	


	      }//  END BLSTATION 
//-----------------------END STATIONS------------------------------------------------------------------------------------------	    

	      	
	} //end If blEndRecord
		

	countLine++;//increase countLines number to numberring Lines   
	
    }  // ----end while read lines-------
    
    fclose(fxml);
    int k=0;

    for (i = 0; i < TLN_NAME_SIZE; i++)
    {
       rdgrp1evm.inhalt[i] = 255;
    }
    
 
    /*  --------------- Initiate VSL data------------------------------------------- */

    logPorts = new char*[numStations+2];
    sEmails = new char*[numStations+2];
    sMobiles = new char*[numStations+2];
    
    for(i=0; i<numStations+2; i++)
    {	 
		logPorts[i]= new char[tblSize];
		sEmails[i] =new char[MAX_EMAIL];
		sMobiles[i] = new char[tblSize];
    }
  
    for(i=0; i<numStations+2; i++)
    {	
	for(pos=0; pos<tblSize; pos++)
	{
		logPorts[i][pos]='\0';		
		sMobiles[i][pos]='\0';
	}
	for(pos=0; pos<MAX_EMAIL; pos++)
	{
		sEmails[i][pos]='\0';
	}
    }  
      	
       
	for(i=0;  i<numStations;  i++)
	{
	     	    
	    
	     // END IF IS THE CURRENT NODE 				
	}
	
	
	//-----Call function in order to update the database 	 

	
	

  int input0=0;
  int input1=1;
  int maxtime_secs=60;	

  int startLicIndex= 30;
  int endLicIndex= 30;
  time_t start,end;
  int ilocal=0;

    
  
//--------------------------starting write licenses ---------------------------------------------------------------------
for(i=0;  i<numStations;  i++)
{

  
}
//--------------------------end write licenses ---------------------------------------------------------------------------	
	
	

    	for(i=0;i<numStations;i++)
   	{
		delete []stnNumber[i];
		delete []stnDuwa[i];
		delete []stnDisplay[i];
		delete []stnStation[i];
		delete []stnEmail[i];
		delete []stnMobile[i];
		delete []stnNode[i];
		delete []stnGw[i];
		delete []stnAccessSlot[i];
		delete []stnAccessPort[i];
		delete []stnAccessLogId[i];
		delete []stnVoicemail[i];
		delete []stnFaxCallno[i];
		delete []stnFaxDid[i];
		delete []stnCos[i];
		delete []stnCallPick[i];
		delete []stnFaxName[i];
		
		delete []stnUCtype[i];
		delete []stnCallPickGr[i];
		delete []stnLastName[i];
		delete []stnFirstName[i];
		delete []stnOutlk[i];
		delete []stnUCclient[i];
		delete []stnUCfax[i];
		delete []stnConfServ[i];
		delete []stnMyAttend[i];
		delete []stnMyAgent[i];
		delete []stnAppLaunch[i];
		delete []stnTapi[i];
	}
	
	for(i=0;i<numStations+2;i++)
   	{
		delete []logPorts[i];
		delete []sEmails[i];
		delete []sMobiles[i];
	
	}
   
	delete []stnNumber;
	delete []stnDuwa;
	delete []stnDisplay;
	delete []stnStation;
	delete []stnEmail;
	delete []stnMobile;
	delete []stnNode;
	delete []stnGw;	   
	delete []stnAccessSlot; 
	delete []stnAccessPort; 
	delete []stnAccessLogId; 
	delete []stnVoicemail;
	delete []stnFaxCallno;
	delete []stnFaxDid;
	delete []stnCos;
	delete []stnCallPick;
	delete []stnFaxName;
	delete []logPorts;
	delete []sEmails;
	delete []sMobiles;
	
	delete []stnUCtype;
	delete []stnCallPickGr;
	delete []stnLastName;
	delete []stnFirstName;
	delete []stnOutlk;
	delete []stnUCclient;
	delete []stnUCfax;
	delete []stnConfServ;
	delete []stnMyAttend;
	delete []stnMyAgent;
	delete []stnAppLaunch;
	delete []stnTapi;

	
	voicemailCounter = evmCounter;
	
	
	
	
	
	if ( icurNodeRecords == 0 ) 
		return false;
	else
		return true;
}

bool writeXmlCustomer111(char* fname, int numStations, int &voicemailCounter)
{
    
   char line [128]; 
    FILE *fxml = fopen(fname,"r");
    int fLast,fFirst,intLen,wksFound,findNameCell=0,findCell=0,countLine=0,wksRowFound,fFiltDb=0;
    string tempstr,totalstr,strData,strCell,tmpStrAccess ;  
    bool blStations=false,blCallFun=false;
    int i=0,pos=0,curRecord=0,curNodeAtoi=0,iSlot=0,iPort=0,iLogId=0,icurElement=0;	
    int  phyPort;
    char **stnNumber,**stnDuwa,**stnDisplay,**stnStation,**stnEmail,**stnMobile,**stnNode,**stnGw,**stnAccessSlot,**stnAccessPort,**stnAccessLogId,**stnVoicemail, **stnFaxCallno, **stnFaxDid, **stnCos, **stnCallPick, **stnFaxName;
    char **logPorts,**sEmails,**sMobiles, **stnUCtype, **stnCallPickGr, **stnLastName,**stnFirstName, **stnOutlk, **stnUCclient,**stnUCfax, **stnConfServ,**stnMyAttend, **stnMyAgent, **stnAppLaunch,**stnTapi ;
     bool firstEmpty=false,secondEmpty=false,thirdEmpty=false,fourthEmpty=false,fifthEmpty=false,sixthEmpty=false,seventhEmpty=false,eighthEmpty=false,ninthEmpty=false,tenthEmpty=false,eleventhEmpty=false
    ,twelvthEmpty=false,therteenthEmpty=false,fourteenthEmpty=false,fifteenthEmpty=false,sixteenthEmpty=false,seventeenthEmpty=false,eighteenthEmpty=false,nineteenthEmpty=false,twentyteenthEmpty=false;
    bool findFirst=false,findSecond=false,findThird=false,findFourth=false,findFifth=false,findSixth=false,findSeventh=false,findEighth=false,findNinth=false,findTenth=false,findEleventh=false,findTwelvth=false,findTherteenth=false;
    bool findFourteenth=false,findFifteenth=false,findSixteenth=false,findSeventeenth=false,findEighteenth=false,findNingteenth=false,findtwenteenth=false;
    bool twentyoneEmpty=false,twentytwoEmpty=false,twentythreeEmpty=false,twentyfourEmpty=false,twentyfiveEmpty=false,twentysixEmpty=false,twentysevenEmpty=false,twentyEightEmpty=false,twentynineEmpty=false;
    bool findtwentyone=false,findtwentytwo=false,findtwentythree=false,findtwentyfour=false,findtwentyfive=false,findtwentysix=false,findtwentyseven=false,findtwentyEight=false,findtwentynine=false;       
    bool  blCellEnd=false,blEndRecord=false,search_only_free_ip=false;
    int  stSipCounter=0, stUp0Counter=0, stIpCounter=0, stRasCounter=0, stDeskCounter=0, stAnalogIndex=0, stIsdnCounter=0, stDectCounter=0, stRasAdminCounter=0, stRasLicCounter=0,iVslCounter=0;
    long filter=0;	
    RD_KDS_RETURN   kdsreturn,rdrecflag,rdgrp1evm,rdgrp2evm;;
    //WR_KDS_RETURN   wrreturn;
    char stnrufnr[50];
    int tblSize = 50,curp1=0;// RUFNR_SIZE*2;
    RD_KDS_RETURN	kdsretNode;
    int startIndexSip=0, startIndexIp=0,startIndexRas=0,startIndexDesk=0,icurNodeRecords=0,evmCounter=0,wFaxPort=-1;    
    int  inhalt[500];
    int  s0_idx; 
    char *tmpNumbers;
    //DB_OSO_PORTS    write_data; 
    RD_KDS_RETURN   uc_buffer;
    //DB_INHALT_T grp;
    int retport = -1; 
    numStations = numStations +2;

    stnUCtype = new char*[numStations];
    stnCallPickGr = new char*[numStations];
    stnLastName = new char*[numStations];
    stnFirstName = new char*[numStations];
    stnOutlk = new char*[numStations];
    stnUCclient = new char*[numStations];
    stnUCfax = new char*[numStations];
    stnConfServ = new char*[numStations];
    stnMyAttend = new char*[numStations];
    stnMyAgent = new char*[numStations];
    stnAppLaunch = new char*[numStations];
    stnTapi = new char*[numStations];
    
        
    stnNumber = new char*[numStations];
    stnDuwa = new char*[numStations];
    stnDisplay = new char*[numStations];
    stnStation = new char*[numStations];
    stnEmail = new char*[numStations];
    stnMobile = new char*[numStations];
    stnNode = new char*[numStations];
    stnGw = new char*[numStations];
    stnAccessSlot= new char*[numStations];
    stnAccessPort= new char*[numStations];
    stnAccessLogId= new char*[numStations];
    stnVoicemail= new char*[numStations];
    stnFaxCallno= new char*[numStations];
    stnFaxDid= new char*[numStations];
    stnCos= new char*[numStations];
    stnCallPick= new char*[numStations];
    stnFaxName = new char*[numStations];
    
    for(i=0; i<numStations; i++)
    {	 
	stnNumber[i]= new char[tblSize];
	stnDuwa[i] =new char[tblSize];
    	stnDisplay[i] = new char[tblSize];
    	stnStation[i] = new char[tblSize];
    	stnEmail[i] = new char[MAX_EMAIL];
    	stnMobile[i] = new char[tblSize];
    	stnNode[i] = new char[tblSize];
    	stnGw[i] = new char[tblSize];
	stnAccessSlot[i] = new char[tblSize];
	stnAccessPort[i] = new char[tblSize];
	stnAccessLogId[i] = new char[tblSize];
	stnVoicemail[i] = new char[tblSize];
	stnFaxCallno[i] = new char[tblSize];
    	stnFaxDid[i] = new char[tblSize];
    	stnCos[i] = new char[tblSize];
    	stnCallPick[i] = new char[tblSize];
	stnFaxName[i] = new char[tblSize];
	
	stnUCtype[i] = new char[tblSize];
	stnCallPickGr[i] = new char[tblSize];
	stnLastName[i] = new char[tblSize];
	stnFirstName[i] = new char[tblSize];
	stnOutlk[i] = new char[tblSize];
	stnUCclient[i] = new char[tblSize];
	stnUCfax[i] = new char[tblSize];
	stnConfServ[i] = new char[tblSize];
	stnMyAttend[i] = new char[tblSize];
	stnMyAgent[i] = new char[tblSize];
	stnAppLaunch[i] = new char[tblSize];
	stnTapi[i] = new char[tblSize];
    }
  
    for(i=0; i<numStations; i++)
    {	
	for(pos=0; pos<tblSize; pos++)
	{
		stnNumber[i][pos]='\0';
		stnDuwa[i][pos]='\0';
    		stnDisplay[i][pos]='\0';
	    	stnStation[i][pos]='\0';	    	
	    	stnMobile[i][pos]='\0';
	    	stnNode[i][pos]='\0';
	    	stnGw[i][pos]='\0';
		stnAccessSlot[i][pos]='\0';
		stnAccessPort[i][pos]='\0';
		stnAccessLogId[i][pos]='\0';
		stnVoicemail[i][pos]='\0';
		stnFaxCallno[i][pos]='\0';
	    	stnFaxDid[i][pos]='\0';
    		stnCos[i][pos]='\0';
	    	stnCallPick[i][pos]='\0';
		stnFaxName[i][pos]='\0';
		
		stnUCtype[i][pos]='\0';
		stnCallPickGr[i][pos]='\0';
		stnLastName[i][pos]='\0';
		stnFirstName[i][pos]='\0';
		stnOutlk[i][pos]='\0';
		stnUCclient[i][pos]='\0';
		stnUCfax[i][pos]='\0';
		stnConfServ[i][pos]='\0';
		stnMyAttend[i][pos]='\0';
		stnMyAgent[i][pos]='\0';
		stnAppLaunch[i][pos]='\0';
		stnTapi[i][pos]='\0';
	}
	for(pos=0; pos<MAX_EMAIL; pos++)
	{
		stnEmail[i][pos]='\0';
	}
    }
    
    //Db_rddtb(KDS_NODE_ID,KEINE_ZEILE,KEINE_SPALTE,(RD_KDS_RETURN*)&kdsretNode);
    curNodeAtoi == 3;//kdsretNode.inhalt[3] ;
    
    while(fgets ( line,128,fxml ) != NULL ) // read a line by line
    {
	
	tempstr=line; // this temp str contains the current line
	intLen = strlen(line);

	//---1-find----WorkSheet name ------------------------------
	wksFound= tempstr.find("Worksheet ss:Name");
	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
	        fFirst= tempstr.find("\"");
	        fLast=tempstr.find_last_of("\"");   
	        tempstr = tempstr.substr(fFirst+1,(fLast-(fFirst+1)));		

		if(tempstr == "Customer")
		{
	   	   blStations = true;
		}
    	}// end worksheet search 

	//---2 find the End of WorkSheet-------------
	wksFound= tempstr.find("</Worksheet>");
	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
		if(blStations)
		{
			blStations = false;
			break;
			//return true;
		}
	}
	
	blEndRecord = false;

	wksFound = tempstr.find("</Data>");
	findNameCell = tempstr.find("<NamedCell");
	findCell = tempstr.find("</Cell>");
	wksRowFound = tempstr.find("</Row>");
	fFiltDb = tempstr.find("FilterDatabase");
	//  CASE  A -- Check if the line is empty, has no data, only namedcell
	if((findNameCell > -1) && (wksFound == -1)  && (fFiltDb==-1) ) 
	{
		fLast = tempstr.find("</Cell>");
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		strData = "empty";
		blEndRecord = true;
	}
	// CASE B scenario we had Data and NameCell Filled in the Same Line 		
	else if( (wksFound > -1) && (findNameCell > -1)  && (findCell >-1) )
	{			
		fLast = tempstr.find("</Cell>");
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		fLast = wksFound;  //tempstr.find("</Data>");
		fFirst = tempstr.rfind("\">");
		strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));
		blEndRecord = true;
	}
	// CASE C -- Has Data and NameCell but the Cell END is in the next Line
	else if( (wksFound > -1) && (findNameCell > -1)  && (findCell == -1) )
	{
		fLast = wksFound;  //tempstr.find("</Data>");
		fFirst = tempstr.rfind("\">");
		strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));
		if(strData.length() == 0 )
				strData = "empty";
		blCellEnd = true; // wait the end of the Cell		
	}
	else if( (findCell > -1) &&  (blCellEnd)  ) // find the end of Cell
	{
		/*
		blCellEnd = false;
		fLast = tempstr.find("</Cell>"); 
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		blEndRecord = true;	
		*/
		int kl = tempstr.find("_FilterDatabase");
		if(kl>-1)
		{
			string koll = "ss:Name=_FilterDatabase/><NamedCell ss:Name=cos/></Cell>";
			int kp = tempstr.find("NamedCell");
			int klen = 9;
			tempstr = tempstr.substr(kp+klen, tempstr.length());
			
		}
		
		
		blCellEnd = false;
		fLast = tempstr.find("</Cell>"); 
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		blEndRecord = true;	
		


	}
	else if(wksRowFound > -1)	
	{
		blEndRecord = true;
		strData = "</Row>";
		strCell="";
	}
	
	if(blEndRecord)
	{
		if(strCell != "_FilterDatabase")
		icurElement++;
	}

			

	// If the Record is OK
	if(blEndRecord  )
	{
//-----------------------STATIONS------------------------------------------------------------------------------------------	    
	    if(blStations   &&  icurElement>35)
	    {				
		  cout << "\n  strCell=<<"<<strCell <<"   --- strData="<<strData<<endl;
			//---------------------------ID---nodeid------------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[0].element ) == 0 )  )				  
		{														
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    firstEmpty = true; 			    
			}
			else
			{
			  firstEmpty=false;
			  strcpy(stnNode[curRecord],strData.c_str());
			  findFirst = true;					    
			}					  
		}
		//------------------------UC TYPE---------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[2].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    secondEmpty  = true; 
			    strcpy(stnUCtype[curRecord],"-");
			}
			else
			{
			    secondEmpty = false;
			    findSecond = true;
			    strcpy(stnUCtype[curRecord],strData.c_str());
			}				
		}	
		//------------------------Call PickUp Groups---------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[3].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			     thirdEmpty = true; 
			      strcpy(stnCallPickGr[curRecord],"-");
			}
			else
			{
			     thirdEmpty = false; 
			     findThird = true;
			     strcpy(stnCallPickGr[curRecord],strData.c_str());
			}					
		}	
		//--------------------LAST NAME-------------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[4].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    fourthEmpty = true; 
			    strcpy(stnLastName[curRecord],"-");
			}
			else
			{
			    findFourth = true;					    
			    fourthEmpty = false;
			    strcpy(stnLastName[curRecord],strData.c_str());
			}
		}
		//--------------------FIRST NAME-------------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[5].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{				    
			    fifthEmpty = true;
			    strcpy(stnFirstName[curRecord],"-");
			}
			else
			{			    
			    fifthEmpty = false;
			    findFifth = true;
			    strcpy(stnFirstName[curRecord],strData.c_str());
			}
		}
		//--------------------DISPLAY NAME-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[6].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    sixthEmpty = true; 
			    strcpy(stnDisplay[curRecord],"-");
			}
			else
			{
			    findSixth = true;
			    sixthEmpty = false;
			    strcpy(stnDisplay[curRecord],strData.c_str());
			}	


			if(sixthEmpty) //  If it is empty and has first or last name please fill the full name.
			{
				if(findFifth    &&  findFourth)
				{
				  strcpy(stnDisplay[curRecord], stnLastName[curRecord]);
				  strcat(stnDisplay[curRecord], ", ");
				  strcat(stnDisplay[curRecord], stnFirstName[curRecord]);
				  
				  
				   findSixth = true;
				    sixthEmpty = false;
				}
			
			}



		}
		//--------------------INTERNAL NUMBER-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[7].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    seventhEmpty = true;	
			    blStations = false;
			}
			else
			{
			    seventhEmpty = false;			    
			    findSeventh = true;
			    strcpy(stnNumber[curRecord],strData.c_str());
			}					
		}
		//--------------------DID-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[8].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    eighthEmpty = true;	
			     strcpy(stnDuwa[curRecord],"-");
			}
			else
			{
			    eighthEmpty = false;			    
			    findEighth = true;
			    strcpy(stnDuwa[curRecord],strData.c_str());
			}					
		}
		
		//--------------------EMAIL-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[9].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    ninthEmpty = true;
			    strcpy(stnEmail[curRecord],"-");
			}
			else
			{
			    ninthEmpty = false;			    
			    findNinth = true;
			    strcpy(stnEmail[curRecord],strData.c_str());
			}					
		}
		//--------------------MOBILE-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[10].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    tenthEmpty = true;		
			    strcpy(stnMobile[curRecord],"-");
			}
			else
			{
			    tenthEmpty = false;			    
			    findTenth = true;
			    strcpy(stnMobile[curRecord],strData.c_str());
			}					
		}
		//--------------------DEVTYPE-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[11].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    eleventhEmpty = true;	
			    strcpy(stnStation[curRecord],"-");
			}
			else
			{
			    eleventhEmpty = false;			    
			    findEleventh = true;
			    strcpy(stnStation[curRecord],strData.c_str());
			}					
		}
		
		//-------------------VOICEMAIL-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[12].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    twelvthEmpty = true;			    
			    strcpy(stnVoicemail[curRecord],"-");
			}
			else
			{
			    twelvthEmpty = false;			    
			    findTwelvth = true;
			    strcpy(stnVoicemail[curRecord],strData.c_str());
			}					
		}
		
		//-------------------OUTLOOK ADDIN-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[13].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    therteenthEmpty = true;	
			    strcpy(stnOutlk[curRecord],"-");
			}
			else
			{
			    therteenthEmpty = false;			    
			    findTherteenth = true;
			    strcpy(stnOutlk[curRecord],strData.c_str());
			}					
		}
		
		//-------------------UC client-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[14].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    fourteenthEmpty = true;			   
			    strcpy(stnUCclient[curRecord],"-");
			}
			else
			{
			    fourteenthEmpty = false;			    
			    findFourteenth = true;
			    strcpy(stnUCclient[curRecord],strData.c_str());
			}					
		}
		
		//-------------------UC faxc-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[15].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    fifteenthEmpty = true;	
			    strcpy(stnUCfax[curRecord],"-");
			}
			else
			{
			    fifteenthEmpty = false;			    
			    findFifteenth = true;
			    strcpy(stnUCfax[curRecord],strData.c_str());
			}					
		}
		
		//-------------------FAx callno-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[16].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    sixteenthEmpty = true;			    
			    strcpy(stnFaxCallno[curRecord],"-");
			}
			else
			{
			    sixteenthEmpty = false;			    
			    findSixteenth = true;
			    strcpy(stnFaxCallno[curRecord],strData.c_str());
			}					
		}
		
		//-------------------FAx DID-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[17].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    seventeenthEmpty = true;	
			    strcpy(stnFaxDid[curRecord],"-");
			}
			else
			{
			    seventeenthEmpty = false;			    
			    findSeventeenth = true;
			    strcpy(stnFaxDid[curRecord],strData.c_str());
			}					
		}
		
		//-------------------FAx NAme-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[18].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    eighteenthEmpty = true;			  
			    strcpy(stnFaxName[curRecord],"-");
			}
			else
			{
			    eighteenthEmpty = false;			    
			    findEighteenth = true;
			    strcpy(stnFaxName[curRecord],strData.c_str());
			}					
		}
		
		
		//-------------------Conference Server-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[19].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    nineteenthEmpty = true;			   
			    strcpy(stnConfServ[curRecord],"-");
			}
			else
			{
			    nineteenthEmpty = false;			    
			    findNingteenth = true;
			    strcpy(stnConfServ[curRecord],strData.c_str());
			}					
		}
		
		//-------------------MyAttendant-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[20].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    twentyteenthEmpty = true;
			    strcpy(stnMyAttend[curRecord],"-");
			}
			else
			{
			    twentyteenthEmpty = false;			    
			    findtwenteenth = true;
			    strcpy(stnMyAttend[curRecord],strData.c_str());
			}					
		}
		
		//-------------------Myagent-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[21].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    twentyoneEmpty = true;
			    strcpy(stnMyAgent[curRecord],"-");
			}
			else
			{
			    twentyoneEmpty = false;			    
			    findtwentyone = true;
			    strcpy(stnMyAgent[curRecord],strData.c_str());
			}					
		}
		
		//-------------------Application Launcher-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[22].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    twentytwoEmpty = true;	
			    strcpy(stnAppLaunch[curRecord],"-");
			}
			else
			{
			    twentytwoEmpty = false;			    
			    findtwentytwo = true;
			    strcpy(stnAppLaunch[curRecord],strData.c_str());
			}					
		}
		
		//-------------------TAPI-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[23].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    twentythreeEmpty = true;			
			    strcpy(stnTapi[curRecord],"-");
			}
			else
			{
			    twentythreeEmpty = false;			    
			    findtwentythree = true;
			    strcpy(stnTapi[curRecord],strData.c_str());
			}					
		}
		
		//-------------------COS-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[24].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    twentyfourEmpty = true;			
			    strcpy(stnCos[curRecord],"-");
			}
			else
			{
			    twentyfourEmpty = false;			    
			    findtwentyfour = true;
			    strcpy(stnCos[curRecord],strData.c_str());
			}					
		}
		
		//-------------------CAllPickUp-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[25].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    twentyfiveEmpty = true;
			    strcpy(stnCallPick[curRecord],"-");
			}
			else
			{
			    twentyfiveEmpty = false;			    
			    findtwentyfive = true;
			    /*curp1 = retpos(stnCallPickGr,strData.c_str());
			    string cxr = "";
			    cxr = curp1;
			    strcpy(stnCallPick[curRecord],cxr.c_str());
			    */
			    strcpy(stnCallPick[curRecord],strData.c_str());
			}					
		}
		
		//-------------------Secondary GW-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[27].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    twentysevenEmpty = true;			
			    strcpy(stnGw[curRecord],"-");
			}
			else
			{
			    twentysevenEmpty = false;			    
			    findtwentyseven = true;
			    strcpy(stnGw[curRecord],strData.c_str());
			}					
		}
		
		//-------------------Access-----------------------------------------------------
		if( ( strcmp(strCell.c_str(),xmlUsaElements[28].element ) == 0 )  )				  
		{
			if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
			{	
			    twentyEightEmpty = true;			    
			}
			else
			{
			    twentyEightEmpty = false;			    
			    findtwentyEight = true;			    
			}
			
			if(findSeventh)
			{
				
				tmpStrAccess = "";
				
				if((strcmp(strData.c_str(),"empty") ==0) ||  (strcmp(strData.c_str(),"-") == 0)  )
				{
					strcpy(stnAccessSlot[curRecord],"empty");
					strcpy(stnAccessPort[curRecord],"empty");
					strcpy(stnAccessLogId[curRecord],"empty"); 
				}
				else
				{
					string stra="";
					string strb="";
					string strc="";
					tmpStrAccess = strData.substr(0,strData.find(" "));
					
					stra = tmpStrAccess.substr(0,tmpStrAccess.find("-"));
					strb = tmpStrAccess.substr(tmpStrAccess.find("-")+1);
					//stra = strData.substr(0,strData.find("-"));
					//strb = strData.substr(strData.find("-")+ 1);
					tmpStrAccess = strData.substr(strData.find(" ")+1);

					strc = tmpStrAccess;
										
					strcpy( stnAccessSlot[curRecord] ,stra.c_str()); //strData.substr(0,strData.find("-").c_str(); // from Starto to the Position char '-'
					strcpy( stnAccessPort[curRecord] ,strb.c_str()); // strData.substr(strData.find("-")+ 1).c_str(); // from the position to the end
					strcpy( stnAccessLogId[curRecord] ,strc.c_str()); 												
				}
			}
		}
		
	     
		//------Else if End Row--- The Current Record Finished---------------------------
		else if( strcmp(strData.c_str(),"</Row>")  == 0  )
		{
			if( findSeventh) // If has Call Number 
			{       
			      if(!findFirst)// node Id entry
			      {
				  string snd="";
				  snd = curNodeAtoi;
				  strcpy(stnNode[curRecord],snd.c_str());
			      }
				
				if(!findEleventh)
				{
					strcpy(stnAccessSlot[curRecord],"empty");
					strcpy(stnAccessPort[curRecord],"empty");
					strcpy(stnAccessLogId[curRecord],"empty");
				}				
				
				curRecord++; 				
			}
			else
			{
			  blStations = false;
			}  
			
			findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; 
			findNinth=false; findTenth=false; findEleventh=false;	findTwelvth=false; findTherteenth =false; 
			findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;findTherteenth=false;				
			findFourteenth=false; findFifteenth=false; findSixteenth=false; findSeventeenth=false; findEighteenth=false; findNingteenth=false; findtwenteenth=false;
			findtwentyone=false; findtwentytwo=false; findtwentythree=false; findtwentyfour=false; findtwentyfive=false; findtwentysix=false; findtwentyseven=false; findtwentyEight=false; findtwentynine=false;
	
			firstEmpty=false; secondEmpty=false; thirdEmpty=false;   fourthEmpty=false;   fifthEmpty=false; sixthEmpty=false; seventhEmpty=false;   eighthEmpty=false;	
			ninthEmpty=false; tenthEmpty=false; eleventhEmpty=false; twelvthEmpty=false; therteenthEmpty=false;fourteenthEmpty=false; fifteenthEmpty=false; 
			sixteenthEmpty=false; seventeenthEmpty=false; eighteenthEmpty=false; nineteenthEmpty=false; twentyteenthEmpty=false;twentyoneEmpty=false; twentytwoEmpty=false;
			twentythreeEmpty=false; twentyfourEmpty=false; twentyfiveEmpty=false; twentysixEmpty=false; twentysevenEmpty=false; twentyEightEmpty=false; twentynineEmpty=false;
		}
	


	      }//  END BLSTATION 
//-----------------------END STATIONS------------------------------------------------------------------------------------------	    

	      	
	} //end If blEndRecord
		

	countLine++;//increase countLines number to numberring Lines   
	
    }  // ----end while read lines-------
    
    fclose(fxml);
    int k=0;

   
    /*  --------------- Initiate VSL data------------------------------------------- */

    logPorts = new char*[numStations+2];
    sEmails = new char*[numStations+2];
    sMobiles = new char*[numStations+2];
    
    for(i=0; i<numStations+2; i++)
    {	 
		logPorts[i]= new char[tblSize];
		sEmails[i] =new char[MAX_EMAIL];
		sMobiles[i] = new char[tblSize];
    }
  
    for(i=0; i<numStations+2; i++)
    {	
	for(pos=0; pos<tblSize; pos++)
	{
		logPorts[i][pos]='\0';		
		sMobiles[i][pos]='\0';
	}
	for(pos=0; pos<MAX_EMAIL; pos++)
	{
		sEmails[i][pos]='\0';
	}
    }  
      
	for(i=0;  i<numStations; i++)
	{
	printf("\n  (stnNumber[%d]=%s)-(stnDuwa[%d]=%s )-(stnDisplay[%d]=%s)-(stnStation[%d]=%s)-(stnEmail[%d]=%s) \n",i,stnNumber[i],i,stnDuwa[i],i,stnDisplay[i], i, stnStation[i],i,stnEmail[i]);
	}



	for(i=0;  i<numStations; i++)
	{
	printf("\n  (stnNumber[%d]=%s)-(stnDuwa[%d]=%s ) \n",i,stnNumber[i],i,stnDuwa[i]);
	printf("\n   stnUCtype[i]=%s,\n  stnOutlk[i]=%s,\n  stnUCclient[i]=%s,\n  stnUCfax[i]=%s,\n  stnConfServ[i]=%s, \n stnMyAttend[i]=%s,\n stnMyAgent[i]=%s,\n  stnAppLaunch[i]=%s,\n  stnTapi[i]=%s",		
		stnUCtype[i],stnOutlk[i],stnUCclient[i],stnUCfax[i], stnConfServ[i],stnMyAttend[i],stnMyAgent[i],stnAppLaunch[i],stnTapi[i]);
	}

	/*
	stnUCtype[i] = new char[tblSize];
	stnCallPickGr[i] = new char[tblSize];
	stnLastName[i] = new char[tblSize];
	stnFirstName[i] = new char[tblSize];
	stnOutlk[i] = new char[tblSize];
	stnUCclient[i] = new char[tblSize];
	stnUCfax[i] = new char[tblSize];
	stnConfServ[i] = new char[tblSize];
	stnMyAttend[i] = new char[tblSize];
	stnMyAgent[i] = new char[tblSize];
	stnAppLaunch[i] = new char[tblSize];
	stnTapi[i] = new char[tblSize];
	
	*/




	for(i=0;  i<numStations;  i++)
	{
	     	    
	    curNodeAtoi = atoi(stnNode[i]);    
  	     if(curNodeAtoi == 0)//kdsretNode.inhalt[3] ) // Means The Same Node As the System  
  	     {
		icurNodeRecords++;  
		printf("\n  (stnNumber[%d]=%s)-(stnDuwa[%d]=%s )-(stnDisplay[%d]=%s)-(stnStation[%d]=%s)-(stnEmail[%d]=%s) ",i,stnNumber[i],i,stnDuwa[i],i,stnDisplay[i], i, stnStation[i],i,stnEmail[i]);
		if((strcmp(stnDuwa[i],"x" )  ==0) || (strcmp(stnDuwa[i],"X" )  ==0)  )
		{
		  strcpy(stnDuwa[i],stnNumber[i] );
		}
		
		if((strcmp(stnFaxDid[i],"x" )  ==0) || (strcmp(stnFaxDid[i],"X" )  ==0)  )
		{
		  strcpy(stnFaxDid[i],stnFaxCallno[i] );
		}
		
		if( strcmp(stnDisplay[i],"&lt;auto&gt;" )  ==0  )
		{		  
		  strcpy(stnDisplay[i], stnLastName[i]);
		  strcat(stnDisplay[i], " ");
		  strcat(stnDisplay[i], stnFirstName[i]);
		  
		}
		
		curp1 = -1;
		
		if(numStations <64)
		  	curp1 = retpos(stnCallPickGr,stnCallPick[i],numStations);
		else
			curp1 = retpos(stnCallPickGr,stnCallPick[i],64);
		if(curp1 != -1)
		  curp1++;
		
		
		char  cxr[50] ;	
		sprintf(cxr,"  %d ",curp1);
		strcpy(stnCallPick[i],cxr);

		sprintf(cxr,"  %s ","-1");
		//-------------COS  --------------------------------------
		if(strcmp(stnCos[i],"internal")  ==0 )
		{
		  //cxr[50] = "";
		  sprintf(cxr,"  %s ","1");
		  strcpy( stnCos[i] , cxr);
		}
		else if(strcmp(stnCos[i],"national")  ==0 )
		{
		  sprintf(cxr,"  %s ","6");
		  strcpy( stnCos[i] , cxr);
		}
		else if(strcmp(stnCos[i],"international")  ==0 )
		{
		  sprintf(cxr,"  %s ","7");
		  strcpy( stnCos[i] , cxr);
		}
		else 
		{
		  sprintf(cxr,"  %s ","-1");
		  strcpy( stnCos[i] , cxr);
		}
		
		
	
	    } // END IF IS THE CURRENT NODE 				
		

}
//--------------------------end write licenses ---------------------------------------------------------------------------	
	


for(i=0;i<numStations;i++)
   	{
		delete []stnNumber[i];
		delete []stnDuwa[i];
		delete []stnDisplay[i];
		delete []stnStation[i];
		delete []stnEmail[i];
		delete []stnMobile[i];
		delete []stnNode[i];
		delete []stnGw[i];
		delete []stnAccessSlot[i];
		delete []stnAccessPort[i];
		delete []stnAccessLogId[i];
		delete []stnVoicemail[i];
		delete []stnFaxCallno[i];
		delete []stnFaxDid[i];
		delete []stnCos[i];
		delete []stnCallPick[i];
		delete []stnFaxName[i];
		
		delete []stnUCtype[i];
		delete []stnCallPickGr[i];
		delete []stnLastName[i];
		delete []stnFirstName[i];
		delete []stnOutlk[i];
		delete []stnUCclient[i];
		delete []stnUCfax[i];
		delete []stnConfServ[i];
		delete []stnMyAttend[i];
		delete []stnMyAgent[i];
		delete []stnAppLaunch[i];
		delete []stnTapi[i];
	}
	
	for(i=0;i<numStations+2;i++)
   	{
		delete []logPorts[i];
		delete []sEmails[i];
		delete []sMobiles[i];
	
	}
   
	delete []stnNumber;
	delete []stnDuwa;
	delete []stnDisplay;
	delete []stnStation;
	delete []stnEmail;
	delete []stnMobile;
	delete []stnNode;
	delete []stnGw;	   
	delete []stnAccessSlot; 
	delete []stnAccessPort; 
	delete []stnAccessLogId; 
	delete []stnVoicemail;
	delete []stnFaxCallno;
	delete []stnFaxDid;
	delete []stnCos;
	delete []stnCallPick;
	delete []stnFaxName;
	delete []logPorts;
	delete []sEmails;
	delete []sMobiles;
	
	delete []stnUCtype;
	delete []stnCallPickGr;
	delete []stnLastName;
	delete []stnFirstName;
	delete []stnOutlk;
	delete []stnUCclient;
	delete []stnUCfax;
	delete []stnConfServ;
	delete []stnMyAttend;
	delete []stnMyAgent;
	delete []stnAppLaunch;
	delete []stnTapi;

	
	voicemailCounter = evmCounter;
	
	if ( icurNodeRecords == 0 ) 
		return false;
	else
		return true;
}



bool checkDevType(const char* strTypes)
{
     int i,k=0;
     
 
     for(i=0; i <14; i++)
     {
     	if( strcmp(strTypes,xmlDevType[i].name)  == 0 )
	k++;	
     }	
     
     if (k>0)
     return      true;
     else
     return false;
 
 }

int  checkXmlFormatErrorsUsa11(char* fname, int type[7], int errorCount,int faults[21][3], bool blBooster)
{
    char line [128]; 
    char *tmpNumbers;
    FILE *fxml = fopen(fname,"r");
    int fLast,fFirst,intLen,wksFound,findNameCell=0,findCell=0,countLine=0,rowCount=0,result=-1,wksRowFound,corXml=0,klen=0,fFiltDb=0,uc_count=0,icurrentrow=0;
    string tempstr,totalstr,strData,strCell,strtmpNumDid="",strtmpFaxDid="";  
    //bool blStations=false,blCellEnd=false,blEndRecord=false,blX1=false;    
    int i=0,pos=0,numStations=0,numLicenses=0,numGroups=0,numVoicemail=0,numVirtual=0,numTrunkGroups=0,numberoflines=1,faultrow=1,record=0,block=0,numSipConfig=0,icountCallPick=0;
    bool blStations=false,blLicenses=false,blGroups=false,blVirtual=false,blTrunkGroup=false,blVoicemail=false,blCellEnd=false,blEndRecord=false,blX1=false,blSipConfig=false;
    bool firstEmpty=false,secondEmpty=false,thirdEmpty=false,fourthEmpty=false,fifthEmpty=false,sixthEmpty=false,seventhEmpty=false,eighthEmpty=false,ninthEmpty=false,tenthEmpty=false,eleventhEmpty=false
    ,twelvthEmpty=false,therteenthEmpty=false,fourteenthEmpty=false,fifteenthEmpty=false,sixteenthEmpty=false,seventeenthEmpty=false,eighteenthEmpty=false,nineteenthEmpty=false,twentyteenthEmpty=false;
    bool findFirst=false,findSecond=false,findThird=false,findFourth=false,findFifth=false,findSixth=false,findSeventh=false,findEighth=false,findNinth=false,findTenth=false,findEleventh=false,findTwelvth=false,findTherteenth=false;
    bool findFourteenth=false,findFifteenth=false,findSixteenth=false,findSeventeenth=false,findEighteenth=false,findNingteenth=false,findtwenteenth=false;
    bool twentyoneEmpty=false,twentytwoEmpty=false,twentythreeEmpty=false,twentyfourEmpty=false,twentyfiveEmpty=false,twentysixEmpty=false,twentysevenEmpty=false,twentyEightEmpty=false,twentynineEmpty=false;
    bool findtwentyone=false,findtwentytwo=false,findtwentythree=false,findtwentyfour=false,findtwentyfive=false,findtwentysix=false,findtwentyseven=false,findtwentyEight=false,findtwentynine=false;
//    unsigned char chEmpty;
    RD_KDS_RETURN			kdsreturn,kdsreturnacode;
    RD_KDS_RETURN           kdsreturnX1;
    char * sacode;
    int  inhalt[256];
    bool blisBooster=false;
    
    
    blisBooster = blBooster;
    // uc_count= Db_rddtb((enum KDS_TABLE) KDS_VPLRN_DDI, (DB_ZEILE_T)0, (DB_SPALTE_T)KEINE_SPALTE, &kdsreturnacode );
   //  FPUti::bcd_to_a ( &kdsreturnacode.inhalt[0], inhalt, (WORD)uc_count );   
     
    
    
    
   // Db_rddtb(KDS_AUSBAU_VAR,KDS_ANLAGEN_AUSBAU,KEINE_SPALTE,(RD_KDS_RETURN*)&kdsreturnX1);   // takes System type 

    //if(kdsreturnX1.inhalt[0]==DS_BPL_ONE_X1)  //DS_BPL_ONE
  	//blX1=true; // means system is X1
	
    errorCount = 0;
        
    for(i=0;i<21;i++)
    {
	for(pos=0;pos<3;pos++)
		faults[i][pos]=0;
    }
    
    
// -- Prepei na mpoun edo kai Safe Conditions an Skasei        
    while ( fgets ( line,128,fxml ) != NULL ) // read a line by line
    {
	
	if (faultrow > 20)
		break;
	
	tempstr=line; // this temp str contains the current line
	intLen = strlen(line);
	
	//---1-find----WorkSheet name ------------------------------
	wksFound= tempstr.find("Worksheet ss:Name");

	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
	        fFirst= tempstr.find("\"");
	        fLast=tempstr.find_last_of("\"");   
	        tempstr = tempstr.substr(fFirst+1,(fLast-(fFirst+1)));		

		if(tempstr == "Customer")
		{
	   	   blStations = true;
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name   
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;
		   countLine=0;
		   corXml++;		   
		}
		else if(tempstr =="Groups")		
		{
		   blGroups = true;		    
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 		
		   countLine=0;		
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;
		   corXml++;				    
		}
		else if(tempstr =="Virtual")		
		{
		   blVirtual = true;
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 		
		   countLine=0;		
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;
		   corXml++;			    		   
		}
		else if(tempstr =="Trunk Groups")
		{
		   blTrunkGroup = true;		
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 		   
		   countLine=0;		
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;
		   corXml++;	
		}
		else if(tempstr =="Voicemail")	
		{
		   blVoicemail = true;		   
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 		   
		   countLine=0;		
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;
		   corXml++;		   
		}
		else if(tempstr =="SipConfig")	
		{
		   blSipConfig = true;		   
		   block=0;          
		   record=0;        
		   countLine=0;		
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;
		   corXml++;		   
		}

    }// end worksheet search 

	//---2 find the End of WorkSheet-------------
	wksFound= tempstr.find("</Worksheet>");
	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{				
		if(blStations)
		{
			blStations = false;
		}		
		else if(blGroups)
		{
			blGroups = false;
		}
		else if(blVirtual)
		{
			blVirtual = false;
		}
		else if(blTrunkGroup)
		{
			blTrunkGroup = false;
		}
		else if(blVoicemail)
		{
			blVoicemail = false;
				
		}
		else if(blSipConfig)
		{
			blSipConfig = false;
			break;	
		}

	}


	blEndRecord = false;
	//if(blStations)
	//{
	
		wksFound = tempstr.find("</Data>");
		findNameCell = tempstr.find("<NamedCell");
		findCell = tempstr.find("</Cell>");
		wksRowFound = tempstr.find("</Row>");
		fFiltDb = tempstr.find("FilterDatabase");
		//  CASE  A -- Check if the line is empty, has no data, only namedcell
		if((findNameCell > -1) && (wksFound == -1)  && (fFiltDb==-1) ) 
		{
			fLast = tempstr.find("</Cell>");
			fLast = fLast -3;
			fFirst = tempstr.rfind("=\"");
			fFirst  = fFirst+2;
			strCell = tempstr.substr(fFirst,(fLast-fFirst));
			strData = "empty";
			blEndRecord = true;
		}
		// CASE B scenario we had Data and NameCell Filled in the Same Line 		
		else if( (wksFound > -1) && (findNameCell > -1)  && (findCell >-1) )
		{			
			//cell name
			fLast = tempstr.find("</Cell>");
			fLast = fLast -3;
			fFirst = tempstr.rfind("=\"");
			fFirst  = fFirst+2;
			strCell = tempstr.substr(fFirst,(fLast-fFirst));
			//data 
			fLast = wksFound;  //tempstr.find("</Data>");
			fFirst = tempstr.rfind("\">");
			strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));
			blEndRecord = true;	
		}
		// CASE C -- Has Data and NameCell but the Cell END is in the next Line
		else if( (wksFound > -1) && (findNameCell > -1)  && (findCell == -1) )
		{
			//data
			fLast = wksFound;  //tempstr.find("</Data>");
			fFirst = tempstr.rfind("\">");
			
			strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));

			if(strData.length() == 0 )
				strData = "empty";
			blCellEnd = true; // wait the end of the Cell	
		}
		else if( (findCell > -1) &&  (blCellEnd)  ) // find the end of Cell
		{
			blCellEnd = false;
			//cell name
			fLast = tempstr.find("</Cell>");
			fLast = fLast -3;
			fFirst = tempstr.rfind("=\"");
			fFirst  = fFirst+2;
			strCell = tempstr.substr(fFirst,(fLast-fFirst));
			blEndRecord = true;
		}
		else if(wksRowFound > -1)	
		{
			blEndRecord = true;
			strData = "</Row>";
			strCell="";
		}
		
		if(blEndRecord)
		{		 
		  if(strCell != "_FilterDatabase")
		  icurrentrow++;
		}
		
		//  When Find a Record the blEndRecord is TRUE 
		if((blEndRecord)  &&  (faultrow <21)   && (icurrentrow > 35))
		{
			
//----------------Start ----  Validation -- Check If the Header of Each  Sheet Is Correct ----------------------------------------------			
			if(blStations) 
			{								
				if(record >30)
				{
				  block++;
				  record = 0;
				  firstEmpty=false; secondEmpty=false; thirdEmpty=false;   fourthEmpty=false;   fifthEmpty=false; sixthEmpty=false; seventhEmpty=false;   eighthEmpty=false;	
				  ninthEmpty=false; tenthEmpty=false; eleventhEmpty=false; twelvthEmpty=false; therteenthEmpty=false;fourteenthEmpty=false; fifteenthEmpty=false; 
				  sixteenthEmpty=false; seventeenthEmpty=false; eighteenthEmpty=false; nineteenthEmpty=false; twentyteenthEmpty=false;twentyoneEmpty=false; twentytwoEmpty=false;
				  twentythreeEmpty=false; twentyfourEmpty=false; twentyfiveEmpty=false; twentysixEmpty=false; twentysevenEmpty=false; twentyEightEmpty=false; twentynineEmpty=false;
				}
			  }
			if(blGroups) 
			  {
				if(record >4)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
				}					
			   }
			  
			  if(blVirtual) 
			  {
				if(record >4)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
				}
							
			   }
			   
			  if(blTrunkGroup) 
			  {
				if(record >2)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
				}								
			   }
			   
			  if(blVoicemail) 
			  {
				if(record >2)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
				}				
			   }
			   if(blSipConfig)
			   {
				if(record >4)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
				}				
			   }
			   
			  					
//----------------END ----  Validation -- Check If the Header of Each  Sheet Is Correct ----------------------------------------------						
			
//----------------------------------------------Customer --------------------------------------------------------------------------------------------------------------
			if( (blStations) )// &&  (block > 0) )
			{
				
				//---------------------------ID---nodeid------------------------------------------------------

				if( ( strcmp(strCell.c_str(),xmlUsaElements[0].element ) == 0 )  )				  
				{														
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					    firstEmpty = true; 
					}
					else
					{
					    findFirst = true;
					    /* node ID  must be a number other case return error code */
					    if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
					    {
						  faults[0][0]++;
						  faults[faultrow][0]=1;
						  faults[faultrow][1]=numStations+3;
						  faults[faultrow][2]=INVALID_NODEID;
						  faultrow++;
					    }
					    /*  node ID must be betwwen 0....999, it's refered to nodeID number */
					    else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
					    {
						  faults[0][0]++;
						  faults[faultrow][0]=1;
						  faults[faultrow][1]=numStations+3;
						  faults[faultrow][2]=INVALID_NODEID;
						  faultrow++;
					    }
					    /*  node Id cannot be greater than 999, if we have more than 3 digits return error code.*/
					    else if( strData.length() > 4 )
					    {
						  faults[0][0]++;
			      			  faults[faultrow][0]=1;
		   				  faults[faultrow][1]=numStations+3;
						  faults[faultrow][2]=INVALID_NODEID;
						  faultrow++;
					    }
					    
					}
					  
				}
				//-----------------------END----NODE ID ------------------------------------------------------
				//-------------------------SITENAME-----------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[1].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					    secondEmpty = true; 
					}
					else
					{
					    findSecond = true;
					    //----------------site name  max length 50characters------------------
					    klen=0;
					    klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
				            /*-----search for invalid characters ------------------------*/		      
					    if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_SITENAME;
						faultrow++;	
					    }
					    /*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					    else if( (strData.length() > (MAXLENSTRS_CUSTOMER))     &&   (klen>MAXLENSTRS_CUSTOMER ) )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_SITENAME;
						faultrow++;	
					    }
					}
					
				}
				//------------------------END SITE NAME---------------------------------
				
				//------------------------UC TYPE---------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[2].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					    thirdEmpty = true; 
					}
					else
					{
					    findThird = true;
					    //----------------site name  max length 50characters------------------
					    klen=0;
					    klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
				            /*-----search for invalid characters ------------------------*/		      
					    if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_UCTYPE;
						faultrow++;	
					    }
					    /*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					    else if( (strData.length() > (MAXLENSTRS_CUSTOMER))     &&   (klen>MAXLENSTRS_CUSTOMER ) )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_UCTYPE;
						faultrow++;	
					    }
					    else if(  (strcmp(strData.c_str(),"UC Suite")!=0) && (strcmp(strData.c_str(),"UC Smart")!=0))	
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_UCTYPE;
						faultrow++;	
					    
					    }
					    
					}
					
				}				
				//------------------------END UC TYPE ----------------------------------
				
				//------------------------Call PickUp Groups---------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[3].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					    fourthEmpty = true; 
					}
					else
					{
					    findFourth = true;
					    //----------------site name  max length 50characters------------------
					    klen=0;
					    klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
				            /*-----search for invalid characters ------------------------*/		      
					    if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_CALLPICKUP;
						faultrow++;	
					    }
					    /*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					    else if( (strData.length() > (MAXLENSTRS_CUSTOMER))     &&   (klen>MAXLENSTRS_CUSTOMER ) )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_CALLPICKUP;
						faultrow++;	
					    }
					    
					    icountCallPick++;
					    if(icountCallPick > 64)
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]= 6698;//MORE_CALLPICKUP_NAMES;			
						faultrow++;
					    }
					
					    
					}
					
				}				
				//------------------------END Call PickUp Groups ----------------------------------
				//MAXLENSTR_NAME
				
				//--------------------LAST NAME-------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[4].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					    fifthEmpty = true; 
					}
					else
					{   
					    
					    findFifth = true;
					    //----------------site name  max length 32 characters------------------
					    klen=0;
					    klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
				            /*-----search for invalid characters ------------------------*/		      
					    if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_LASTNAME;
						faultrow++;	
					    }
					    /*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					    else if( (strData.length() > (MAXLENSTR_NAME))     &&   (klen>MAXLENSTR_NAME ) )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_LASTNAME;
						faultrow++;	
					    }
					    
					    
					}
					
				}
				//--------------------END LAST NAME---------------------------------------------------
				
				//--------------------FIRST NAME-------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[5].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					    sixthEmpty = true; 
					}
					else
					{
					    findSixth = true;
					    //----------------site name  max length 32 characters------------------
					    klen=0;
					    klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
				            /*-----search for invalid characters ------------------------*/		      
					    if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_FIRSTNAME;
						faultrow++;	
					    }
					    /*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					    else if( (strData.length() > (MAXLENSTR_NAME))     &&   (klen>MAXLENSTR_NAME ) )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_FIRSTNAME;
						faultrow++;	
					    }
					}
					
				}
				//--------------------END FIRST NAME---------------------------------------------------
				
				//--------------------DISPLAY NAME-----------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[6].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					    seventhEmpty = true; 
					}
					else
					{
					    findSeventh = true;
					    //----------------site name  max length 32 characters------------------
					    klen=0;
					    klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
				            /*-----search for invalid characters ------------------------*/		      
					    if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_NAME_CHARACTERS;
						faultrow++;	
					    }
					    /*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					    else if( (strData.length() > (MAXLENSTR_NAME*2))     &&   (klen>MAXLENSTR_NAME*2 ) )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_NAME;
						faultrow++;	
					    }
					}
					
				}
				//--------------------END DISPLAY NAME-----------------------------------------------------
				
				//--------------------INTERNAL NUMBER------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[7].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					    eighthEmpty = true; 
					}
					else
					{
					    findEighth = true;
					    // THIS VARIABLE MUST REINIT IN EACHE END OF </ROW>
					    strtmpNumDid = strData.c_str();//This variable is used in case where the DID is 'X', this means that the DID number is same as Internal Number
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());
					    if(!checkvalidCallDuwa(tmpNumbers))
					    {				       
					       faults[0][0]++;
					       faults[faultrow][0]=1;
   					       faults[faultrow][1]=numStations+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
					    				    
					    }
					    else if(strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					       faults[0][0]++;
					       faults[faultrow][0]=1;
   					       faults[faultrow][1]=numStations+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
			    
					    }
					    else
					    {
					    
					    }
					    //----------call old Checks --------------------------------------					    
					    delete[] tmpNumbers;
					}
				}
				//-------------------END INTERNAL NUMBER--------------------------------------------------- 
				
				//-------------------DID-------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[8].element ) == 0 )  )				  
				{
				  bool 	bltmpnumdid=false;
				  string strtmp_1="";
				  
				  if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				  {	
				    ninthEmpty = true; 
				  }
				  else
				  {
					  findNinth = true;
					  if(  (strcmp(strData.c_str(),"x")==0) || (strcmp(strData.c_str(),"X")==0))	
					  {
						if(!findEighth) // Internal number FLAG 
						{
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=INVALID_CALL_NO;
						   faultrow++;
						}
						else
						    bltmpnumdid = true;												
					    }
					    
					    
					    if(bltmpnumdid)
					    {
						tmpNumbers = new char[strtmpNumDid.length()+1];  
						strcpy(tmpNumbers,strtmpNumDid.c_str());
						//strcpy(strtmp_1.c_str()  ,strtmpNumDid.c_str());						
					    }
					    else
					    {
						tmpNumbers = new char[strData.length()+1];  
						strcpy(tmpNumbers,strData.c_str());
						//strcpy(strtmp_1.c_str(),strData.c_str());	
						
					    }
					    
					    if( (!checkvalidCallDuwa(tmpNumbers) )  ||  (strcmp(strData.c_str(),"empty") == 0) ) 
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
	   					faults[faultrow][1]=numStations+3;
					        faults[faultrow][2]=INVALID_DUWA;
					        faultrow++;						    
					    }
					    else if(strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {						       
						faults[0][0]++;
						faults[faultrow][0]=1;
	   					faults[faultrow][1]=numStations+3;
					        faults[faultrow][2]=INVALID_DUWA;
					        faultrow++;			    
					    }
					    else
					    {

							/*
						//FPUti::ascii_to_bcd ((INT8U *)tmpNumbers, &kdsreturn.inhalt[0], strlen(tmpNumbers));
						
						if (checkAttentCodeCollision((char *)strtmp_1.c_str() , (char *)inhalt ) == true ) // did a code   
						{
							faults[0][0]++;
							faults[faultrow][0]=1;
   							faults[faultrow][1]=numStations+3;
							faults[faultrow][2]=DUWA_NOT_UNIQUE;//return DUWA_NOT_UNIQUE;
							faultrow++;	
						}
						
						else
						{
						//--CHRIS result= FPUti::check_duwa_other(kdsreturn,TEILNEHMER_CODE,STN_IP_CLIENT_START,0); // System Clients, SIP, RAS
							result= FPUti::check_duwa_other(kdsreturn,TEILNEHMER_CODE,0,1); // System Clients, SIP, RAS
		 					if (result!=NO_DOUBLE)
		 					{
								result= FPUti::check_duwa_other(kdsreturn,SAM_CODE,L_SAM_GROUP,0);     //Groups
								if (result!=NO_DOUBLE)
								{								
								  faults[0][0]++;
								  faults[faultrow][0]=1;
   								  faults[faultrow][1]=numStations+3;
								  faults[faultrow][2]=DUWA_NOT_UNIQUE;//return DUWA_NOT_UNIQUE;
								  faultrow++;											
								}
							 }
						}
						*/
					    }
					    
					    
					    
					    
					    delete[] tmpNumbers;
					}
				}
				//-------------------END DID---------------------------------------------------------------
				
				//------------------EMAIL ADDRESS----------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[9].element ) == 0 )  )				  
				{
				    if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)   )
				    {	
					tenthEmpty = true;
				    }					
				    else
				    {
					findTenth=true;	
				
					tmpNumbers = new char[strData.length()+1];  
					strcpy(tmpNumbers,strData.c_str());

					if( !checkvalidmail(tmpNumbers) )
					{	
					    faults[0][0]++;
	      				    faults[faultrow][0]=1;
   					    faults[faultrow][1]=numStations+3;
				            faults[faultrow][2]=INVALID_EMAIL;
				            faultrow++;
					}
					else if(strData.length() >  MAX_EMAIL )
					{
					    faults[0][0]++;
		      			    faults[faultrow][0]=1;
	   				    faults[faultrow][1]=numStations+3;
					    faults[faultrow][2]=INVALID_EMAIL;
					    faultrow++;		
					}						
						delete [] tmpNumbers;
				    }
				}
				//------------------END EMAIL ADDRESS----------------------------------------------------------
				
				//------------------MOBILE ----------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[10].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     eleventhEmpty = true;
					}
					else
					{
						findEleventh=true; 
						

						tmpNumbers = new char[strData.length()+1];  
						strcpy(tmpNumbers,strData.c_str());

						if( !checkvalidnumber(tmpNumbers) )
						{					    							    
						    faults[0][0]++;
		      				    faults[faultrow][0]=1;
	   					    faults[faultrow][1]=numStations+3;
					            faults[faultrow][2]=INVALID_MOBILE;
					            faultrow++;	
						}
						else if(strData.length() > MAX_MOBILE)
						{
						    faults[0][0]++;
		      				    faults[faultrow][0]=1;
	   					    faults[faultrow][1]=numStations+3;
					            faults[faultrow][2]=INVALID_MOBILE;
					            faultrow++;	
				
						}
						delete [] tmpNumbers;
					}
				}
				//------------------END MOBILE-------------------------------------------------------
				
				//------------------DEVTYPE----------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[11].element ) == 0 )  )				  
				{
					if ( strcmp(strData.c_str(),"empty") == 0 )
					{	
					     twelvthEmpty = true;
					}					
					else 
					{
						findTwelvth=true; 
						if(blisBooster)
						{
							if( ! LXCheckStationType(strData.c_str()) )//loloca							
							{
								faults[0][0]++;
								faults[faultrow][0]=1;
		   						faults[faultrow][1]=numStations+3;
						        	faults[faultrow][2]=STN_TYP_UNKNOWN;
						       		 faultrow++;
							}
						}
						else
						{					    
							if ( !checkDevType(strData.c_str()) )
							{
							faults[0][0]++;
							faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=STN_TYP_UNKNOWN;
						        faultrow++;	
							}
						}
						
					}
				}
				//------------------END DEVTYPE-----------------------------------------------------
				
				//-----------------Voicemail---------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[12].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					therteenthEmpty = true; 
				      }
				      else
				      {
					  findTherteenth = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=WRONG_VOICEMAIL_FORMAT; // Fix ERROR
						   faultrow++;
					  }
				      }
					    
				}
				//-----------------End VoiceMail-----------------------------------------------------
				
				//-----------------Outlook Addin-----------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[13].element ) == 0 )  )				  
				{
				     if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					fourteenthEmpty = true; 
				      }
				      else
				      {
					  findFourteenth = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=INVALID_OUTLADD; 
						   faultrow++;
					  }
				      }
				}
				//-----------------END Outlook Addin-------------------------------------------------
				
				//-----------------UC Client---------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[14].element ) == 0 )  )				  
				{
				    if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					fifteenthEmpty = true; 
				      }
				      else
				      {
					  findFifteenth = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=INVALID_UCCLIENT; 
						   faultrow++;
					  }
					  
					  if( thirdEmpty)
					  {
	 				         faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_UCTYPE;
						faultrow++;	
					  
					  }
					  
					  
				      }
				}
				//-----------------End UC Client-----------------------------------------------------
				
				//-----------------UC FaAx-----------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[15].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					sixteenthEmpty = true; 
				      }
				      else
				      {
					  findSixteenth = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=INVALID_UCFAX; // Fix ERROR
						   faultrow++;
					  }
				      }
				}
				//-----------------End UC Fax---------------------------------------------------------
				
				//-----------------Fax Callno---------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[16].element ) == 0 )  )				  
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if Internal Number Is Emprty 
					{					   
					    seventeenthEmpty = true;					    
					}
					else // Check If Valid Call Number 
					{
					    findSeventeenth=true;
					    strtmpFaxDid = strData;
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());
					    if(!checkvalidCallDuwa(tmpNumbers))
					    {				       
					       faults[0][0]++;
					       faults[faultrow][0]=1;
   					       faults[faultrow][1]=numStations+3;
					       faults[faultrow][2]=INVALID_FAXCALLNO;
					       faultrow++;
					    				    
					    }
					    else if(strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					       faults[0][0]++;
					       faults[faultrow][0]=1;
   					       faults[faultrow][1]=numStations+3;
					       faults[faultrow][2]=INVALID_FAXCALLNO;
					       faultrow++;
			    
					    }
					    else//----------call old Checks --------------------------------------
					    {
							/*
						FPUti::ascii_to_bcd ((INT8U*)tmpNumbers, &kdsreturn.inhalt[0], strlen(tmpNumbers));
						
						result= FPUti::check_rufnummer(kdsreturn,TEILNEHMER_CODE,-1,1);// System Clients, SIP, RAS 
						if (result!=NO_DOUBLE)
						{ 
							result= FPUti::check_rufnummer(kdsreturn,RICHTUNGS_CODE, -1,1);//Trunk Group for SIP Provider
							if (result!=NO_DOUBLE)
							{	
							    result= FPUti::check_rufnummer(kdsreturn,VOICE_PREF_CODE,0xFFFF);//Voicemail Callnumber
							    if (result!=NO_DOUBLE)
							    {
								result= FPUti::check_rufnummer(kdsreturn,SAM_CODE,1); //Groups
								if (result!=NO_DOUBLE)	
								{					
								  faults[0][0]++;
								  faults[faultrow][0]=1;
								  faults[faultrow][1]=numStations+3;
								  faults[faultrow][2]=FAX_CALL_NOT_UNIQUE;
								  faultrow++;
								}
									    
							      }
							 }						    
						  }
						  */
					     }//----------call old Checks --------------------------------------					    					    
					    delete[] tmpNumbers;
				         }
				}
				//-----------------END Fax Callno-----------------------------------------------------
				
				//-----------------Fax DID------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[17].element ) == 0 )  )				  
				{
				  bool bltmpfaxdid = false;
				  string strtmp_1="";
					  
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if Internal Number Is Emprty 
					{					   
					    eighteenthEmpty = true;					    
					}
					else // Check If Valid Call Number 
					{
					    findEighteenth = true;
					    
					    if(  (strcmp(strData.c_str(),"x")==0) || (strcmp(strData.c_str(),"X")==0))	
					    {
						if(!findSeventeenth) // Internal number FLAG 
						{
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=INVALID_FAXCALLNO;
						   faultrow++;
						}
						else
						    bltmpfaxdid = true;												
					    }
					    
					    if(bltmpfaxdid)
					    {
						tmpNumbers = new char[strtmpFaxDid.length()+1];  
						strcpy(tmpNumbers,strtmpFaxDid.c_str());
						//strcpy(strtmp_1.c_str(),strtmpFaxDid.c_str());			
					    }
					    else
					    {
						tmpNumbers = new char[strData.length()+1];  
						strcpy(tmpNumbers,strData.c_str());
						//strcpy(strtmp_1.c_str(),strData.c_str());					      
					    }
					    					    
						 //Check if Valid Number  Duwa or Is Empty Then Error
						if( (!checkvalidCallDuwa(tmpNumbers) )   ) 
						{
					     	        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_FAXDID;
					                faultrow++;
						    
						}
						else if(strtmp_1.length() > ((RUFNR_SIZE*2) -2 ))
					    	{						       
						        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_FAXDID;
					                faultrow++;
			    
					    	}
						        							
						else
						{						    	
							/*
							FPUti::ascii_to_bcd ((INT8U *)tmpNumbers, &kdsreturn.inhalt[0], strlen(tmpNumbers));
							
							if (checkAttentCodeCollision((char *)strtmp_1.c_str() , (char *)inhalt ) == true ) // did a code   
							{
								faults[0][0]++;
								faults[faultrow][0]=1;
   								faults[faultrow][1]=numStations+3;
								faults[faultrow][2]=FAX_DID_NOT_UNIQUE;//return DUWA_NOT_UNIQUE;
								faultrow++;	
							}
							else
							{
								// FPUti::ascii_to_bcd ((INT8U *)tmpNumbers, &kdsreturn.inhalt[0], strlen(tmpNumbers));
								//--CHRIS result= FPUti::check_duwa_other(kdsreturn,TEILNEHMER_CODE,STN_IP_CLIENT_START,0); // System Clients, SIP, RAS
								result= FPUti::check_duwa_other(kdsreturn,TEILNEHMER_CODE,0,1); // System Clients, SIP, RAS
			 					if (result!=NO_DOUBLE)
			 					{							 																		
									result= FPUti::check_duwa_other(kdsreturn,SAM_CODE,L_SAM_GROUP,0);     //Groups
									if (result!=NO_DOUBLE)
									{
								
										faults[0][0]++;
										faults[faultrow][0]=1;
   									        faults[faultrow][1]=numStations+3;
								                faults[faultrow][2]=FAX_DID_NOT_UNIQUE;//return DUWA_NOT_UNIQUE;
								                faultrow++;											
									}
										
									
										
								 }
							 }

							*/

						}
						delete[] tmpNumbers;
					    
					    
					    
					}
				}
				//----------------END Fax DID---------------------------------------------------------
				
				//----------------FAX name------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[18].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     //thirdEmpty = true;
					     nineteenthEmpty = true;
					}

					else 
					{
						//findThird=true; 
						findNingteenth=true;
						klen=0;
						klen= my_strlen_utf8_c(strData.c_str());
						if( (strData.length() > (TLN_NAME_SIZE))     &&   (klen>TLN_NAME_SIZE ) )
						{
						    	faults[0][0]++;
							faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=INVALID_FAX_NAME;
						        faultrow++;	
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
							faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=INVALID_FAX_NAME;
						        faultrow++;	
						}
												
					}
				}
				//----------------END FAX name--------------------------------------------------------
				
				//----------------Conference Server---------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[19].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentyteenthEmpty = true; 
				      }
				      else
				      {
					  findtwenteenth = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=INVALID_CONFSERV; 
						   faultrow++;
					  }
				      }
				}
				//----------------END Conference Server-----------------------------------------------
				
				//----------------My Attendant--------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[20].element ) == 0 )  )				  
				{
				    if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentyoneEmpty = true; 
				      }
				      else
				      {
					  findtwentyone = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=LIC_TYP_MYATTEND; // Fix ERROR
						   faultrow++;
					  }
				      }
				}
				//----------------END My Attendant----------------------------------------------------
				
				//----------------myagent-------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[21].element ) == 0 )  )				  
				{
				    if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentytwoEmpty = true; 
				      }
				      else
				      {
					  findtwentytwo = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=LIC_TYP_MYAGENT; // Fix ERROR
						   faultrow++;
					  }
				      }
				}
				//----------------END myagent---------------------------------------------------------
				
				//----------------Application Launcher------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[22].element ) == 0 )  )				  
				{	
				    if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentythreeEmpty = true; 
				      }
				      else
				      {
					  findtwentythree = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=LIC_TYP_APPLAUNCH; // Fix ERROR
						   faultrow++;
					  }
				      }
				}
				//----------------END Application Launcher--------------------------------------------
				
				//----------------TAPI------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[23].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentyfourEmpty = true; 
				      }
				      else
				      {
					  findtwentyfour = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=LIC_TYP_TAPI; // Fix ERROR
						   faultrow++;
					  }
				      }
				}
				//----------------END TAPI --------------------------------------------
				
				//----------------Class of service------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[24].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentyfiveEmpty = true; 
				      }
				      else
				      {
					findtwentyfive = true;
					if(  (strcmp(strData.c_str(),"national")!=0) && (strcmp(strData.c_str(),"international")!=0)  && (strcmp(strData.c_str(),"internal")!=0))	
					{						
					   faults[0][0]++;
					   faults[faultrow][0]=1;
					   faults[faultrow][1]=numStations+3;
					   faults[faultrow][2]=INVALID_COS; // Fix ERROR
					   faultrow++;
					}
					
				      }
				}
				//----------------END Class of sertvice --------------------------------------------
				
				
				//----------------Call PickUp ------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[25].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentysixEmpty = true; 
				      }
				      else
				      {
					findtwentysix = true;
					klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
					/*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					if( (strData.length() > (MAXLENSTRS_CUSTOMER))     &&   (klen>MAXLENSTRS_CUSTOMER ) )
					{
					  faults[0][0]++;
					  faults[faultrow][0]=1;
					  faults[faultrow][1]=numStations+3;
					  faults[faultrow][2]=INVALID_CALLPICKUP;// FIX Error Message 
					  faultrow++;	
					}
					
				      }
				}
				//----------------END Call PickUp --------------------------------------------
				
				
				//----------------Network Sites------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[26].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentysevenEmpty  = true; 
				      }
				      else
				      {
					findtwentyseven = true;
					klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
					/*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					if( (strData.length() > (MAXLENSTRS_CUSTOMER))     &&   (klen>MAXLENSTRS_CUSTOMER ) )
					{
					  faults[0][0]++;
					  faults[faultrow][0]=1;
					  faults[faultrow][1]=numStations+3;
					  faults[faultrow][2]=INVALID_NETWSITE;// FIX Error Message 
					  faultrow++;	
					}
					
				      }
				}
				//----------------END Network Sites --------------------------------------------
				
				
				//----------------Secondary GW------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[27].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentyEightEmpty  = true; 
				      }
				      else
				      {
					findtwentyEight = true;
					klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
					/*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					if( (strData.length() > (MAXLENSTRS_CUSTOMER))     &&   (klen>MAXLENSTRS_CUSTOMER ) )
					{
					  faults[0][0]++;
					  faults[faultrow][0]=1;
					  faults[faultrow][1]=numStations+3;
					  faults[faultrow][2]=INVALID_SECGW;// FIX Error Message 
					  faultrow++;	
					}
					
				      }
				}
				//----------------END Secondary GW --------------------------------------------
				
				
				//----------------Access------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[28].element ) == 0 )  )				  
				{
				      
				      if(blisBooster)
				      {
				      	if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      	{	
						twentynineEmpty  = true; 
				      	}
					else if( strcmp(strData.c_str(),"empty") != 0 )
					{	
					     faults[0][0]++;
					     faults[faultrow][0]=1;
		   			     faults[faultrow][1]=numStations+3;
					     faults[faultrow][2]=WRONG_ACCESS_TYPE;
					     faultrow++;
					}		
				      }				      
				      else   /*is system is embeded*/
				      {
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentynineEmpty  = true; 
				      }
				      else
				      {
					findtwentynine = true;
					i = strData.find("-");
					if( (i == -1)  || (strData.length() <3)  || ( (strData.length() - i) < 1 )  || (i==0) )
					{
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
					        faults[faultrow][2]=WRONG_ACEESS_FORMAT;
					        faultrow++;	
					}
				
					tmpNumbers = new char[strData.length()+1];  
					strcpy(tmpNumbers,strData.substr(0,strData.find(" ")).c_str());
					//strcpy(tmpNumbers,strData.c_str());
					if(checkvalidAccess(tmpNumbers) == false)
					{						
						faults[0][0]++;
						faults[faultrow][0]=1;
	   					faults[faultrow][1]=numStations+3;
					        faults[faultrow][2]=WRONG_ACEESS_FORMAT;
					        faultrow++;	
					}
					else if (( strcmp("Master",strData.substr(strData.find(" ")+1).c_str() )  !=0   )   &&	( strcmp("Slave",strData.substr(strData.find(" ")+1).c_str() )  !=0   ) )
					{
						faults[0][0]++;
						faults[faultrow][0]=1;
						faults[faultrow][1]=numStations+3;
					        faults[faultrow][2]=WRONG_ACEESS_FORMAT;
					        faultrow++;							
					}
					
				      }
				      }
				}
				//----------------END Acess --------------------------------------------
				
				
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					

					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) && (fourthEmpty) && (fifthEmpty) && (sixthEmpty) && (seventhEmpty) && (eighthEmpty)&& (ninthEmpty)&&(tenthEmpty) &&(eleventhEmpty) &&
					(twelvthEmpty)   &&  (therteenthEmpty) &&  (fourteenthEmpty) &&  (fifteenthEmpty) &&  (sixteenthEmpty)  &&  (seventeenthEmpty)  &&  (eighteenthEmpty) &&  (nineteenthEmpty) &&  (twentyteenthEmpty)
					&&  (twentyoneEmpty) &&  (twentytwoEmpty) &&  (twentythreeEmpty) &&  (twentyfourEmpty) &&  (twentyfiveEmpty)  &&  (twentysixEmpty)  &&  (twentysevenEmpty) &&  (twentyEightEmpty) &&  (twentynineEmpty))
					{
					    blStations = false;

					    firstEmpty=false; secondEmpty=false; thirdEmpty=false;   fourthEmpty=false;   fifthEmpty=false; sixthEmpty=false; seventhEmpty=false;   eighthEmpty=false;	
					    ninthEmpty=false; tenthEmpty=false; eleventhEmpty=false; twelvthEmpty=false; therteenthEmpty=false;fourteenthEmpty=false; fifteenthEmpty=false; 
					    sixteenthEmpty=false; seventeenthEmpty=false; eighteenthEmpty=false; nineteenthEmpty=false; twentyteenthEmpty=false;twentyoneEmpty=false; twentytwoEmpty=false;
					    twentythreeEmpty=false; twentyfourEmpty=false; twentyfiveEmpty=false; twentysixEmpty=false; twentysevenEmpty=false; twentyEightEmpty=false; twentynineEmpty=false;
					    block =0;
					    record = 0;					    
				        }
					
					
					if( (findFirst) && (findSecond) && (findThird)  && (findFourth) && (findFifth) && (findSixth) && (findSeventh) && (findEighth) && (findNinth)&&(findTenth) &&(findEleventh) &&
					(findTwelvth)   &&  (findTherteenth) && (findFourteenth) &&(findFifteenth)  &&(findSixteenth)  &&(findSeventeenth)  &&(findEighteenth)  &&(findNingteenth)  &&(findtwenteenth)
					&&(findtwentyone)  &&(findtwentytwo)  &&(findtwentythree) &&(findtwentyfour)  &&(findtwentyfive) &&(findtwentysix) &&(findtwentyseven) &&(findtwentyEight) &&(findtwentynine))
					{
					    firstEmpty=false; secondEmpty=false; thirdEmpty=false;   fourthEmpty=false;   fifthEmpty=false; sixthEmpty=false; seventhEmpty=false;   eighthEmpty=false;	
					    ninthEmpty=false; tenthEmpty=false; eleventhEmpty=false; twelvthEmpty=false; therteenthEmpty=false;fourteenthEmpty=false; fifteenthEmpty=false; 
					    sixteenthEmpty=false; seventeenthEmpty=false; eighteenthEmpty=false; nineteenthEmpty=false; twentyteenthEmpty=false;twentyoneEmpty=false; twentytwoEmpty=false;
					    twentythreeEmpty=false; twentyfourEmpty=false; twentyfiveEmpty=false; twentysixEmpty=false; twentysevenEmpty=false; twentyEightEmpty=false; twentynineEmpty=false;

					} 
					else if( (findEighth)  && (!findTwelvth) )
					{
						faults[0][0]++;
						faults[faultrow][0]=1;
	   					faults[faultrow][1]=numStations+2;
					        faults[faultrow][2]=STN_TYP_UNKNOWN;
					        faultrow++;	
					}
					else if( (!findEighth) &&  ((findFirst)  ||  ((findSecond) || (findThird)  || (findFourth) || (findFifth) || (findSixth) || (findSeventh) || (findEighth) || (findNinth) || (findTenth) || (findEleventh) ||
					(findTwelvth) ||(findTherteenth) ||(findFourteenth) ||(findFifteenth)  ||(findSixteenth)  ||(findSeventeenth)  ||(findEighteenth)  ||(findNingteenth)  ||(findtwenteenth)
					||(findtwentyone)  ||(findtwentytwo)  ||(findtwentythree) ||(findtwentyfour)  ||(findtwentyfive) ||(findtwentysix) ||(findtwentyseven) ||(findtwentyEight) ||(findtwentynine))))
					{					    
					    
					    faults[0][0]++;
			      		    faults[faultrow][0]=1;
		   			    faults[faultrow][1]=numStations+3;
					    faults[faultrow][2]=CALL_NO_MISSING;
					    faultrow++;
					}
					
					/*
					if( ((findEighth)    &&   (!findFirst))   )
					{
						faults[0][0]++;
						faults[faultrow][0]=1;
	   				        faults[faultrow][1]=numStations+3;
					        faults[faultrow][2]=INVALID_NODEID;
					        faultrow++;
					}
					*/

					
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) && (!findFifth) && (!findSixth)  && (!findSeventh) && (!findEighth) && (!findNinth)&&(!findTenth) &&(!findEleventh) &&
					(!findTwelvth)   &&  (!findTherteenth) )
					{
					    //blStations = false;
					    numStations = numStations;
					}
					else
					  numStations++;
					
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;findTherteenth=false;				
					findFourteenth=false; findFifteenth=false; findSixteenth=false; findSeventeenth=false; findEighteenth=false; findNingteenth=false; findtwenteenth=false;
					findtwentyone=false; findtwentytwo=false; findtwentythree=false; findtwentyfour=false; findtwentyfive=false; findtwentysix=false; findtwentyseven=false; findtwentyEight=false; findtwentynine=false;

					
					firstEmpty=false; secondEmpty=false; thirdEmpty=false;   fourthEmpty=false;   fifthEmpty=false; sixthEmpty=false; seventhEmpty=false;   eighthEmpty=false;	
					ninthEmpty=false; tenthEmpty=false; eleventhEmpty=false; twelvthEmpty=false; therteenthEmpty=false;fourteenthEmpty=false; fifteenthEmpty=false; 
					sixteenthEmpty=false; seventeenthEmpty=false; eighteenthEmpty=false; nineteenthEmpty=false; twentyteenthEmpty=false;twentyoneEmpty=false; twentytwoEmpty=false;
					twentythreeEmpty=false; twentyfourEmpty=false; twentyfiveEmpty=false; twentysixEmpty=false; twentysevenEmpty=false; twentyEightEmpty=false; twentynineEmpty=false;

					strtmpNumDid=""; 
					strtmpFaxDid = "";
				}
				
								


			} // END if(blStations)
//---------------------------------------------- END STATIONS--------------------------------------------------------------------------------------------------------------			
		//-----------------------------------------------GROUPS START-----------------------------------------------------------------------------------------------------------			
			else if( (blGroups) )
			{				
				//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlGroupsNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[0].headerrecord)!= 0 ) )
				{
					//numGroups++;
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if GRoup Internal Number Is Emprty 
					{										   
					     firstEmpty = true;	
					     //numGroups--;			    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true; 
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {					       
					       faults[0][0]++;
				      	       faults[faultrow][0]=3;
		   			       faults[faultrow][1]=numGroups+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					       faults[0][0]++;
				      	       faults[faultrow][0]=3;
		   			       faults[faultrow][1]=numGroups+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
					    }
					    else
					    {
					    /*
					     FPUti::ascii_to_bcd ((INT8U*)tmpNumbers, &kdsreturn.inhalt[0], strlen(tmpNumbers));
					     //--CHRIS---result= FPUti::check_rufnummer(kdsreturn,TEILNEHMER_CODE,STN_IP_CLIENT_START,0);// System Clients, SIP, RAS
					     result= FPUti::check_rufnummer(kdsreturn,TEILNEHMER_CODE,-1,1);// System Clients, SIP, RAS
	 				     if (result!=NO_DOUBLE)
					     { 		 				
							result= FPUti::check_rufnummer(kdsreturn,RICHTUNGS_CODE, 0,1);//Trunk Group for SIP Provider
							if (result!=NO_DOUBLE)
							{
								result= FPUti::check_rufnummer(kdsreturn,VOICE_PREF_CODE,0xFFFF);//Voicemail Callnumber
								if (result!=NO_DOUBLE)
								{
									result= FPUti::check_rufnummer(kdsreturn,SAM_CODE,1); //Groups
									//result= FPUti::check_rufnummer(kdsreturn,SAM_CODE,L_SAM_GROUP,0); //Groups
									if (result!=NO_DOUBLE)	
									{																
									       faults[0][0]++;
								      	       faults[faultrow][0]=3;
			       						       faults[faultrow][1]=numGroups+3;
									       faults[faultrow][2]=CALL_NO_NOT_UNIQUE;
									       faultrow++;
									}
									
								}
							}
						
	  				      }
					    */
					    }					    					    		

					    delete [] tmpNumbers;
					}     	
					numberoflines++;
					
					
				}
				//------------------------------DID NUMBER -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlGroupsNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[1].headerrecord)!= 0 ) )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  ) // Check if GRoup Internal Number Is Emprty 
					{										   
					     secondEmpty = true;
				    
					}
					else // Check If Valid Call Number 
					{
					    findSecond=true; 
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
				               faults[0][0]++;
				      	       faults[faultrow][0]=3;
		   			       faults[faultrow][1]=numGroups+3;
					       faults[faultrow][2]=INVALID_DUWA;
					       faultrow++;
					    }
					    else if (strData.length() > ((DID_SIZE*2) -1) )
		   			    {
				               faults[0][0]++;
				      	       faults[faultrow][0]=3;
		   			       faults[faultrow][1]=numGroups+3;
					       faults[faultrow][2]=INVALID_DUWA;
					       faultrow++;
					    }
					    else
					    {
					     		
							 
					    }
					    
					    
					    delete [] tmpNumbers;
					}    
					 	
				}
				//------------------------------DISPLAY NAME -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlGroupsNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[2].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}
					else 
					{	klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=INVALID_NAME;
						       faultrow++;
						}
						else if ( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=INVALID_NAME;
						       faultrow++;	
						}
						findThird=true; 
					}
					
				}
				//------------------------------Voicemail -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlGroupsNameTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[3].headerrecord)!= 0)  )
				{
					
					if(blisBooster)
					{
						if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
						{	
						     thirdEmpty = true;
						}
						else
						{
						     faults[0][0]++;
				      	       	     faults[faultrow][0]=3;
		   			       	     faults[faultrow][1]=numGroups+3;
						     faults[faultrow][2]=WRONG_VOICEMAIL_FORMAT;
						     faultrow++;
	
						}
					}
					else /*embeded*/
					{
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}
					else 
					{							
						if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0)  )	
						{
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=WRONG_VOICEMAIL_FORMAT;
						       faultrow++;
						}
						findThird=true; 
					}
					}
					
				}
				//------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlGroupsNameTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[4].headerrecord)!= 0)  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     fourthEmpty = true;
					}					
					else 
					{
						if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{	       
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;						       
	
						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;						       
						}
						else if ( strData.length() > 4) 
						{
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;						       
						}
					
						findFourth=true; 
					}
					
					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) )
					{
					   // blGroups = false;
					   numGroups=numGroups;
					}
					else
					   numGroups++;


					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) && (fourthEmpty) )
					{
					    blGroups = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
					    fourthEmpty=false;
				        }
				       
					if( (findFirst) && (findSecond) && (findThird)  && (findFourth)  )
					{
						findFirst=false; findSecond=false; findThird=false; findFourth=false; 
					} 
					else if( (!findFirst) &&  ((findSecond) || (findThird)  || (findFourth) ) )
					{	
						faults[0][0]++;
				      	    	faults[faultrow][0]=3;
		   			    	faults[faultrow][1]=numGroups+3;
					    	faults[faultrow][2]=CALL_NO_MISSING;
					    	faultrow++;					
					}
					
					   
					firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;

					
				}
				
								
			}// END blGroups
			
//-----------------------------------------------GROUPS END-----------------------------------------------------------------------------------------------------------						
			//-----------------------------------------------VIRTUAL START-----------------------------------------------------------------------------------------------------------									
			
			else if( (blVirtual)  )
			{

	  			//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlVirtualNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[0].headerrecord)!= 0 ) )
				{
					//numVirtual++;
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     firstEmpty = true;	
					     //numVirtual--;			    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true;   
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
				           	faults[0][0]++;
				      	    	faults[faultrow][0]=4;
		   			    	faults[faultrow][1]=numVirtual+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;						       					    
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					        faults[0][0]++;
				      	    	faults[faultrow][0]=4;
		   			    	faults[faultrow][1]=numVirtual+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;	
					    
					    }
					    else
					    {
						     
					    }
					    					    
					    delete [] tmpNumbers;
					}
					   	
					numberoflines++;
				}
				//------------------------------DID NUMBER -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVirtualNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[1].headerrecord)!= 0 ) )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  ) // Check if GRoup Internal Number Is Emprty 
					{										   
					     secondEmpty = true;
				    
					}
					else // Check If Valid Call Number 
					{
					    findSecond=true;  
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
					        faults[0][0]++;
 			      	    		faults[faultrow][0]=4;
		   			    	faults[faultrow][1]=numVirtual+3;
					    	faults[faultrow][2]=INVALID_DUWA;
					    	faultrow++;
	
					    }
					    else if (strData.length() > ((DID_SIZE*2) -1) )
					    {
					        faults[0][0]++;
 			      	    		faults[faultrow][0]=4;
		   			    	faults[faultrow][1]=numVirtual+3;
					    	faults[faultrow][2]=INVALID_DUWA;
					    	faultrow++;
					    }
					    else
					    {
					    	
					    }					    					    
					    
					    delete [] tmpNumbers;
					}    
						
				}
				//------------------------------DISPLAY NAME -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVirtualNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[2].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}
					else 
					{

						klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						   faults[0][0]++;
	 			      	    	   faults[faultrow][0]=4;
			   			   faults[faultrow][1]=numVirtual+3;
						   faults[faultrow][2]=INVALID_NAME;
						   faultrow++;	
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
	 			      	    	   	faults[faultrow][0]=4;
			   			   	faults[faultrow][1]=numVirtual+3;
						   	faults[faultrow][2]=INVALID_NAME;
						   	faultrow++;		
						}
						findThird=true;
					}
				}
				//----------------------------STATION TYPE ------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVirtualNameTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(),xmlVirtualNameTable[3].headerrecord)!=0) )
				{
					if ( strcmp(strData.c_str(),"empty") == 0 )
					{	
					     fourthEmpty = true;
					}					
					else
					{ 
						if(blX1)
						{
							if(strcmp ( strData.c_str(),  xmlVirtualStationTypes[5].name ) != 0  )
							{
								faults[0][0]++;
								faults[faultrow][0]=4;
		   						faults[faultrow][1]=numVirtual+3;
						        	faults[faultrow][2]=STN_TYP_UNKNOWN;
						        	faultrow++;
							}
							
							findFourth=true;
						
						}
						else
						{
						if( !CheckStationTypeVirtual(strData.c_str()) ) // ||  (strcmp(strData.c_str(),"empty") == 0) )
						{					    					    
						    faults[0][0]++;
	  			      	    	    faults[faultrow][0]=4;
			   			    faults[faultrow][1]=numVirtual+3;
						    faults[faultrow][2]=STN_TYP_UNKNOWN;
						    faultrow++;
						}
						findFourth=true;
						}
					}
				}
				//------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVirtualNameTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[4].headerrecord)!= 0)  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     fifthEmpty = true;
					}					
					else 
					{
						if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{
						    faults[0][0]++;
  				      	    	    faults[faultrow][0]=4;
			   			    faults[faultrow][1]=numVirtual+3;
						    faults[faultrow][2]=INVALID_NODEID;
						   faultrow++;

						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						    faults[0][0]++;
	  			      	    	    faults[faultrow][0]=4;
		   				    faults[faultrow][1]=numVirtual+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;
						}
						else if(strData.length() > 4)
						{
						    faults[0][0]++;
  			      		    	    faults[faultrow][0]=4;
		   				    faults[faultrow][1]=numVirtual+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;
						}
															
						findFifth=true; 
					}
					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) && (!findFifth)  )
					{
					   // blVirtual = false;
					   numVirtual = numVirtual;
					   //blVirtual = false;
					}
					else
					   numVirtual++;
						
					
					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) && (fourthEmpty) && (fifthEmpty))
					{
					    blVirtual = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
					    fourthEmpty=false;
					    fifthEmpty=false;
				        }
				       /*
				        else if(  (firstEmpty)  && ( (!secondEmpty) || (!thirdEmpty) || (!fourthEmpty)  || (!fifthEmpty)  )  )
				        {
					    faults[0][0]++;
  			      	    	    faults[faultrow][0]=4;
		   			    faults[faultrow][1]=numVirtual+2;
					    faults[faultrow][2]=CALL_NO_MISSING;
					    faultrow++;
					    
					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
					    fourthEmpty=false;
					    fifthEmpty = false;
 				        }
					*/
					if( (findFirst) && (findSecond) && (findThird)  && (findFourth) && (findFifth)  )
					{
						findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; 
					}
					else if(  (findFirst) &&  (!findFourth) )
					{
						 faults[0][0]++;
	  			      	    	 faults[faultrow][0]=4;
			   			 faults[faultrow][1]=numVirtual+3;
						 faults[faultrow][2]=STN_TYP_UNKNOWN;
						 faultrow++;						
					} 
					else if( (!findFirst) &&  ((findSecond) || (findThird)  || (findFourth) || (findFifth)  ) )
					{		
						faults[0][0]++;
  			      	    	   	faults[faultrow][0]=4;
		   			    	faults[faultrow][1]=numVirtual+3;
					   	faults[faultrow][2]=CALL_NO_MISSING;
					   	faultrow++;	
					}
					
					firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
					//numVirtual++;
				}
			

				


			}// END If VIRTUAL
//-----------------------------------------------VIRTUAL END-----------------------------------------------------------------------------------------------------------									
			
//-----------------------------------------------TRUNK GROUPS---------------------------------------------------------------------------------------------------------			
			else if( (blTrunkGroup) )
			{

				//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlTrunkGrpNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlTrunkGrpNameTable[0].headerrecord)!= 0 ) )
				{
					//numTrunkGroups++;
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     firstEmpty = true;	
					    // numTrunkGroups--;			    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true; 
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
						faults[0][0]++;
  			      	    	    	faults[faultrow][0]=5;
		   			    	faults[faultrow][1]=numTrunkGroups+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
						faults[0][0]++;
  			      	    	    	faults[faultrow][0]=5;
		   			    	faults[faultrow][1]=numTrunkGroups+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;
					    }
					    else
					    {

						     
					    					    
					    }
					    
					    delete [] tmpNumbers;
					}     	
					numberoflines++;
					
				}
				//------------------------------DISPLAY NAME -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlTrunkGrpNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlTrunkGrpNameTable[1].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     secondEmpty = true;
					}
					else 
					{
						
						klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						    faults[0][0]++;
  			      	    		    faults[faultrow][0]=5;
		   				    faults[faultrow][1]=numTrunkGroups+3;
						    faults[faultrow][2]=INVALID_NAME;
						    faultrow++;
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
						    faults[0][0]++;
  			      	    		    faults[faultrow][0]=5;
		   				    faults[faultrow][1]=numTrunkGroups+3;
						    faults[faultrow][2]=INVALID_NAME;
						    faultrow++;	
						}
						findSecond=true;
					}
				}
				//------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlTrunkGrpNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlTrunkGrpNameTable[2].headerrecord)!= 0)  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}					
					else 
					{
						if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{					       
						    faults[0][0]++;
  				      	    	    faults[faultrow][0]=5;
			   			    faults[faultrow][1]=numTrunkGroups+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;					       					       
						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						    faults[0][0]++;
  				      	    	    faults[faultrow][0]=5;
			   			    faults[faultrow][1]=numTrunkGroups+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;					       					       
						}
						else if (strData.length() > 4)
						{
						    faults[0][0]++;
  				      	    	    faults[faultrow][0]=5;
			   			    faults[faultrow][1]=numTrunkGroups+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;					       					       
						}
						findThird=true; 
					}
						
					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) && (!findFifth) && (!findSixth)  && (!findSeventh) && (!findEighth) && (!findNinth) && (!findTenth) && (!findEleventh) && (!findTwelvth)  )
					{
					    numTrunkGroups=numTrunkGroups;
					    //blTrunkGroup = false;
					}
					else
						numTrunkGroups++;
					
					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) )
					{
					    blTrunkGroup = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
				        }
				        /*else if(  (firstEmpty)  && ( (!secondEmpty) || (!thirdEmpty)  )  )
				        {
					    faults[0][0]++;
  			      	    	    faults[faultrow][0]=5;
		   			    faults[faultrow][1]=numTrunkGroups+2;
					    faults[faultrow][2]=CALL_NO_MISSING;
					    faultrow++;					       					       
					    					    
					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
 				        }	
					*/
					if( (findFirst) && (findSecond) && (findThird)  )
					{
						findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
					} 
					else if( (!findFirst) &&  ((findSecond) || (findThird)  ) )
					{	
						faults[0][0]++;
  			      	    	    	faults[faultrow][0]=5;
		   			    	faults[faultrow][1]=numTrunkGroups+3;
					    	faults[faultrow][2]=CALL_NO_MISSING;
					    	faultrow++;					       					       					    				
					}
					
					
					firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
					
				}				
				

			}
			else if( (blVoicemail)  )
			{

				//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlVoiceMailNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVoiceMailNameTable[0].headerrecord)!= 0 ) )
				{
					//numVoicemail++;
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     firstEmpty = true;	
					     //numVoicemail--;			    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true; 
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {					       
					       faults[0][0]++;
	  			      	       faults[faultrow][0]=6;
			   		       faults[faultrow][1]=numVoicemail+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					       faults[0][0]++;
	  			      	       faults[faultrow][0]=6;
			   		       faults[faultrow][1]=numVoicemail+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
				            }
					    else
					    {
						    
					    }
					    delete [] tmpNumbers;
					}     	
					numberoflines++;
					
				}
				//------------------------------DISPLAY NAME -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVoiceMailNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVoiceMailNameTable[1].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     secondEmpty = true;
					}
					else
					{
						klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE)  )
						{
					       		faults[0][0]++;
	  			      	       		faults[faultrow][0]=6;
				   		       	faults[faultrow][1]=numVoicemail+3;
						       	faults[faultrow][2]=INVALID_NAME;
						       faultrow++;
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
	  			      	       		faults[faultrow][0]=6;
				   		       	faults[faultrow][1]=numVoicemail+3;
						       	faults[faultrow][2]=INVALID_NAME;
						       faultrow++;	
						}
						findSecond=true; 
					}
				}
				//------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVoiceMailNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVoiceMailNameTable[2].headerrecord)!= 0)  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}					
					else
					{
						 if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{					       
					       		faults[0][0]++;
		  			      	       	faults[faultrow][0]=6;
				   		       faults[faultrow][1]=numVoicemail+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;
						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						       faults[0][0]++;
		  			      	       faults[faultrow][0]=6;
				   		       faults[faultrow][1]=numVoicemail+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;
						}
						else if(strData.length() > 4)
						{
						       faults[0][0]++;
		  			      	       faults[faultrow][0]=6;
				   		       faults[faultrow][1]=numVoicemail+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;
						}
						
						findThird=true; 
					}					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					
					if( (!findFirst) && (!findSecond) && (!findThird) )
					{
						numVoicemail = numVoicemail;
						 //blVoicemail = false;
						
					} 
					else
						numVoicemail++;
						
					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) )
					{
					    blVoicemail = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
				        }										
					
					else if( (!findFirst) &&  ((findSecond) || (findThird) ) )
					{		
						faults[0][0]++;
	  			      	  	faults[faultrow][0]=6;
			   		    	faults[faultrow][1]=numVoicemail+3;
					    	faults[faultrow][2]=CALL_NO_MISSING;
					    	faultrow++;		
					}
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;	
					firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;
					//numVoicemail++;
				}
				
			} // end if voicemail
			
//-----------------------------------------------SipConfig-----------------------------------------------------------------------------------------------------------									
			
			else if( (blSipConfig)  )
			{

	  			//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlSipConfigTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[0].headerrecord)!= 0 ) )
				{
					
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     firstEmpty = true;	
					     		    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true;   
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
				           	faults[0][0]++;
				      	    	faults[faultrow][0]=7;
		   			    	faults[faultrow][1]=numSipConfig+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;						       					    
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					        faults[0][0]++;
				      	    	faults[faultrow][0]=7;
		   			    	faults[faultrow][1]=numSipConfig+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;	
					    
					    }
					    else
					    {
						     
					    }
					    					    
					    delete [] tmpNumbers;
					}
					   	
					numberoflines++;
				}
				//------------------------------Password Sip -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlSipConfigTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[1].headerrecord)!= 0 ) )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  ) // Check if GRoup Internal Number Is Emprty 
					{										   
					     secondEmpty = true;
				    
					}
					else // Check If Valid Call Number 
					{
					    findSecond=true;  
					    klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						   faults[0][0]++;
	 			      	    	   faults[faultrow][0]=7;
			   			   faults[faultrow][1]=numSipConfig+3;
						   faults[faultrow][2]=INVALID_PASSWORD;
						   faultrow++;	
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
	 			      	    	   	faults[faultrow][0]=7;
			   			   	faults[faultrow][1]=numSipConfig+3;
						   	faults[faultrow][2]=INVALID_PASSWORD;
						   	faultrow++;		
						}
					    // Here will check the type of password					    
					}    
						
				}
				//------------------------------UserId/Username  -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlSipConfigTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[2].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}
					else 
					{

						klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						   faults[0][0]++;
	 			      	    	   faults[faultrow][0]=7;
			   			   faults[faultrow][1]=numSipConfig+3;
						   faults[faultrow][2]=INVALID_USERID_USERNAME;
						   faultrow++;	
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
	 			      	    	   	faults[faultrow][0]=7;
			   			   	faults[faultrow][1]=numSipConfig+3;
						   	faults[faultrow][2]=INVALID_USERID_USERNAME;
						   	faultrow++;		
						}
						findThird=true;
					}
				}
				//----------------------------Realm ------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlSipConfigTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(),xmlSipConfigTable[3].headerrecord)!=0) )
				{
					if ( strcmp(strData.c_str(),"empty") == 0 )
					{	
					     fourthEmpty = true;
					}					
					else
					{ 						
						klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						   faults[0][0]++;
	 			      	    	   faults[faultrow][0]=7;
			   			   faults[faultrow][1]=numSipConfig+3;
						   faults[faultrow][2]=INVALID_REALM;
						   faultrow++;	
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
	 			      	    	   	faults[faultrow][0]=7;
			   			   	faults[faultrow][1]=numSipConfig+3;
						   	faults[faultrow][2]=INVALID_REALM;
						   	faultrow++;		
						}   
					  findFourth=true;						
					}
				}
				//------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlSipConfigTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[4].headerrecord)!= 0)  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     fifthEmpty = true;
					}					
					else 
					{
						if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{
						    faults[0][0]++;
  				      	    	    faults[faultrow][0]=7;
			   			    faults[faultrow][1]=numSipConfig+3;
						    faults[faultrow][2]=INVALID_NODEID;
						   faultrow++;

						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						    faults[0][0]++;
	  			      	    	    faults[faultrow][0]=7;
		   				    faults[faultrow][1]=numSipConfig+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;
						}
						else if(strData.length() > 4)
						{
						    faults[0][0]++;
  			      		    	    faults[faultrow][0]=7;
		   				    faults[faultrow][1]=numSipConfig+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;
						}
															
						findFifth=true; 
					}
					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) && (!findFifth)  )
					{
					   
					   numSipConfig = numSipConfig;
					}
					else
					   numSipConfig++;
						
					
					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) && (fourthEmpty) && (fifthEmpty))
					{
					    blSipConfig = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
					    fourthEmpty=false;
					    fifthEmpty=false;
				        }
				       
				}
			

				


			}// END If SipConfig
//-----------------------------------------------SipConfig-----------------------------------------------------------------------------------------------------------									
			
		}  // END // If the Record is OK
		

	countLine++;//increase countLines number to numberring Lines   
	
    }// ----end while read lines-------    
    type[0] = numStations; // Licenses Number   
    type[1] = 0; // Licenses Number
    type[2] = numGroups;   // Group Number
    type[3] = numVirtual;   //  Virtual Number
    type[4] = numTrunkGroups; // Trunk number
    type[5] = numVoicemail;   // Voicemail Number 
    type[6] = numSipConfig;   // Voicemail Number 
    
    if(corXml==0)
    {
	    faults[0][0]++;
	    faults[faultrow][0]=1;
	    faults[faultrow][1]= 0; // invalid Xml with no contents 
	    faults[faultrow][2]=INVALID_FILE_FORMAT;
	    faultrow++;	
    }
    
    errorCount = faultrow; 

    fclose(fxml);
    
    if(faults[0][0]==0)
    return  0; 
    else 
    return errorCount;  

    
  //
}


int  checkXmlFormatErrorsUsa(char* fname, int type[7], int errorCount,int faults[21][3])
{
    char line [128]; 
    char *tmpNumbers;
    FILE *fxml = fopen(fname,"r");
    int fLast,fFirst,intLen,wksFound,findNameCell=0,findCell=0,countLine=0,rowCount=0,result=-1,wksRowFound,corXml=0,klen=0,fFiltDb=0,uc_count=0,icurrentrow=0;
    string tempstr,totalstr,strData,strCell,strtmpNumDid="",strtmpFaxDid="";  
    //bool blStations=false,blCellEnd=false,blEndRecord=false,blX1=false;    
    int i=0,pos=0,numStations=0,numLicenses=0,numGroups=0,numVoicemail=0,numVirtual=0,numTrunkGroups=0,numberoflines=1,faultrow=1,record=0,block=0,numSipConfig=0,icountCallPick=0;
    bool blStations=false,blLicenses=false,blGroups=false,blVirtual=false,blTrunkGroup=false,blVoicemail=false,blCellEnd=false,blEndRecord=false,blX1=false,blSipConfig=false;
    bool firstEmpty=false,secondEmpty=false,thirdEmpty=false,fourthEmpty=false,fifthEmpty=false,sixthEmpty=false,seventhEmpty=false,eighthEmpty=false,ninthEmpty=false,tenthEmpty=false,eleventhEmpty=false
    ,twelvthEmpty=false,therteenthEmpty=false,fourteenthEmpty=false,fifteenthEmpty=false,sixteenthEmpty=false,seventeenthEmpty=false,eighteenthEmpty=false,nineteenthEmpty=false,twentyteenthEmpty=false;
    bool findFirst=false,findSecond=false,findThird=false,findFourth=false,findFifth=false,findSixth=false,findSeventh=false,findEighth=false,findNinth=false,findTenth=false,findEleventh=false,findTwelvth=false,findTherteenth=false;
    bool findFourteenth=false,findFifteenth=false,findSixteenth=false,findSeventeenth=false,findEighteenth=false,findNingteenth=false,findtwenteenth=false;
    bool twentyoneEmpty=false,twentytwoEmpty=false,twentythreeEmpty=false,twentyfourEmpty=false,twentyfiveEmpty=false,twentysixEmpty=false,twentysevenEmpty=false,twentyEightEmpty=false,twentynineEmpty=false;
    bool findtwentyone=false,findtwentytwo=false,findtwentythree=false,findtwentyfour=false,findtwentyfive=false,findtwentysix=false,findtwentyseven=false,findtwentyEight=false,findtwentynine=false;
//    unsigned char chEmpty;
    RD_KDS_RETURN			kdsreturn,kdsreturnacode;
    RD_KDS_RETURN           kdsreturnX1;
    char * sacode;
    int  inhalt[256];
    
    
    
    
    // uc_count= Db_rddtb((enum KDS_TABLE) KDS_VPLRN_DDI, (DB_ZEILE_T)0, (DB_SPALTE_T)KEINE_SPALTE, &kdsreturnacode );
    // FPUti::bcd_to_a ( &kdsreturnacode.inhalt[0], inhalt, (WORD)uc_count );   
     
    
    
    
   // Db_rddtb(KDS_AUSBAU_VAR,KDS_ANLAGEN_AUSBAU,KEINE_SPALTE,(RD_KDS_RETURN*)&kdsreturnX1);   // takes System type 

   // if(kdsreturnX1.inhalt[0]==DS_BPL_ONE_X1)  //DS_BPL_ONE
  //	blX1=true; // means system is X1
	
    errorCount = 0;
        
    for(i=0;i<21;i++)
    {
	for(pos=0;pos<3;pos++)
		faults[i][pos]=0;
    }
    
    
// -- Prepei na mpoun edo kai Safe Conditions an Skasei        
    while ( fgets ( line,128,fxml ) != NULL ) // read a line by line
    {
	
	if (faultrow > 20)
		break;
	
	tempstr=line; // this temp str contains the current line
	intLen = strlen(line);
	
	//---1-find----WorkSheet name ------------------------------
	wksFound= tempstr.find("Worksheet ss:Name");

	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
	        fFirst= tempstr.find("\"");
	        fLast=tempstr.find_last_of("\"");   
	        tempstr = tempstr.substr(fFirst+1,(fLast-(fFirst+1)));		

		if(tempstr == "Customer")
		{
	   	   blStations = true;
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name   
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;
		   countLine=0;
		   corXml++;
		}
		else if(tempstr =="Groups")		
		{
		   blGroups = true;		    
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 		
		   countLine=0;		
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;
		   corXml++;		   
		}
		else if(tempstr =="Virtual")		
		{
		   blVirtual = true;
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 		
		   countLine=0;		
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;
		   corXml++;		   
		   
		}
		else if(tempstr =="Trunk Groups")
		{
		   blTrunkGroup = true;		
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 		   
		   countLine=0;		
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;
		   corXml++;		   

		}
		else if(tempstr =="Voicemail")	
		{
		   blVoicemail = true;		   
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 		   
		   countLine=0;		
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;
		   corXml++;
		}
		else if(tempstr =="SipConfig")	
		{
		   blSipConfig = true;		   
		   block=0;          
		   record=0;        
		   countLine=0;		
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;
		   corXml++;
		}

    }// end worksheet search 

	//---2 find the End of WorkSheet-------------
	wksFound= tempstr.find("</Worksheet>");
	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{				
		if(blStations)
		{
			blStations = false;
		}		
		else if(blGroups)
		{
			blGroups = false;
		}
		else if(blVirtual)
		{
			blVirtual = false;
		}
		else if(blTrunkGroup)
		{
			blTrunkGroup = false;
		}
		else if(blVoicemail)
		{
			blVoicemail = false;
				
		}
		else if(blSipConfig)
		{
			blSipConfig = false;
			break;	
		}

	}


	blEndRecord = false;
	//if(blStations)
	//{
	
		wksFound = tempstr.find("</Data>");
		findNameCell = tempstr.find("<NamedCell");
		findCell = tempstr.find("</Cell>");
		wksRowFound = tempstr.find("</Row>");
		fFiltDb = tempstr.find("FilterDatabase");
		//  CASE  A -- Check if the line is empty, has no data, only namedcell
		if((findNameCell > -1) && (wksFound == -1)  && (fFiltDb==-1) ) 
		{
			fLast = tempstr.find("</Cell>");
			fLast = fLast -3;
			fFirst = tempstr.rfind("=\"");
			fFirst  = fFirst+2;
			strCell = tempstr.substr(fFirst,(fLast-fFirst));
			strData = "empty";
			blEndRecord = true;
		}
		// CASE B scenario we had Data and NameCell Filled in the Same Line 		
		else if( (wksFound > -1) && (findNameCell > -1)  && (findCell >-1) )
		{			
			//cell name
			fLast = tempstr.find("</Cell>");
			fLast = fLast -3;
			fFirst = tempstr.rfind("=\"");
			fFirst  = fFirst+2;
			strCell = tempstr.substr(fFirst,(fLast-fFirst));
			//data 
			fLast = wksFound;  //tempstr.find("</Data>");
			fFirst = tempstr.rfind("\">");
			strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));
			blEndRecord = true;	
		}
		// CASE C -- Has Data and NameCell but the Cell END is in the next Line
		else if( (wksFound > -1) && (findNameCell > -1)  && (findCell == -1) )
		{
			//data
			fLast = wksFound;  //tempstr.find("</Data>");
			fFirst = tempstr.rfind("\">");
			
			strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));

			if(strData.length() == 0 )
				strData = "empty";

			//cout << " \n ******strData="<<strData<<endl;
			blCellEnd = true; // wait the end of the Cell	

			//printf("\n strData=%s \n",strData);
		}
		else if( (findCell > -1) &&  (blCellEnd)  ) // find the end of Cell
		{
			blCellEnd = false;
			//cell name
			fLast = tempstr.find("</Cell>");
			fLast = fLast -3;
			fFirst = tempstr.rfind("=\"");
			fFirst  = fFirst+2;
			strCell = tempstr.substr(fFirst,(fLast-fFirst));
			//cout << " \n -------strCell="<<strCell<<endl;
			//printf("\n strCell=%s \n",strCell);
			blEndRecord = true;
		}
		else if(wksRowFound > -1)	
		{
			blEndRecord = true;
			strData = "</Row>";
			strCell="";
		}
		
		if(blEndRecord)
		{	
			if(strCell != "_FilterDatabase")
		  icurrentrow++;
		}
		
		//  When Find a Record the blEndRecord is TRUE 
		if((blEndRecord)  &&  (faultrow <21)   && (icurrentrow > 35))
		{
			
//----------------Start ----  Validation -- Check If the Header of Each  Sheet Is Correct ----------------------------------------------			
			if(blStations) 
			{								
				if(record >30)
				{
				  block++;
				  record = 0;
				  firstEmpty=false; secondEmpty=false; thirdEmpty=false;   fourthEmpty=false;   fifthEmpty=false; sixthEmpty=false; seventhEmpty=false;   eighthEmpty=false;	
				  ninthEmpty=false; tenthEmpty=false; eleventhEmpty=false; twelvthEmpty=false; therteenthEmpty=false;fourteenthEmpty=false; fifteenthEmpty=false; 
				  sixteenthEmpty=false; seventeenthEmpty=false; eighteenthEmpty=false; nineteenthEmpty=false; twentyteenthEmpty=false;twentyoneEmpty=false; twentytwoEmpty=false;
				  twentythreeEmpty=false; twentyfourEmpty=false; twentyfiveEmpty=false; twentysixEmpty=false; twentysevenEmpty=false; twentyEightEmpty=false; twentynineEmpty=false;
				}
			  }
			if(blGroups) 
			  {
				if(record >4)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
				}					
			   }
			  
			  if(blVirtual) 
			  {
				if(record >4)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
				}
							
			   }
			   
			  if(blTrunkGroup) 
			  {
				if(record >2)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
				}								
			   }
			   
			  if(blVoicemail) 
			  {
				if(record >2)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
				}				
			   }
			   if(blSipConfig)
			   {
				if(record >4)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
				}				
			   }
			   
			  					
//----------------END ----  Validation -- Check If the Header of Each  Sheet Is Correct ----------------------------------------------						
			
//----------------------------------------------Customer --------------------------------------------------------------------------------------------------------------
			if( (blStations) )// &&  (block > 0) )
			{
				
				//---------------------------ID---nodeid------------------------------------------------------


				cout << "\n--  strCell="<<strCell << "   --  strData="<<strData<<endl;

				if( ( strcmp(strCell.c_str(),xmlUsaElements[0].element ) == 0 )  )				  
				{														
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					    firstEmpty = true; 
					}
					else
					{
					    findFirst = true;
					    /* node ID  must be a number other case return error code */
					    if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
					    {
						  faults[0][0]++;
						  faults[faultrow][0]=1;
						  faults[faultrow][1]=numStations+3;
						  faults[faultrow][2]=INVALID_NODEID;
						  faultrow++;
					    }
					    /*  node ID must be betwwen 0....999, it's refered to nodeID number */
					    else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
					    {
						  faults[0][0]++;
						  faults[faultrow][0]=1;
						  faults[faultrow][1]=numStations+3;
						  faults[faultrow][2]=INVALID_NODEID;
						  faultrow++;
					    }
					    /*  node Id cannot be greater than 999, if we have more than 3 digits return error code.*/
					    else if( strData.length() > 4 )
					    {
						  faults[0][0]++;
			      			  faults[faultrow][0]=1;
		   				  faults[faultrow][1]=numStations+3;
						  faults[faultrow][2]=INVALID_NODEID;
						  faultrow++;
					    }
					    
					}
					  
				}
				//-----------------------END----NODE ID ------------------------------------------------------
				//-------------------------SITENAME-----------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[1].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					    secondEmpty = true; 
					}
					else
					{
					    findSecond = true;
					    //----------------site name  max length 50characters------------------
					    klen=0;
					    klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
				            /*-----search for invalid characters ------------------------*/		      
					    if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_SITENAME;
						faultrow++;	
					    }
					    /*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					    else if( (strData.length() > (MAXLENSTRS_CUSTOMER))     &&   (klen>MAXLENSTRS_CUSTOMER ) )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_SITENAME;
						faultrow++;	
					    }
					}
					
				}
				//------------------------END SITE NAME---------------------------------
				
				//------------------------UC TYPE---------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[2].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					    thirdEmpty = true; 
					}
					else
					{
					    findThird = true;
					    //----------------site name  max length 50characters------------------
					    klen=0;
					    klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
				            /*-----search for invalid characters ------------------------*/		      
					    if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_UCTYPE;
						faultrow++;	
					    }
					    /*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					    else if( (strData.length() > (MAXLENSTRS_CUSTOMER))     &&   (klen>MAXLENSTRS_CUSTOMER ) )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_UCTYPE;
						faultrow++;	
					    }
					    else if(  (strcmp(strData.c_str(),"UC Suite")!=0) && (strcmp(strData.c_str(),"UC Smart")!=0))	
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_UCTYPE;
						faultrow++;	
					    
					    }
					    
					}
					
				}				
				//------------------------END UC TYPE ----------------------------------
				
				//------------------------Call PickUp Groups---------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[3].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					    fourthEmpty = true; 
					}
					else
					{
					    findFourth = true;
					    //----------------site name  max length 50characters------------------
					    klen=0;
					    klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
				            /*-----search for invalid characters ------------------------*/		      
					    if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_CALLPICKUP;
						faultrow++;	
					    }
					    /*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					    else if( (strData.length() > (MAXLENSTRS_CUSTOMER))     &&   (klen>MAXLENSTRS_CUSTOMER ) )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_CALLPICKUP;
						faultrow++;	
					    }
					    
					    icountCallPick++;
					    if(icountCallPick > 64)
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=111;			
						faultrow++;
					    }
					
					    
					}
					
				}				
				//------------------------END Call PickUp Groups ----------------------------------
				//MAXLENSTR_NAME
				
				//--------------------LAST NAME-------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[4].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					    fifthEmpty = true; 
					}
					else
					{   
					    
					    findFifth = true;
					    //----------------site name  max length 32 characters------------------
					    klen=0;
					    klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
				            /*-----search for invalid characters ------------------------*/		      
					    if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_LASTNAME;
						faultrow++;	
					    }
					    /*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					    else if( (strData.length() > (MAXLENSTR_NAME))     &&   (klen>MAXLENSTR_NAME ) )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_LASTNAME;
						faultrow++;	
					    }
					    
					    
					}
					
				}
				//--------------------END LAST NAME---------------------------------------------------
				
				//--------------------FIRST NAME-------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[5].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					    sixthEmpty = true; 
					}
					else
					{
					    findSixth = true;
					    //----------------site name  max length 32 characters------------------
					    klen=0;
					    klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
				            /*-----search for invalid characters ------------------------*/		      
					    if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_FIRSTNAME;
						faultrow++;	
					    }
					    /*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					    else if( (strData.length() > (MAXLENSTR_NAME))     &&   (klen>MAXLENSTR_NAME ) )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_FIRSTNAME;
						faultrow++;	
					    }
					}
					
				}
				//--------------------END FIRST NAME---------------------------------------------------
				
				//--------------------DISPLAY NAME-----------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[6].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					    seventhEmpty = true; 
					}
					else
					{
					    findSeventh = true;
					    //----------------site name  max length 32 characters------------------
					    klen=0;
					    klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
				            /*-----search for invalid characters ------------------------*/		      
					    if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_NAME_CHARACTERS;
						faultrow++;	
					    }
					    /*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					    else if( (strData.length() > (MAXLENSTR_NAME*2))     &&   (klen>MAXLENSTR_NAME*2 ) )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_NAME;
						faultrow++;	
					    }
					}
					
				}
				//--------------------END DISPLAY NAME-----------------------------------------------------
				
				//--------------------INTERNAL NUMBER------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[7].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					    eighthEmpty = true; 
					}
					else
					{
					    cout << "\n  strData="<<strData<< "   strCell="<<strCell <<endl;
						findEighth = true;
					    // THIS VARIABLE MUST REINIT IN EACHE END OF </ROW>
					    strtmpNumDid = strData.c_str();//This variable is used in case where the DID is 'X', this means that the DID number is same as Internal Number
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());
					    if(!checkvalidCallDuwa(tmpNumbers))
					    {				       
					       faults[0][0]++;
					       faults[faultrow][0]=1;
   					       faults[faultrow][1]=numStations+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
					    				    
					    }
					    else if(strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					       faults[0][0]++;
					       faults[faultrow][0]=1;
   					       faults[faultrow][1]=numStations+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
			    
					    }
					    else
					    {
					
					    }
					    //----------call old Checks --------------------------------------					    
					    delete[] tmpNumbers;
					}
				}
				//-------------------END INTERNAL NUMBER--------------------------------------------------- 
				
				//-------------------DID-------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[8].element ) == 0 )  )				  
				{
				  bool 	bltmpnumdid=false;
				  string strtmp_1="";
				  
				  if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				  {	
				    ninthEmpty = true; 
				  }
				  else
				  {
					  findNinth = true;
					  if(  (strcmp(strData.c_str(),"x")==0) || (strcmp(strData.c_str(),"X")==0))	
					  {
						if(!findEighth) // Internal number FLAG 
						{
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=INVALID_CALL_NO;
						   faultrow++;
						}
						else
						    bltmpnumdid = true;												
					    }
					    
					    
					    if(bltmpnumdid)
					    {
						tmpNumbers = new char[strtmpNumDid.length()+1];  
						strcpy(tmpNumbers,strtmpNumDid.c_str());
						strtmp_1 = strtmpNumDid;						
					    }
					    else
					    {
						tmpNumbers = new char[strData.length()+1];  
						strcpy(tmpNumbers,strData.c_str());
						strtmp_1 = strData;
						
						
					    }
					    
					    if( (!checkvalidCallDuwa(tmpNumbers) )  ||  (strcmp(strData.c_str(),"empty") == 0) ) 
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
	   					faults[faultrow][1]=numStations+3;
					        faults[faultrow][2]=INVALID_DUWA;
					        faultrow++;						    
					    }
					    else if(strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {						       
						faults[0][0]++;
						faults[faultrow][0]=1;
	   					faults[faultrow][1]=numStations+3;
					        faults[faultrow][2]=INVALID_DUWA;
					        faultrow++;			    
					    }
					    else
					    {
						
					    }
					    
					    
					    
					    
					    delete[] tmpNumbers;
					}
				}
				//-------------------END DID---------------------------------------------------------------
				
				//------------------EMAIL ADDRESS----------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[9].element ) == 0 )  )				  
				{
				    if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)   )
				    {	
					tenthEmpty = true;
				    }					
				    else
				    {
					findTenth=true;	
				
					tmpNumbers = new char[strData.length()+1];  
					strcpy(tmpNumbers,strData.c_str());

					if( !checkvalidmail(tmpNumbers) )
					{	
					    faults[0][0]++;
	      				    faults[faultrow][0]=1;
   					    faults[faultrow][1]=numStations+3;
				            faults[faultrow][2]=INVALID_EMAIL;
				            faultrow++;
					}
					else if(strData.length() >  MAX_EMAIL )
					{
					    faults[0][0]++;
		      			    faults[faultrow][0]=1;
	   				    faults[faultrow][1]=numStations+3;
					    faults[faultrow][2]=INVALID_EMAIL;
					    faultrow++;		
					}						
						delete [] tmpNumbers;
				    }
				}
				//------------------END EMAIL ADDRESS----------------------------------------------------------
				
				//------------------MOBILE ----------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[10].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     eleventhEmpty = true;
					}
					else
					{
						findEleventh=true; 
						

						tmpNumbers = new char[strData.length()+1];  
						strcpy(tmpNumbers,strData.c_str());

						if( !checkvalidnumber(tmpNumbers) )
						{					    							    
						    faults[0][0]++;
		      				    faults[faultrow][0]=1;
	   					    faults[faultrow][1]=numStations+3;
					            faults[faultrow][2]=INVALID_MOBILE;
					            faultrow++;	
						}
						else if(strData.length() > MAX_MOBILE)
						{
						    faults[0][0]++;
		      				    faults[faultrow][0]=1;
	   					    faults[faultrow][1]=numStations+3;
					            faults[faultrow][2]=INVALID_MOBILE;
					            faultrow++;	
				
						}
						delete [] tmpNumbers;
					}
				}
				//------------------END MOBILE-------------------------------------------------------
				
				//------------------DEVTYPE----------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[11].element ) == 0 )  )				  
				{
					if ( strcmp(strData.c_str(),"empty") == 0 )
					{	
					     twelvthEmpty = true;
					}					
					else 
					{
						findTwelvth=true; 
						if( !checkDevType(strData.c_str()) )
						{					    
							faults[0][0]++;
							faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=STN_TYP_UNKNOWN;
						        faultrow++;	
						}
						
					}
				}
				//------------------END DEVTYPE-----------------------------------------------------
				
				//-----------------Voicemail---------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[12].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					therteenthEmpty = true; 
				      }
				      else
				      {
					  findTherteenth = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=WRONG_VOICEMAIL_FORMAT; // Fix ERROR
						   faultrow++;
					  }
				      }
					    
				}
				//-----------------End VoiceMail-----------------------------------------------------
				
				//-----------------Outlook Addin-----------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[13].element ) == 0 )  )				  
				{
				     if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					fourteenthEmpty = true; 
				      }
				      else
				      {
					  findFourteenth = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=INVALID_OUTLADD; 
						   faultrow++;
					  }
				      }
				}
				//-----------------END Outlook Addin-------------------------------------------------
				
				//-----------------UC Client---------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[14].element ) == 0 )  )				  
				{
				    if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					fifteenthEmpty = true; 
				      }
				      else
				      {
					  findFifteenth = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=INVALID_UCCLIENT; 
						   faultrow++;
					  }
				      }
				}
				//-----------------End UC Client-----------------------------------------------------
				
				//-----------------UC FaAx-----------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[15].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					sixteenthEmpty = true; 
				      }
				      else
				      {
					  findSixteenth = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=INVALID_UCFAX; // Fix ERROR
						   faultrow++;
					  }
				      }
				}
				//-----------------End UC Fax---------------------------------------------------------
				
				//-----------------Fax Callno---------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[16].element ) == 0 )  )				  
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if Internal Number Is Emprty 
					{					   
					    seventeenthEmpty = true;					    
					}
					else // Check If Valid Call Number 
					{
					    findSeventeenth=true;
					    strtmpFaxDid = strData;
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());
					    if(!checkvalidCallDuwa(tmpNumbers))
					    {				       
					       faults[0][0]++;
					       faults[faultrow][0]=1;
   					       faults[faultrow][1]=numStations+3;
					       faults[faultrow][2]=INVALID_FAXCALLNO;
					       faultrow++;
					    				    
					    }
					    else if(strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					       faults[0][0]++;
					       faults[faultrow][0]=1;
   					       faults[faultrow][1]=numStations+3;
					       faults[faultrow][2]=INVALID_FAXCALLNO;
					       faultrow++;
			    
					    }
					    else//----------call old Checks --------------------------------------
					    {						
						
					     }//----------call old Checks --------------------------------------					    					    
					    delete[] tmpNumbers;
				         }
				}
				//-----------------END Fax Callno-----------------------------------------------------
				
				//-----------------Fax DID------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[17].element ) == 0 )  )				  
				{
				  bool bltmpfaxdid = false;
				  string strtmp_1="";
					  
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if Internal Number Is Emprty 
					{					   
					    eighteenthEmpty = true;					    
					}
					else // Check If Valid Call Number 
					{
					    findEighteenth = true;
					    
					    if(  (strcmp(strData.c_str(),"x")==0) || (strcmp(strData.c_str(),"X")==0))	
					    {
						if(!findSeventeenth) // Internal number FLAG 
						{
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=INVALID_FAXCALLNO;
						   faultrow++;
						}
						else
						    bltmpfaxdid = true;												
					    }
					    
					    if(bltmpfaxdid)
					    {
						tmpNumbers = new char[strtmpFaxDid.length()+1];  
						strcpy(tmpNumbers,strtmpFaxDid.c_str());
						strtmp_1 = strtmpFaxDid;
						
					    }
					    else
					    {
						tmpNumbers = new char[strData.length()+1];  
						strcpy(tmpNumbers,strData.c_str());
						strtmp_1 = strData;
						
					    }
					    					    
						 //Check if Valid Number  Duwa or Is Empty Then Error
						if( (!checkvalidCallDuwa(tmpNumbers) )   ) 
						{
					     	        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_FAXDID;
					                faultrow++;
						    
						}
						else if(strtmp_1.length() > ((RUFNR_SIZE*2) -2 ))
					    	{						       
						        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_FAXDID;
					                faultrow++;
			    
					    	}
						        							
						else
						{						    	
							
						}
						delete[] tmpNumbers;
					    
					    
					    
					}
				}
				//----------------END Fax DID---------------------------------------------------------
				
				//----------------FAX name------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[18].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     //thirdEmpty = true;
					     nineteenthEmpty = true;
					}

					else 
					{
						//findThird=true; 
						findNingteenth=true;
						klen=0;
						klen= my_strlen_utf8_c(strData.c_str());
						if( (strData.length() > (TLN_NAME_SIZE))     &&   (klen>TLN_NAME_SIZE ) )
						{
						    	faults[0][0]++;
							faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=INVALID_FAX_NAME;
						        faultrow++;	
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
							faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=INVALID_FAX_NAME;
						        faultrow++;	
						}
												
					}
				}
				//----------------END FAX name--------------------------------------------------------
				
				//----------------Conference Server---------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[19].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentyteenthEmpty = true; 
				      }
				      else
				      {
					  findtwenteenth = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=INVALID_CONFSERV; 
						   faultrow++;
					  }
				      }
				}
				//----------------END Conference Server-----------------------------------------------
				
				//----------------My Attendant--------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[20].element ) == 0 )  )				  
				{
				    if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentyoneEmpty = true; 
				      }
				      else
				      {
					  findtwentyone = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=LIC_TYP_MYATTEND; // Fix ERROR
						   faultrow++;
					  }
				      }
				}
				//----------------END My Attendant----------------------------------------------------
				
				//----------------myagent-------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[21].element ) == 0 )  )				  
				{
				    if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentytwoEmpty = true; 
				      }
				      else
				      {
					  findtwentytwo = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=LIC_TYP_MYAGENT; // Fix ERROR
						   faultrow++;
					  }
				      }
				}
				//----------------END myagent---------------------------------------------------------
				
				//----------------Application Launcher------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[22].element ) == 0 )  )				  
				{	
				    if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentythreeEmpty = true; 
				      }
				      else
				      {
					  findtwentythree = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=LIC_TYP_APPLAUNCH; // Fix ERROR
						   faultrow++;
					  }
				      }
				}
				//----------------END Application Launcher--------------------------------------------
				
				//----------------TAPI------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[23].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentyfourEmpty = true; 
				      }
				      else
				      {
					  findtwentyfour = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=LIC_TYP_TAPI; // Fix ERROR
						   faultrow++;
					  }
				      }
				}
				//----------------END TAPI --------------------------------------------
				
				//----------------Class of service------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[24].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentyfiveEmpty = true; 
				      }
				      else
				      {
					findtwentyfive = true;
					if(  (strcmp(strData.c_str(),"national")!=0) && (strcmp(strData.c_str(),"international")!=0)  && (strcmp(strData.c_str(),"internal")!=0))	
					{						
					   faults[0][0]++;
					   faults[faultrow][0]=1;
					   faults[faultrow][1]=numStations+3;
					   faults[faultrow][2]=INVALID_COS; // Fix ERROR
					   faultrow++;
					}
					
				      }
				}
				//----------------END Class of sertvice --------------------------------------------
				
				
				//----------------Call PickUp ------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[25].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentysixEmpty = true; 
				      }
				      else
				      {
					findtwentysix = true;
					klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
					/*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					if( (strData.length() > (MAXLENSTRS_CUSTOMER))     &&   (klen>MAXLENSTRS_CUSTOMER ) )
					{
					  faults[0][0]++;
					  faults[faultrow][0]=1;
					  faults[faultrow][1]=numStations+3;
					  faults[faultrow][2]=INVALID_CALLPICKUP;// FIX Error Message 
					  faultrow++;	
					}
					
				      }
				}
				//----------------END Call PickUp --------------------------------------------
				
				
				//----------------Network Sites------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[26].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentysevenEmpty  = true; 
				      }
				      else
				      {
					findtwentyseven = true;
					klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
					/*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					if( (strData.length() > (MAXLENSTRS_CUSTOMER))     &&   (klen>MAXLENSTRS_CUSTOMER ) )
					{
					  faults[0][0]++;
					  faults[faultrow][0]=1;
					  faults[faultrow][1]=numStations+3;
					  faults[faultrow][2]=INVALID_NETWSITE;// FIX Error Message 
					  faultrow++;	
					}
					
				      }
				}
				//----------------END Network Sites --------------------------------------------
				
				
				//----------------Secondary GW------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[27].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentyEightEmpty  = true; 
				      }
				      else
				      {
					findtwentyEight = true;
					klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
					/*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					if( (strData.length() > (MAXLENSTRS_CUSTOMER))     &&   (klen>MAXLENSTRS_CUSTOMER ) )
					{
					  faults[0][0]++;
					  faults[faultrow][0]=1;
					  faults[faultrow][1]=numStations+3;
					  faults[faultrow][2]=INVALID_SECGW;// FIX Error Message 
					  faultrow++;	
					}
					
				      }
				}
				//----------------END Secondary GW --------------------------------------------
				
				
				//----------------Access------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[28].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentynineEmpty  = true; 
				      }
				      else
				      {
					findtwentynine = true;
					i = strData.find("-");
					if( (i == -1)  || (strData.length() <3)  || ( (strData.length() - i) < 1 )  || (i==0) )
					{
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
					        faults[faultrow][2]=WRONG_ACEESS_FORMAT;
					        faultrow++;	
					}
				
					tmpNumbers = new char[strData.length()+1];  
					strcpy(tmpNumbers,strData.substr(0,strData.find(" ")).c_str());
					//strcpy(tmpNumbers,strData.c_str());
					if(checkvalidAccess(tmpNumbers) == false)
					{						
						faults[0][0]++;
						faults[faultrow][0]=1;
	   					faults[faultrow][1]=numStations+3;
					        faults[faultrow][2]=WRONG_ACEESS_FORMAT;
					        faultrow++;	
					}
					else if (( strcmp("Master",strData.substr(strData.find(" ")+1).c_str() )  !=0   )   &&	( strcmp("Slave",strData.substr(strData.find(" ")+1).c_str() )  !=0   ) )
					{
						faults[0][0]++;
						faults[faultrow][0]=1;
						faults[faultrow][1]=numStations+3;
					        faults[faultrow][2]=WRONG_ACEESS_FORMAT;
					        faultrow++;							
					}
					
				      }
				}
				//----------------END Acess --------------------------------------------
				
				
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					

					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) && (fourthEmpty) && (fifthEmpty) && (sixthEmpty) && (seventhEmpty) && (eighthEmpty)&& (ninthEmpty)&&(tenthEmpty) &&(eleventhEmpty) &&
					(twelvthEmpty)   &&  (therteenthEmpty) &&  (fourteenthEmpty) &&  (fifteenthEmpty) &&  (sixteenthEmpty)  &&  (seventeenthEmpty)  &&  (eighteenthEmpty) &&  (nineteenthEmpty) &&  (twentyteenthEmpty)
					&&  (twentyoneEmpty) &&  (twentytwoEmpty) &&  (twentythreeEmpty) &&  (twentyfourEmpty) &&  (twentyfiveEmpty)  &&  (twentysixEmpty)  &&  (twentysevenEmpty) &&  (twentyEightEmpty) &&  (twentynineEmpty))
					{
					    blStations = false;

					    firstEmpty=false; secondEmpty=false; thirdEmpty=false;   fourthEmpty=false;   fifthEmpty=false; sixthEmpty=false; seventhEmpty=false;   eighthEmpty=false;	
					    ninthEmpty=false; tenthEmpty=false; eleventhEmpty=false; twelvthEmpty=false; therteenthEmpty=false;fourteenthEmpty=false; fifteenthEmpty=false; 
					    sixteenthEmpty=false; seventeenthEmpty=false; eighteenthEmpty=false; nineteenthEmpty=false; twentyteenthEmpty=false;twentyoneEmpty=false; twentytwoEmpty=false;
					    twentythreeEmpty=false; twentyfourEmpty=false; twentyfiveEmpty=false; twentysixEmpty=false; twentysevenEmpty=false; twentyEightEmpty=false; twentynineEmpty=false;
					    block =0;
					    record = 0;					    
				        }
					
					
					if( (findFirst) && (findSecond) && (findThird)  && (findFourth) && (findFifth) && (findSixth) && (findSeventh) && (findEighth) && (findNinth)&&(findTenth) &&(findEleventh) &&
					(findTwelvth)   &&  (findTherteenth) && (findFourteenth) &&(findFifteenth)  &&(findSixteenth)  &&(findSeventeenth)  &&(findEighteenth)  &&(findNingteenth)  &&(findtwenteenth)
					&&(findtwentyone)  &&(findtwentytwo)  &&(findtwentythree) &&(findtwentyfour)  &&(findtwentyfive) &&(findtwentysix) &&(findtwentyseven) &&(findtwentyEight) &&(findtwentynine))
					{
					    firstEmpty=false; secondEmpty=false; thirdEmpty=false;   fourthEmpty=false;   fifthEmpty=false; sixthEmpty=false; seventhEmpty=false;   eighthEmpty=false;	
					    ninthEmpty=false; tenthEmpty=false; eleventhEmpty=false; twelvthEmpty=false; therteenthEmpty=false;fourteenthEmpty=false; fifteenthEmpty=false; 
					    sixteenthEmpty=false; seventeenthEmpty=false; eighteenthEmpty=false; nineteenthEmpty=false; twentyteenthEmpty=false;twentyoneEmpty=false; twentytwoEmpty=false;
					    twentythreeEmpty=false; twentyfourEmpty=false; twentyfiveEmpty=false; twentysixEmpty=false; twentysevenEmpty=false; twentyEightEmpty=false; twentynineEmpty=false;

					} 
					else if( (findEighth)  && (!findTwelvth) )
					{
						faults[0][0]++;
						faults[faultrow][0]=1;
	   					faults[faultrow][1]=numStations+2;
					        faults[faultrow][2]=STN_TYP_UNKNOWN;
					        faultrow++;	
					}
					else if( (!findEighth) &&  ((findFirst)  ||  ((findSecond) || (findThird)  || (findFourth) || (findFifth) || (findSixth) || (findSeventh) || (findEighth) || (findNinth) || (findTenth) || (findEleventh) ||
					(findTwelvth) ||(findTherteenth) ||(findFourteenth) ||(findFifteenth)  ||(findSixteenth)  ||(findSeventeenth)  ||(findEighteenth)  ||(findNingteenth)  ||(findtwenteenth)
					||(findtwentyone)  ||(findtwentytwo)  ||(findtwentythree) ||(findtwentyfour)  ||(findtwentyfive) ||(findtwentysix) ||(findtwentyseven) ||(findtwentyEight) ||(findtwentynine))))
					{					    
					    
					    faults[0][0]++;
			      		    faults[faultrow][0]=1;
		   			    faults[faultrow][1]=numStations+3;
					    faults[faultrow][2]=CALL_NO_MISSING;
					    faultrow++;
					}
					
					if( ((findEighth)    &&   (!findFirst))   )
					{
						faults[0][0]++;
						faults[faultrow][0]=1;
	   				        faults[faultrow][1]=numStations+3;
					        faults[faultrow][2]=INVALID_NODEID;
					        faultrow++;
					}

					
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) && (!findFifth) && (!findSixth)  && (!findSeventh) && (!findEighth) && (!findNinth)&&(!findTenth) &&(!findEleventh) &&
					(!findTwelvth)   &&  (!findTherteenth) )
					{
					    //blStations = false;
					    numStations = numStations;
					}
					else
					  numStations++;
					
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;findTherteenth=false;				
					findFourteenth=false; findFifteenth=false; findSixteenth=false; findSeventeenth=false; findEighteenth=false; findNingteenth=false; findtwenteenth=false;
					findtwentyone=false; findtwentytwo=false; findtwentythree=false; findtwentyfour=false; findtwentyfive=false; findtwentysix=false; findtwentyseven=false; findtwentyEight=false; findtwentynine=false;

					
					firstEmpty=false; secondEmpty=false; thirdEmpty=false;   fourthEmpty=false;   fifthEmpty=false; sixthEmpty=false; seventhEmpty=false;   eighthEmpty=false;	
					ninthEmpty=false; tenthEmpty=false; eleventhEmpty=false; twelvthEmpty=false; therteenthEmpty=false;fourteenthEmpty=false; fifteenthEmpty=false; 
					sixteenthEmpty=false; seventeenthEmpty=false; eighteenthEmpty=false; nineteenthEmpty=false; twentyteenthEmpty=false;twentyoneEmpty=false; twentytwoEmpty=false;
					twentythreeEmpty=false; twentyfourEmpty=false; twentyfiveEmpty=false; twentysixEmpty=false; twentysevenEmpty=false; twentyEightEmpty=false; twentynineEmpty=false;

					strtmpNumDid=""; 
					strtmpFaxDid = "";
				}
				
								


			} // END if(blStations)
//---------------------------------------------- END STATIONS--------------------------------------------------------------------------------------------------------------			
		//-----------------------------------------------GROUPS START-----------------------------------------------------------------------------------------------------------			
			else if( (blGroups) )
			{				
				//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlGroupsNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[0].headerrecord)!= 0 ) )
				{
					//numGroups++;
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if GRoup Internal Number Is Emprty 
					{										   
					     firstEmpty = true;	
					     //numGroups--;			    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true; 
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {					       
					       faults[0][0]++;
				      	       faults[faultrow][0]=3;
		   			       faults[faultrow][1]=numGroups+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					       faults[0][0]++;
				      	       faults[faultrow][0]=3;
		   			       faults[faultrow][1]=numGroups+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
					    }
					    else
					    {
					    
					    
					    
					    }					    					    		

					    delete [] tmpNumbers;
					}     	
					numberoflines++;
					
					
				}
				//------------------------------DID NUMBER -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlGroupsNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[1].headerrecord)!= 0 ) )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  ) // Check if GRoup Internal Number Is Emprty 
					{										   
					     secondEmpty = true;
				    
					}
					else // Check If Valid Call Number 
					{
					    findSecond=true; 
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
				               faults[0][0]++;
				      	       faults[faultrow][0]=3;
		   			       faults[faultrow][1]=numGroups+3;
					       faults[faultrow][2]=INVALID_DUWA;
					       faultrow++;
					    }
					    else if (strData.length() > ((DID_SIZE*2) -1) )
		   			    {
				               faults[0][0]++;
				      	       faults[faultrow][0]=3;
		   			       faults[faultrow][1]=numGroups+3;
					       faults[faultrow][2]=INVALID_DUWA;
					       faultrow++;
					    }
					    else
					    {
							 
					    }
					    
					    
					    delete [] tmpNumbers;
					}    
					 	
				}
				//------------------------------DISPLAY NAME -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlGroupsNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[2].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}
					else 
					{	klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=INVALID_NAME;
						       faultrow++;
						}
						else if ( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=INVALID_NAME;
						       faultrow++;	
						}
						findThird=true; 
					}
					
				}
				//------------------------------Voicemail -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlGroupsNameTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[3].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}
					else 
					{							
						if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0)  )	
						{
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=WRONG_VOICEMAIL_FORMAT;
						       faultrow++;
						}
						findThird=true; 
					}
					
				}
				//------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlGroupsNameTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[4].headerrecord)!= 0)  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     fourthEmpty = true;
					}					
					else 
					{
						if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{	       
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;						       
	
						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;						       
						}
						else if ( strData.length() > 4) 
						{
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;						       
						}
					
						findFourth=true; 
					}
					
					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) )
					{
					   // blGroups = false;
					   numGroups=numGroups;
					}
					else
					   numGroups++;


					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) && (fourthEmpty) )
					{
					    blGroups = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
					    fourthEmpty=false;
				        }
				       
					if( (findFirst) && (findSecond) && (findThird)  && (findFourth)  )
					{
						findFirst=false; findSecond=false; findThird=false; findFourth=false; 
					} 
					else if( (!findFirst) &&  ((findSecond) || (findThird)  || (findFourth) ) )
					{	
						faults[0][0]++;
				      	    	faults[faultrow][0]=3;
		   			    	faults[faultrow][1]=numGroups+3;
					    	faults[faultrow][2]=CALL_NO_MISSING;
					    	faultrow++;					
					}
					
					   
					firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;

					
				}
				
								
			}// END blGroups
			
//-----------------------------------------------GROUPS END-----------------------------------------------------------------------------------------------------------						
			//-----------------------------------------------VIRTUAL START-----------------------------------------------------------------------------------------------------------									
			
			else if( (blVirtual)  )
			{

	  			//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlVirtualNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[0].headerrecord)!= 0 ) )
				{
					//numVirtual++;
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     firstEmpty = true;	
					     //numVirtual--;			    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true;   
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
				           	faults[0][0]++;
				      	    	faults[faultrow][0]=4;
		   			    	faults[faultrow][1]=numVirtual+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;						       					    
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					        faults[0][0]++;
				      	    	faults[faultrow][0]=4;
		   			    	faults[faultrow][1]=numVirtual+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;	
					    
					    }
					    else
					    {
						     
					    }
					    					    
					    delete [] tmpNumbers;
					}
					   	
					numberoflines++;
				}
				//------------------------------DID NUMBER -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVirtualNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[1].headerrecord)!= 0 ) )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  ) // Check if GRoup Internal Number Is Emprty 
					{										   
					     secondEmpty = true;
				    
					}
					else // Check If Valid Call Number 
					{
					    findSecond=true;  
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
					        faults[0][0]++;
 			      	    		faults[faultrow][0]=4;
		   			    	faults[faultrow][1]=numVirtual+3;
					    	faults[faultrow][2]=INVALID_DUWA;
					    	faultrow++;
	
					    }
					    else if (strData.length() > ((DID_SIZE*2) -1) )
					    {
					        faults[0][0]++;
 			      	    		faults[faultrow][0]=4;
		   			    	faults[faultrow][1]=numVirtual+3;
					    	faults[faultrow][2]=INVALID_DUWA;
					    	faultrow++;
					    }
					    else
					    {
					    }					    					    
					    
					    delete [] tmpNumbers;
					}    
						
				}
				//------------------------------DISPLAY NAME -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVirtualNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[2].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}
					else 
					{

						klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						   faults[0][0]++;
	 			      	    	   faults[faultrow][0]=4;
			   			   faults[faultrow][1]=numVirtual+3;
						   faults[faultrow][2]=INVALID_NAME;
						   faultrow++;	
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
	 			      	    	   	faults[faultrow][0]=4;
			   			   	faults[faultrow][1]=numVirtual+3;
						   	faults[faultrow][2]=INVALID_NAME;
						   	faultrow++;		
						}
						findThird=true;
					}
				}
				//----------------------------STATION TYPE ------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVirtualNameTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(),xmlVirtualNameTable[3].headerrecord)!=0) )
				{
					if ( strcmp(strData.c_str(),"empty") == 0 )
					{	
					     fourthEmpty = true;
					}					
					else
					{ 
						if(blX1)
						{
							if(strcmp ( strData.c_str(),  xmlVirtualStationTypes[5].name ) != 0  )
							{
								faults[0][0]++;
								faults[faultrow][0]=4;
		   						faults[faultrow][1]=numVirtual+3;
						        	faults[faultrow][2]=STN_TYP_UNKNOWN;
						        	faultrow++;
							}
							
							findFourth=true;
						
						}
						else
						{
						if( !CheckStationTypeVirtual(strData.c_str()) ) // ||  (strcmp(strData.c_str(),"empty") == 0) )
						{					    					    
						    faults[0][0]++;
	  			      	    	    faults[faultrow][0]=4;
			   			    faults[faultrow][1]=numVirtual+3;
						    faults[faultrow][2]=STN_TYP_UNKNOWN;
						    faultrow++;
						}
						findFourth=true;
						}
					}
				}
				//------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVirtualNameTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[4].headerrecord)!= 0)  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     fifthEmpty = true;
					}					
					else 
					{
						if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{
						    faults[0][0]++;
  				      	    	    faults[faultrow][0]=4;
			   			    faults[faultrow][1]=numVirtual+3;
						    faults[faultrow][2]=INVALID_NODEID;
						   faultrow++;

						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						    faults[0][0]++;
	  			      	    	    faults[faultrow][0]=4;
		   				    faults[faultrow][1]=numVirtual+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;
						}
						else if(strData.length() > 4)
						{
						    faults[0][0]++;
  			      		    	    faults[faultrow][0]=4;
		   				    faults[faultrow][1]=numVirtual+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;
						}
															
						findFifth=true; 
					}
					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) && (!findFifth)  )
					{
					   // blVirtual = false;
					   numVirtual = numVirtual;
					}
					else
					   numVirtual++;
						
					
					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) && (fourthEmpty) && (fifthEmpty))
					{
					    blVirtual = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
					    fourthEmpty=false;
					    fifthEmpty=false;
				        }
				       /*
				        else if(  (firstEmpty)  && ( (!secondEmpty) || (!thirdEmpty) || (!fourthEmpty)  || (!fifthEmpty)  )  )
				        {
					    faults[0][0]++;
  			      	    	    faults[faultrow][0]=4;
		   			    faults[faultrow][1]=numVirtual+2;
					    faults[faultrow][2]=CALL_NO_MISSING;
					    faultrow++;
					    
					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
					    fourthEmpty=false;
					    fifthEmpty = false;
 				        }
					*/
					if( (findFirst) && (findSecond) && (findThird)  && (findFourth) && (findFifth)  )
					{
						findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; 
					}
					else if(  (findFirst) &&  (!findFourth) )
					{
						 faults[0][0]++;
	  			      	    	 faults[faultrow][0]=4;
			   			 faults[faultrow][1]=numVirtual+3;
						 faults[faultrow][2]=STN_TYP_UNKNOWN;
						 faultrow++;						
					} 
					else if( (!findFirst) &&  ((findSecond) || (findThird)  || (findFourth) || (findFifth)  ) )
					{		
						faults[0][0]++;
  			      	    	   	faults[faultrow][0]=4;
		   			    	faults[faultrow][1]=numVirtual+3;
					   	faults[faultrow][2]=CALL_NO_MISSING;
					   	faultrow++;	
					}
					
					firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
					//numVirtual++;
				}
			

				


			}// END If VIRTUAL
//-----------------------------------------------VIRTUAL END-----------------------------------------------------------------------------------------------------------									
			
//-----------------------------------------------TRUNK GROUPS---------------------------------------------------------------------------------------------------------			
			else if( (blTrunkGroup) )
			{

				//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlTrunkGrpNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlTrunkGrpNameTable[0].headerrecord)!= 0 ) )
				{
					//numTrunkGroups++;
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     firstEmpty = true;	
					    // numTrunkGroups--;			    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true; 
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
						faults[0][0]++;
  			      	    	    	faults[faultrow][0]=5;
		   			    	faults[faultrow][1]=numTrunkGroups+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
						faults[0][0]++;
  			      	    	    	faults[faultrow][0]=5;
		   			    	faults[faultrow][1]=numTrunkGroups+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;
					    }
					    else
					    {

						     
					    					    
					    }
					    
					    delete [] tmpNumbers;
					}     	
					numberoflines++;
					
				}
				//------------------------------DISPLAY NAME -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlTrunkGrpNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlTrunkGrpNameTable[1].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     secondEmpty = true;
					}
					else 
					{
						
						klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						    faults[0][0]++;
  			      	    		    faults[faultrow][0]=5;
		   				    faults[faultrow][1]=numTrunkGroups+3;
						    faults[faultrow][2]=INVALID_NAME;
						    faultrow++;
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
						    faults[0][0]++;
  			      	    		    faults[faultrow][0]=5;
		   				    faults[faultrow][1]=numTrunkGroups+3;
						    faults[faultrow][2]=INVALID_NAME;
						    faultrow++;	
						}
						findSecond=true;
					}
				}
				//------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlTrunkGrpNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlTrunkGrpNameTable[2].headerrecord)!= 0)  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}					
					else 
					{
						if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{					       
						    faults[0][0]++;
  				      	    	    faults[faultrow][0]=5;
			   			    faults[faultrow][1]=numTrunkGroups+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;					       					       
						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						    faults[0][0]++;
  				      	    	    faults[faultrow][0]=5;
			   			    faults[faultrow][1]=numTrunkGroups+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;					       					       
						}
						else if (strData.length() > 4)
						{
						    faults[0][0]++;
  				      	    	    faults[faultrow][0]=5;
			   			    faults[faultrow][1]=numTrunkGroups+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;					       					       
						}
						findThird=true; 
					}
						
					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) && (!findFifth) && (!findSixth)  && (!findSeventh) && (!findEighth) && (!findNinth) && (!findTenth) && (!findEleventh) && (!findTwelvth)  )
					{
					    numTrunkGroups=numTrunkGroups;
					}
					else
						numTrunkGroups++;
					
					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) )
					{
					    blTrunkGroup = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
				        }
				        /*else if(  (firstEmpty)  && ( (!secondEmpty) || (!thirdEmpty)  )  )
				        {
					    faults[0][0]++;
  			      	    	    faults[faultrow][0]=5;
		   			    faults[faultrow][1]=numTrunkGroups+2;
					    faults[faultrow][2]=CALL_NO_MISSING;
					    faultrow++;					       					       
					    					    
					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
 				        }	
					*/
					if( (findFirst) && (findSecond) && (findThird)  )
					{
						findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
					} 
					else if( (!findFirst) &&  ((findSecond) || (findThird)  ) )
					{	
						faults[0][0]++;
  			      	    	    	faults[faultrow][0]=5;
		   			    	faults[faultrow][1]=numTrunkGroups+3;
					    	faults[faultrow][2]=CALL_NO_MISSING;
					    	faultrow++;					       					       					    				
					}
					
					
					firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
					
				}				
				

			}
			else if( (blVoicemail)  )
			{

				//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlVoiceMailNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVoiceMailNameTable[0].headerrecord)!= 0 ) )
				{
					//numVoicemail++;
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     firstEmpty = true;	
					     //numVoicemail--;			    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true; 
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {					       
					       faults[0][0]++;
	  			      	       faults[faultrow][0]=6;
			   		       faults[faultrow][1]=numVoicemail+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					       faults[0][0]++;
	  			      	       faults[faultrow][0]=6;
			   		       faults[faultrow][1]=numVoicemail+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
				            }
					    else
					    {
						
					    }
					    delete [] tmpNumbers;
					}     	
					numberoflines++;
					
				}
				//------------------------------DISPLAY NAME -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVoiceMailNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVoiceMailNameTable[1].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     secondEmpty = true;
					}
					else
					{
						klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE)  )
						{
					       		faults[0][0]++;
	  			      	       		faults[faultrow][0]=6;
				   		       	faults[faultrow][1]=numVoicemail+3;
						       	faults[faultrow][2]=INVALID_NAME;
						       faultrow++;
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
	  			      	       		faults[faultrow][0]=6;
				   		       	faults[faultrow][1]=numVoicemail+3;
						       	faults[faultrow][2]=INVALID_NAME;
						       faultrow++;	
						}
						findSecond=true; 
					}
				}
				//------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVoiceMailNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVoiceMailNameTable[2].headerrecord)!= 0)  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}					
					else
					{
						 if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{					       
					       		faults[0][0]++;
		  			      	       	faults[faultrow][0]=6;
				   		       faults[faultrow][1]=numVoicemail+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;
						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						       faults[0][0]++;
		  			      	       faults[faultrow][0]=6;
				   		       faults[faultrow][1]=numVoicemail+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;
						}
						else if(strData.length() > 4)
						{
						       faults[0][0]++;
		  			      	       faults[faultrow][0]=6;
				   		       faults[faultrow][1]=numVoicemail+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;
						}
						
						findThird=true; 
					}					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					
					if( (!findFirst) && (!findSecond) && (!findThird) )
					{
						numVoicemail = numVoicemail;
						
					} 
					else
						numVoicemail++;
						
					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) )
					{
					    blVoicemail = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
				        }										
					
					else if( (!findFirst) &&  ((findSecond) || (findThird) ) )
					{		
						faults[0][0]++;
	  			      	  	faults[faultrow][0]=6;
			   		    	faults[faultrow][1]=numVoicemail+3;
					    	faults[faultrow][2]=CALL_NO_MISSING;
					    	faultrow++;		
					}
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;	
					firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;
					//numVoicemail++;
				}
				
			} // end if voicemail
			
//-----------------------------------------------SipConfig-----------------------------------------------------------------------------------------------------------									
			
			else if( (blSipConfig)  )
			{

	  			//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlSipConfigTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[0].headerrecord)!= 0 ) )
				{
					
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     firstEmpty = true;	
					     		    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true;   
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
				           	faults[0][0]++;
				      	    	faults[faultrow][0]=7;
		   			    	faults[faultrow][1]=numSipConfig+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;						       					    
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					        faults[0][0]++;
				      	    	faults[faultrow][0]=7;
		   			    	faults[faultrow][1]=numSipConfig+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;	
					    
					    }
					    else
					    {
					    }
					    					    
					    delete [] tmpNumbers;
					}
					   	
					numberoflines++;
				}
				//------------------------------Password Sip -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlSipConfigTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[1].headerrecord)!= 0 ) )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  ) // Check if GRoup Internal Number Is Emprty 
					{										   
					     secondEmpty = true;
				    
					}
					else // Check If Valid Call Number 
					{
					    findSecond=true;  
					    klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						   faults[0][0]++;
	 			      	    	   faults[faultrow][0]=7;
			   			   faults[faultrow][1]=numSipConfig+3;
						   faults[faultrow][2]=INVALID_PASSWORD;
						   faultrow++;	
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
	 			      	    	   	faults[faultrow][0]=7;
			   			   	faults[faultrow][1]=numSipConfig+3;
						   	faults[faultrow][2]=INVALID_PASSWORD;
						   	faultrow++;		
						}
					    // Here will check the type of password					    
					}    
						
				}
				//------------------------------UserId/Username  -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlSipConfigTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[2].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}
					else 
					{

						klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						   faults[0][0]++;
	 			      	    	   faults[faultrow][0]=7;
			   			   faults[faultrow][1]=numSipConfig+3;
						   faults[faultrow][2]=INVALID_USERID_USERNAME;
						   faultrow++;	
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
	 			      	    	   	faults[faultrow][0]=7;
			   			   	faults[faultrow][1]=numSipConfig+3;
						   	faults[faultrow][2]=INVALID_USERID_USERNAME;
						   	faultrow++;		
						}
						findThird=true;
					}
				}
				//----------------------------Realm ------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlSipConfigTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(),xmlSipConfigTable[3].headerrecord)!=0) )
				{
					if ( strcmp(strData.c_str(),"empty") == 0 )
					{	
					     fourthEmpty = true;
					}					
					else
					{ 						
						klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						   faults[0][0]++;
	 			      	    	   faults[faultrow][0]=7;
			   			   faults[faultrow][1]=numSipConfig+3;
						   faults[faultrow][2]=INVALID_REALM;
						   faultrow++;	
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
	 			      	    	   	faults[faultrow][0]=7;
			   			   	faults[faultrow][1]=numSipConfig+3;
						   	faults[faultrow][2]=INVALID_REALM;
						   	faultrow++;		
						}   
					  findFourth=true;						
					}
				}
				//------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlSipConfigTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[4].headerrecord)!= 0)  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     fifthEmpty = true;
					}					
					else 
					{
						if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{
						    faults[0][0]++;
  				      	    	    faults[faultrow][0]=7;
			   			    faults[faultrow][1]=numSipConfig+3;
						    faults[faultrow][2]=INVALID_NODEID;
						   faultrow++;

						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						    faults[0][0]++;
	  			      	    	    faults[faultrow][0]=7;
		   				    faults[faultrow][1]=numSipConfig+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;
						}
						else if(strData.length() > 4)
						{
						    faults[0][0]++;
  			      		    	    faults[faultrow][0]=7;
		   				    faults[faultrow][1]=numSipConfig+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;
						}
															
						findFifth=true; 
					}
					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) && (!findFifth)  )
					{
					   // blVirtual = false;
					   numSipConfig = numSipConfig;
					}
					else
					   numSipConfig++;
						
					
					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) && (fourthEmpty) && (fifthEmpty))
					{
					    blSipConfig = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
					    fourthEmpty=false;
					    fifthEmpty=false;
				        }
				       
				}
			

				


			}// END If SipConfig
//-----------------------------------------------SipConfig-----------------------------------------------------------------------------------------------------------									
			
		}  // END // If the Record is OK
		

	countLine++;//increase countLines number to numberring Lines   
	
    }// ----end while read lines-------
    
    type[0] = numStations; // Licenses Number   
    type[1] = 0; // Licenses Number
    type[2] = numGroups;   // Group Number
    type[3] = numVirtual;   //  Virtual Number
    type[4] = numTrunkGroups; // Trunk number
    type[5] = numVoicemail;   // Voicemail Number 
    type[6] = numSipConfig;   // Voicemail Number 
    
    if(corXml==0)
    {
	    faults[0][0]++;
	    faults[faultrow][0]=1;
	    faults[faultrow][1]= 0; // invalid Xml with no contents 
	    faults[faultrow][2]=INVALID_FILE_FORMAT;
	    faultrow++;	
    }
    
    errorCount = faultrow; 

    fclose(fxml);

    if(faults[0][0]==0)
    return  0; 
    else 
    return errorCount;  

    
  //
}	
int  checkXmlFormatErrorsUsa1(char* fname, int type[5], int errorCount,int faults[21][3])
{
   char line [128]; 
    char *tmpNumbers;
    FILE *fxml = fopen(fname,"r");
    int fLast,fFirst,intLen,wksFound,findNameCell=0,findCell=0,countLine=0,rowCount=0,result=-1,wksRowFound,corXml=0,klen=0,fFiltDb=0,uc_count=0,icurrentrow=0;
    string tempstr,totalstr,strData,strCell,strtmpNumDid="",strtmpFaxDid="";  
  //  bool blStations=false,blCellEnd=false,blEndRecord=false,blX1=false;    
    int i=0,pos=0,numStations=0,numLicenses=0,numGroups=0,numVoicemail=0,numVirtual=0,numTrunkGroups=0,numberoflines=1,faultrow=1,record=0,block=0,numSipConfig=0;
    bool blStations=false,blLicenses=false,blGroups=false,blVirtual=false,blTrunkGroup=false,blVoicemail=false,blCellEnd=false,blEndRecord=false,blX1=false,blSipConfig=false;
    bool firstEmpty=false,secondEmpty=false,thirdEmpty=false,fourthEmpty=false,fifthEmpty=false,sixthEmpty=false,seventhEmpty=false,eighthEmpty=false,ninthEmpty=false,tenthEmpty=false,eleventhEmpty=false
    ,twelvthEmpty=false,therteenthEmpty=false,fourteenthEmpty=false,fifteenthEmpty=false,sixteenthEmpty=false,seventeenthEmpty=false,eighteenthEmpty=false,nineteenthEmpty=false,twentyteenthEmpty=false;
    bool findFirst=false,findSecond=false,findThird=false,findFourth=false,findFifth=false,findSixth=false,findSeventh=false,findEighth=false,findNinth=false,findTenth=false,findEleventh=false,findTwelvth=false,findTherteenth=false;
    bool findFourteenth=false,findFifteenth=false,findSixteenth=false,findSeventeenth=false,findEighteenth=false,findNingteenth=false,findtwenteenth=false;
    bool twentyoneEmpty=false,twentytwoEmpty=false,twentythreeEmpty=false,twentyfourEmpty=false,twentyfiveEmpty=false,twentysixEmpty=false,twentysevenEmpty=false,twentyEightEmpty=false,twentynineEmpty=false;
    bool findtwentyone=false,findtwentytwo=false,findtwentythree=false,findtwentyfour=false,findtwentyfive=false,findtwentysix=false,findtwentyseven=false,findtwentyEight=false,findtwentynine=false;
//    unsigned char chEmpty;
    RD_KDS_RETURN			kdsreturn,kdsreturnacode;
    RD_KDS_RETURN           kdsreturnX1;
    char * sacode;
    int  inhalt[256];
	 string strtmp_1="";
    
    
    
    
    
//    if(kdsreturnX1.inhalt[0]==DS_BPL_ONE_X1)  //DS_BPL_ONE
//  	blX1=true; // means system is X1
	
    errorCount = 0;
        
    for(i=0;i<21;i++)
    {
	for(pos=0;pos<3;pos++)
		faults[i][pos]=0;
    }
    
    
// -- Prepei na mpoun edo kai Safe Conditions an Skasei        
    while ( fgets ( line,128,fxml ) != NULL ) // read a line by line
    {
	
	if (faultrow > 20)
		break;
	
	tempstr=line; // this temp str contains the current line
	intLen = strlen(line);
	
	//---1-find----WorkSheet name ------------------------------
	wksFound= tempstr.find("Worksheet ss:Name");

	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
	        fFirst= tempstr.find("\"");
	        fLast=tempstr.find_last_of("\"");   
	        tempstr = tempstr.substr(fFirst+1,(fLast-(fFirst+1)));		

		if(tempstr == "Customer")
		{
	   	   blStations = true;
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name   
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;

		   countLine=0;
		   corXml++;
		}
		else if(tempstr =="Groups")		
		{
		   blGroups = true;		    
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 		
		   countLine=0;		
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;
		   corXml++;		   
		}
		else if(tempstr =="Virtual")		
		{
		   blVirtual = true;
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 		
		   countLine=0;		
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;
		   corXml++;		   
		   
		}
		else if(tempstr =="Trunk Groups")
		{
		   blTrunkGroup = true;		
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 		   
		   countLine=0;		
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;
		   corXml++;		   

		}
		else if(tempstr =="Voicemail")	
		{
		   blVoicemail = true;		   
		   block=0;          // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 
		   record=0;         // Initialize the variables when worksheet changes in order to Check the Header Format and Cell Name 		   
		   countLine=0;		
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;
		   corXml++;
		}
		else if(tempstr =="SipConfig")	
		{
		   blSipConfig = true;		   
		   block=0;          
		   record=0;        
		   countLine=0;		
		   firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
		   findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false;
		   findTwelvth=false; findTherteenth=false;
		   corXml++;
		}

    }// end worksheet search 

	//---2 find the End of WorkSheet-------------
	wksFound= tempstr.find("</Worksheet>");
	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
		if(blStations)
		{
			blStations = false;
		}		
		else if(blGroups)
		{
			blGroups = false;
		}
		else if(blVirtual)
		{
			blVirtual = false;
		}
		else if(blTrunkGroup)
		{
			blTrunkGroup = false;
		}
		else if(blVoicemail)
		{
			blVoicemail = false;
				
		}
		else if(blSipConfig)
		{
			blSipConfig = false;
			break;	
		}
	}


	blEndRecord = false;
	//if(blStations)
	//{
	
		wksFound = tempstr.find("</Data>");
		findNameCell = tempstr.find("<NamedCell");
		findCell = tempstr.find("</Cell>");
		wksRowFound = tempstr.find("</Row>");
		fFiltDb = tempstr.find("FilterDatabase");
		//  CASE  A -- Check if the line is empty, has no data, only namedcell
		if((findNameCell > -1) && (wksFound == -1)  && (fFiltDb==-1) ) 
		{
			fLast = tempstr.find("</Cell>");
			fLast = fLast -3;
			fFirst = tempstr.rfind("=\"");
			fFirst  = fFirst+2;
			strCell = tempstr.substr(fFirst,(fLast-fFirst));
			strData = "empty";
			blEndRecord = true;
		}
		// CASE B scenario we had Data and NameCell Filled in the Same Line 		
		else if( (wksFound > -1) && (findNameCell > -1)  && (findCell >-1) )
		{			
			//cell name
			fLast = tempstr.find("</Cell>");
			fLast = fLast -3;
			fFirst = tempstr.rfind("=\"");
			fFirst  = fFirst+2;
			strCell = tempstr.substr(fFirst,(fLast-fFirst));
			//data 
			fLast = wksFound;  //tempstr.find("</Data>");
			fFirst = tempstr.rfind("\">");
			strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));
			blEndRecord = true;	
		}
		// CASE C -- Has Data and NameCell but the Cell END is in the next Line
		else if( (wksFound > -1) && (findNameCell > -1)  && (findCell == -1) )
		{
			//data
			fLast = wksFound;  //tempstr.find("</Data>");
			fFirst = tempstr.rfind("\">");
			
			strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));

			if(strData.length() == 0 )
				strData = "empty";
			blCellEnd = true; // wait the end of the Cell	
		}
		else if( (findCell > -1) &&  (blCellEnd)  ) // find the end of Cell
		{
			blCellEnd = false;
			//cell name
			fLast = tempstr.find("</Cell>");
			fLast = fLast -3;
			fFirst = tempstr.rfind("=\"");
			fFirst  = fFirst+2;
			strCell = tempstr.substr(fFirst,(fLast-fFirst));
			blEndRecord = true;
		}
		else if(wksRowFound > -1)	
		{
			blEndRecord = true;
			strData = "</Row>";
			strCell="";
		}
		
		if(blEndRecord)
		  icurrentrow++;
		
		//  When Find a Record the blEndRecord is TRUE 
		if((blEndRecord)  &&  (faultrow <21)   && (icurrentrow > 35))
		{
			
//----------------Start ----  Validation -- Check If the Header of Each  Sheet Is Correct ----------------------------------------------			
			if(blStations) 
			{				
				
				if(record >30)
				{
				  block++;
				  record = 0;
				  firstEmpty=false; secondEmpty=false; thirdEmpty=false;   fourthEmpty=false;   fifthEmpty=false; sixthEmpty=false; seventhEmpty=false;   eighthEmpty=false;	
					ninthEmpty=false; tenthEmpty=false; eleventhEmpty=false; twelvthEmpty=false; therteenthEmpty=false;fourteenthEmpty=false; fifteenthEmpty=false; 
					sixteenthEmpty=false; seventeenthEmpty=false; eighteenthEmpty=false; nineteenthEmpty=false; twentyteenthEmpty=false;twentyoneEmpty=false; twentytwoEmpty=false;
					twentythreeEmpty=false; twentyfourEmpty=false; twentyfiveEmpty=false; twentysixEmpty=false; twentysevenEmpty=false; twentyEightEmpty=false; twentynineEmpty=false;
				}
				
			}
			if(blGroups) 
			  {
				if(record >4)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
				}					
			   }
			  
			  if(blVirtual) 
			  {
				if(record >4)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
				}
							
			   }
			   
			  if(blTrunkGroup) 
			  {
				if(record >2)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
				}								
			   }
			   
			  if(blVoicemail) 
			  {
				if(record >2)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
				}				
			   }
			   if(blSipConfig)
			   {
				if(record >4)
				{
				  block++;
				  record = 0;
				  firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false,therteenthEmpty=false;
				}				
			   }
			   
			  					
//----------------END ----  Validation -- Check If the Header of Each  Sheet Is Correct ----------------------------------------------						
			
//----------------------------------------------Customer --------------------------------------------------------------------------------------------------------------
			if( (blStations) )// &&  (block > 0) )
			{
				
				//---------------------------ID---nodeid------------------------------------------------------

				if( ( strcmp(strCell.c_str(),xmlUsaElements[0].element ) == 0 )  )				  
				{														
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					    firstEmpty = true; 
					}
					else
					{
					    findFirst = true;
					    /* node ID  must be a number other case return error code */
					    if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
					    {
						  faults[0][0]++;
						  faults[faultrow][0]=1;
						  faults[faultrow][1]=numStations+3;
						  faults[faultrow][2]=INVALID_NODEID;
						  faultrow++;
					    }
					    /*  node ID must be betwwen 0....999, it's refered to nodeID number */
					    else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
					    {
						  faults[0][0]++;
						  faults[faultrow][0]=1;
						  faults[faultrow][1]=numStations+3;
						  faults[faultrow][2]=INVALID_NODEID;
						  faultrow++;
					    }
					    /*  node Id cannot be greater than 999, if we have more than 3 digits return error code.*/
					    else if( strData.length() > 4 )
					    {
						  faults[0][0]++;
			      			  faults[faultrow][0]=1;
		   				  faults[faultrow][1]=numStations+3;
						  faults[faultrow][2]=INVALID_NODEID;
						  faultrow++;
					    }
					    
					}
					  
				}
				//-----------------------END----NODE ID ------------------------------------------------------
				//-------------------------SITENAME-----------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[1].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					    secondEmpty = true; 
					}
					else
					{
					    findSecond = true;
					    //----------------site name  max length 50characters------------------
					    klen=0;
					    klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
				            /*-----search for invalid characters ------------------------*/		      
					    if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_NAME_CHARACTERS;
						faultrow++;	
					    }
					    /*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					    else if( (strData.length() > (50))     &&   (klen>50 ) )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_NAME;
						faultrow++;	
					    }
					}
					
				}
				//------------------------END SITE NAME---------------------------------
				
				//------------------------UC TYPE---------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[2].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					    thirdEmpty = true; 
					}
					else
					{
					    findThird = true;
					    //----------------site name  max length 50characters------------------
					    klen=0;
					    klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
				            /*-----search for invalid characters ------------------------*/		      
					    if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=1;
						faultrow++;	
					    }
					    /*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					    else if( (strData.length() > (50))     &&   (klen>MAXLENSTRS_CUSTOMER ) )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=1;
						faultrow++;	
					    }
					    else if(  (strcmp(strData.c_str(),"UC Suite")!=0) && (strcmp(strData.c_str(),"UC Smart")!=0))	
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=1;
						faultrow++;	
					    
					    }
					    
					}
					
				}				
				//------------------------END UC TYPE ----------------------------------
				
				//------------------------Call PickUp Groups---------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[3].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					    fourthEmpty = true; 
					}
					else
					{
					    findFourth = true;
					    //----------------site name  max length 50characters------------------
					    klen=0;
					    klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
				            /*-----search for invalid characters ------------------------*/		      
					    if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_NAME_CHARACTERS;
						faultrow++;	
					    }
					    /*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					    else if( (strData.length() > (50))     &&   (klen>50 ) )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_NAME;
						faultrow++;	
					    }
					}
					
				}				
				//------------------------END Call PickUp Groups ----------------------------------
				//MAXLENSTR_NAME
				
				//--------------------LAST NAME-------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[4].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					    fifthEmpty = true; 
					}
					else
					{
					    findFifth = true;
					    //----------------site name  max length 32 characters------------------
					    klen=0;
					    klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
				            /*-----search for invalid characters ------------------------*/		      
					    if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_NAME_CHARACTERS;
						faultrow++;	
					    }
					    /*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					    else if( (strData.length() > (50))     &&   (klen>50 ) )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_NAME;
						faultrow++;	
					    }
					}
					
				}
				//--------------------END LAST NAME---------------------------------------------------
				
				//--------------------FIRST NAME-------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[5].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					    sixthEmpty = true; 
					}
					else
					{
					    findSixth = true;
					    //----------------site name  max length 32 characters------------------
					    klen=0;
					    klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
				            /*-----search for invalid characters ------------------------*/		      
					    if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_NAME_CHARACTERS;
						faultrow++;	
					    }
					    /*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					    else if( (strData.length() > (50))     &&   (klen>50 ) )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_NAME;
						faultrow++;	
					    }
					}
					
				}
				//--------------------END FIRST NAME---------------------------------------------------
				
				//--------------------DISPLAY NAME-----------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[6].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					    seventhEmpty = true; 
					}
					else
					{
					    findSeventh = true;
					    //----------------site name  max length 32 characters------------------
					    klen=0;
					    klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
				            /*-----search for invalid characters ------------------------*/		      
					    if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_NAME_CHARACTERS;
						faultrow++;	
					    }
					    /*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					    else if( (strData.length() > (50*2))     &&   (klen>MAXLENSTR_NAME*2 ) )
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
		   				faults[faultrow][1]=numStations+3;
						faults[faultrow][2]=INVALID_NAME;
						faultrow++;	
					    }
					}
					
				}
				//--------------------END DISPLAY NAME-----------------------------------------------------
				
				//--------------------INTERNAL NUMBER------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[7].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					    eighthEmpty = true; 
					}
					else
					{
					    findEighth = true;
					    // THIS VARIABLE MUST REINIT IN EACHE END OF </ROW>
					    strtmpNumDid = strData.c_str();//This variable is used in case where the DID is 'X', this means that the DID number is same as Internal Number
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());
					    if(!checkvalidCallDuwa(tmpNumbers))
					    {				       
					       faults[0][0]++;
					       faults[faultrow][0]=1;
   					       faults[faultrow][1]=numStations+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
					    				    
					    }
					    else if(strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					       faults[0][0]++;
					       faults[faultrow][0]=1;
   					       faults[faultrow][1]=numStations+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
			    
					    }
					    else
					    {
					   
					    }
					    //----------call old Checks --------------------------------------					    
					    delete[] tmpNumbers;
					}
				}
				//-------------------END INTERNAL NUMBER--------------------------------------------------- 
				
				//-------------------DID-------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[8].element ) == 0 )  )				  
				{
				  bool 	bltmpnumdid=false;
				 
				  
				  if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				  {	
				    ninthEmpty = true; 
				  }
				  else
				  {
					  findNinth = true;
					  if(  (strcmp(strData.c_str(),"x")==0) || (strcmp(strData.c_str(),"X")==0))	
					  {
								if(!findEighth) // Internal number FLAG 
								{
								   faults[0][0]++;
								   faults[faultrow][0]=1;
					   			   faults[faultrow][1]=numStations+3;
								   faults[faultrow][2]=INVALID_CALL_NO;
								   faultrow++;
								}
								else
									bltmpnumdid = true;												
					    }
				   
					    
					    if(bltmpnumdid)
					    {
						tmpNumbers = new char[strtmpNumDid.length()+1];  
						strcpy(tmpNumbers,strtmpNumDid.c_str());
						strtmp_1 = strtmpNumDid;
						
					    }
					    else
					    {
						tmpNumbers = new char[strData.length()+1];  
						strcpy(tmpNumbers,strData.c_str());
						strtmp_1 = strData;
						
						
					    }
					    
					    if( (!checkvalidCallDuwa(tmpNumbers) )  ||  (strcmp(strData.c_str(),"empty") == 0) ) 
					    {
						faults[0][0]++;
						faults[faultrow][0]=1;
	   					faults[faultrow][1]=numStations+3;
					        faults[faultrow][2]=INVALID_DUWA;
					        faultrow++;						    
					    }
					    else if(strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {						       
						faults[0][0]++;
						faults[faultrow][0]=1;
	   					faults[faultrow][1]=numStations+3;
					        faults[faultrow][2]=INVALID_DUWA;
					        faultrow++;			    
					    }
					    else
					    {
						//FPUti::ascii_to_bcd ((INT8U *)tmpNumbers, &kdsreturn.inhalt[0], strlen(tmpNumbers));
						
						
						
					
					    }
					    
					    
					    
					    
					    delete[] tmpNumbers;
					}
				}
				//-------------------END DID---------------------------------------------------------------
				
				//------------------EMAIL ADDRESS----------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[9].element ) == 0 )  )				  
				{
				    if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)   )
				    {	
					tenthEmpty = true;
				    }					
				    else
				    {
					findTenth=true;	
				
					tmpNumbers = new char[strData.length()+1];  
					strcpy(tmpNumbers,strData.c_str());

					if( !checkvalidmail(tmpNumbers) )
					{	
					    faults[0][0]++;
	      				    faults[faultrow][0]=1;
   					    faults[faultrow][1]=numStations+3;
				            faults[faultrow][2]=INVALID_EMAIL;
				            faultrow++;
					}
					else if(strData.length() >  MAX_EMAIL )
					{
					    faults[0][0]++;
		      			    faults[faultrow][0]=1;
	   				    faults[faultrow][1]=numStations+3;
					    faults[faultrow][2]=INVALID_EMAIL;
					    faultrow++;		
					}						
						delete [] tmpNumbers;
				    }
				}
				//------------------END EMAIL ADDRESS----------------------------------------------------------
				
				//------------------MOBILE ----------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[10].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     eleventhEmpty = true;
					}
					else
					{
						findEleventh=true; 
						

						tmpNumbers = new char[strData.length()+1];  
						strcpy(tmpNumbers,strData.c_str());

						if( !checkvalidnumber(tmpNumbers) )
						{					    							    
						    faults[0][0]++;
		      				    faults[faultrow][0]=1;
	   					    faults[faultrow][1]=numStations+3;
					            faults[faultrow][2]=INVALID_MOBILE;
					            faultrow++;	
						}
						else if(strData.length() > MAX_MOBILE)
						{
						    faults[0][0]++;
		      				    faults[faultrow][0]=1;
	   					    faults[faultrow][1]=numStations+3;
					            faults[faultrow][2]=INVALID_MOBILE;
					            faultrow++;	
				
						}
						delete [] tmpNumbers;
					}
				}
				//------------------END MOBILE-------------------------------------------------------
				
				//------------------DEVTYPE----------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[11].element ) == 0 )  )				  
				{
					if ( strcmp(strData.c_str(),"empty") == 0 )
					{	
					     twelvthEmpty = true;
					}					
					else 
					{
						findTwelvth=true; 
						if( !checkDevType(strData.c_str()) )
						{					    
							faults[0][0]++;
							faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=STN_TYP_UNKNOWN;
						        faultrow++;	
						}
						
					}
				}
				//------------------END DEVTYPE-----------------------------------------------------
				
				//-----------------Voicemail---------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[12].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					therteenthEmpty = true; 
				      }
				      else
				      {
					  findTherteenth = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=INVALID_CALL_NO; // Fix ERROR
						   faultrow++;
					  }
				      }
					    
				}
				//-----------------End VoiceMail-----------------------------------------------------
				
				//-----------------Outlook Addin-----------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[13].element ) == 0 )  )				  
				{
				     if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					fourteenthEmpty = true; 
				      }
				      else
				      {
					  findFourteenth = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=INVALID_CALL_NO; // Fix ERROR
						   faultrow++;
					  }
				      }
				}
				//-----------------END Outlook Addin-------------------------------------------------
				
				//-----------------UC Client---------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[14].element ) == 0 )  )				  
				{
				    if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					fifteenthEmpty = true; 
				      }
				      else
				      {
					  findFifteenth = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=INVALID_CALL_NO; // Fix ERROR
						   faultrow++;
					  }
				      }
				}
				//-----------------End UC Client-----------------------------------------------------
				
				//-----------------UC FaAx-----------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[15].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					sixteenthEmpty = true; 
				      }
				      else
				      {
					  findSixteenth = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=INVALID_CALL_NO; // Fix ERROR
						   faultrow++;
					  }
				      }
				}
				//-----------------End UC Fax---------------------------------------------------------
				
				//-----------------Fax Callno---------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[16].element ) == 0 )  )				  
				{
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if Internal Number Is Emprty 
					{					   
					    seventeenthEmpty = true;					    
					}
					else // Check If Valid Call Number 
					{
					    findSeventeenth=true;
					    strtmpFaxDid = strData;
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());
					    if(!checkvalidCallDuwa(tmpNumbers))
					    {				       
					       faults[0][0]++;
					       faults[faultrow][0]=1;
   					       faults[faultrow][1]=numStations+3;
					       faults[faultrow][2]=INVALID_FAXCALLNO;
					       faultrow++;
					    				    
					    }
					    else if(strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					       faults[0][0]++;
					       faults[faultrow][0]=1;
   					       faults[faultrow][1]=numStations+3;
					       faults[faultrow][2]=INVALID_FAXCALLNO;
					       faultrow++;
			    
					    }
					    else//----------call old Checks --------------------------------------
					    {						
						
					     }//----------call old Checks --------------------------------------					    					    
					    delete[] tmpNumbers;
				         }
				}
				//-----------------END Fax Callno-----------------------------------------------------
				
				//-----------------Fax DID------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[17].element ) == 0 )  )				  
				{
				  bool bltmpfaxdid = false;
				  string strtmp_1="";
					  
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if Internal Number Is Emprty 
					{					   
					    eighteenthEmpty = true;					    
					}
					else // Check If Valid Call Number 
					{
					    findEighteenth = true;
					    
					    if(  (strcmp(strData.c_str(),"x")==0) || (strcmp(strData.c_str(),"X")==0))	
					    {
						if(!findSeventeenth) // Internal number FLAG 
						{
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=INVALID_CALL_NO;
						   faultrow++;
						}
						else
						    bltmpfaxdid = true;												
					    }
					    
					    if(bltmpfaxdid)
					    {
						tmpNumbers = new char[strtmpFaxDid.length()+1];  
						strcpy(tmpNumbers,strtmpFaxDid.c_str());
						strtmp_1 = strtmpFaxDid;
						
					    }
					    else
					    {
						tmpNumbers = new char[strData.length()+1];  
						strcpy(tmpNumbers,strData.c_str());
						strtmp_1 = strData;
						
					    }
					    					    
						 //Check if Valid Number  Duwa or Is Empty Then Error
						if( (!checkvalidCallDuwa(tmpNumbers) )   ) 
						{
					     	        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_FAXDID;
					                faultrow++;
						    
						}
						else if(strtmp_1.length() > ((RUFNR_SIZE*2) -2 ))
					    	{						       
						        faults[0][0]++;
							faults[faultrow][0]=1;
	   					        faults[faultrow][1]=numStations+3;
					                faults[faultrow][2]=INVALID_FAXDID;
					                faultrow++;
			    
					    	}
						        							
						else
						{						    	
					
						}
						delete[] tmpNumbers;
					    
					    
					    
					}
				}
				//----------------END Fax DID---------------------------------------------------------
				
				//----------------FAX name------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[18].element ) == 0 )  )				  
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     //thirdEmpty = true;
					     nineteenthEmpty = true;
					}

					else 
					{
						//findThird=true; 
						findNingteenth=true;
						klen=0;
						klen= my_strlen_utf8_c(strData.c_str());
						if( (strData.length() > (TLN_NAME_SIZE))     &&   (klen>TLN_NAME_SIZE ) )
						{
						    	faults[0][0]++;
							faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=INVALID_FAX_NAME;
						        faultrow++;	
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
							faults[faultrow][0]=1;
		   					faults[faultrow][1]=numStations+3;
						        faults[faultrow][2]=INVALID_FAX_NAME;
						        faultrow++;	
						}
												
					}
				}
				//----------------END FAX name--------------------------------------------------------
				
				//----------------Conference Server---------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[19].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentyteenthEmpty = true; 
				      }
				      else
				      {
					  findtwenteenth = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=INVALID_CALL_NO; // Fix ERROR
						   faultrow++;
					  }
				      }
				}
				//----------------END Conference Server-----------------------------------------------
				
				//----------------My Attendant--------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[20].element ) == 0 )  )				  
				{
				    if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentyoneEmpty = true; 
				      }
				      else
				      {
					  findtwentyone = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=INVALID_CALL_NO; // Fix ERROR
						   faultrow++;
					  }
				      }
				}
				//----------------END My Attendant----------------------------------------------------
				
				//----------------myagent-------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[21].element ) == 0 )  )				  
				{
				    if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentytwoEmpty = true; 
				      }
				      else
				      {
					  findtwentytwo = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=INVALID_CALL_NO; // Fix ERROR
						   faultrow++;
					  }
				      }
				}
				//----------------END myagent---------------------------------------------------------
				
				//----------------Application Launcher------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[22].element ) == 0 )  )				  
				{	
				    if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentythreeEmpty = true; 
				      }
				      else
				      {
					  findtwentythree = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=INVALID_CALL_NO; // Fix ERROR
						   faultrow++;
					  }
				      }
				}
				//----------------END Application Launcher--------------------------------------------
				
				//----------------TAPI------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[23].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentyfourEmpty = true; 
				      }
				      else
				      {
					  findtwentyfour = true;
					  if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0))	
					  {						
						   faults[0][0]++;
						   faults[faultrow][0]=1;
					   	   faults[faultrow][1]=numStations+3;
						   faults[faultrow][2]=INVALID_CALL_NO; // Fix ERROR
						   faultrow++;
					  }
				      }
				}
				//----------------END TAPI --------------------------------------------
				
				//----------------Class of service------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[24].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentyfiveEmpty = true; 
				      }
				      else
				      {
					findtwentyfive = true;
					if(  (strcmp(strData.c_str(),"national")!=0) && (strcmp(strData.c_str(),"international")!=0)  && (strcmp(strData.c_str(),"internal")!=0))	
					{						
					   faults[0][0]++;
					   faults[faultrow][0]=1;
					   faults[faultrow][1]=numStations+3;
					   faults[faultrow][2]=INVALID_CALL_NO; // Fix ERROR
					   faultrow++;
					}
					
				      }
				}
				//----------------END Class of sertvice --------------------------------------------
				
				
				//----------------Call PickUp ------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[25].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentysixEmpty = true; 
				      }
				      else
				      {
					findtwentysix = true;
					klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
					/*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					if( (strData.length() > (MAXLENSTRS_CUSTOMER))     &&   (klen>MAXLENSTRS_CUSTOMER ) )
					{
					  faults[0][0]++;
					  faults[faultrow][0]=1;
					  faults[faultrow][1]=numStations+3;
					  faults[faultrow][2]=INVALID_NAME;// FIX Error Message 
					  faultrow++;	
					}
					
				      }
				}
				//----------------END Call PickUp --------------------------------------------
				
				
				//----------------Network Sites------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[26].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentysevenEmpty  = true; 
				      }
				      else
				      {
					findtwentyseven = true;
					klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
					/*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					if( (strData.length() > (MAXLENSTRS_CUSTOMER))     &&   (klen>MAXLENSTRS_CUSTOMER ) )
					{
					  faults[0][0]++;
					  faults[faultrow][0]=1;
					  faults[faultrow][1]=numStations+3;
					  faults[faultrow][2]=INVALID_NAME;// FIX Error Message 
					  faultrow++;	
					}
					
				      }
				}
				//----------------END Network Sites --------------------------------------------
				
				
				//----------------Secondary GW------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[27].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentyEightEmpty  = true; 
				      }
				      else
				      {
					findtwentyEight = true;
					klen= my_strlen_utf8_c(strData.c_str()); /*Check utf8 string size*/
					/*-------the max string length(and utf8)   cannot be greater than MAXLENSTRS_CUSTOMER  */
					if( (strData.length() > (MAXLENSTRS_CUSTOMER))     &&   (klen>MAXLENSTRS_CUSTOMER ) )
					{
					  faults[0][0]++;
					  faults[faultrow][0]=1;
					  faults[faultrow][1]=numStations+3;
					  faults[faultrow][2]=INVALID_NAME;// FIX Error Message 
					  faultrow++;	
					}
					
				      }
				}
				//----------------END Secondary GW --------------------------------------------
				
				
				//----------------Access------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlUsaElements[28].element ) == 0 )  )				  
				{
				      if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
				      {	
					twentynineEmpty  = true; 
				      }
				      else
				      {
								findtwentynine = true;
								i = strData.find("-");
								if( (i == -1)  || (strData.length() <3)  || ( (strData.length() - i) < 1 )  || (i==0) )
								{
									faults[0][0]++;
									faults[faultrow][0]=1;
		   							faults[faultrow][1]=numStations+3;
										faults[faultrow][2]=WRONG_ACEESS_FORMAT;
										faultrow++;	
								}
				
								tmpNumbers = new char[strData.length()+1];  
								strcpy(tmpNumbers,strData.substr(0,strData.find(" ")).c_str());
								//strcpy(tmpNumbers,strData.c_str());
								if(checkvalidAccess(tmpNumbers) == false)
								{						
									faults[0][0]++;
									faults[faultrow][0]=1;
	   								faults[faultrow][1]=numStations+3;
										faults[faultrow][2]=WRONG_ACEESS_FORMAT;
										faultrow++;	
								}
								else if (( strcmp("Master",strData.substr(strData.find(" ")+1).c_str() )  !=0   )   &&	( strcmp("Slave",strData.substr(strData.find(" ")+1).c_str() )  !=0   ) )
								{
									faults[0][0]++;
									faults[faultrow][0]=1;
									faults[faultrow][1]=numStations+3;
										faults[faultrow][2]=WRONG_ACEESS_FORMAT;
										faultrow++;							
								}
					
				      }
				}
				//----------------END Acess --------------------------------------------
				
				
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					
					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) && (fourthEmpty) && (fifthEmpty) && (sixthEmpty) && (seventhEmpty) && (eighthEmpty)&& (ninthEmpty)&&(tenthEmpty) &&(eleventhEmpty) &&
					(twelvthEmpty)   &&  (therteenthEmpty) )
					{
					    blStations = false;

					    firstEmpty=false; secondEmpty=false; thirdEmpty=false;   fourthEmpty=false;   fifthEmpty=false; sixthEmpty=false; seventhEmpty=false;   eighthEmpty=false;	
					    ninthEmpty=false; tenthEmpty=false; eleventhEmpty=false; twelvthEmpty=false; therteenthEmpty=false;fourteenthEmpty=false; fifteenthEmpty=false; 
					    sixteenthEmpty=false; seventeenthEmpty=false; eighteenthEmpty=false; nineteenthEmpty=false; twentyteenthEmpty=false;twentyoneEmpty=false; twentytwoEmpty=false;
					    twentythreeEmpty=false; twentyfourEmpty=false; twentyfiveEmpty=false; twentysixEmpty=false; twentysevenEmpty=false; twentyEightEmpty=false; twentynineEmpty=false;
					    block =0;
					    record = 0;					    
				        }
					
					
					if( (findFirst) && (findSecond) && (findThird)  && (findFourth) && (findFifth) && (findSixth) && (findSeventh) && (findEighth) && (findNinth)&&(findTenth) &&(findEleventh) &&
					(findTwelvth)   &&  (findTherteenth) )
					{
					    firstEmpty=false; secondEmpty=false; thirdEmpty=false;   fourthEmpty=false;   fifthEmpty=false; sixthEmpty=false; seventhEmpty=false;   eighthEmpty=false;	
					    ninthEmpty=false; tenthEmpty=false; eleventhEmpty=false; twelvthEmpty=false; therteenthEmpty=false;fourteenthEmpty=false; fifteenthEmpty=false; 
					    sixteenthEmpty=false; seventeenthEmpty=false; eighteenthEmpty=false; nineteenthEmpty=false; twentyteenthEmpty=false;twentyoneEmpty=false; twentytwoEmpty=false;
					    twentythreeEmpty=false; twentyfourEmpty=false; twentyfiveEmpty=false; twentysixEmpty=false; twentysevenEmpty=false; twentyEightEmpty=false; twentynineEmpty=false;

					} 
					else if( (findEighth)  && (!findTwelvth) )
					{
						faults[0][0]++;
						faults[faultrow][0]=1;
	   					faults[faultrow][1]=numStations+2;
					        faults[faultrow][2]=STN_TYP_UNKNOWN;
					        faultrow++;	
					}
					else if( (!findEighth) &&  ((findFirst)  ||  ((findSecond) || (findThird)  || (findFourth) || (findFifth) || (findSixth) || (findSeventh) || (findEighth) || (findNinth) || (findTenth) || (findEleventh) ||
					(findTwelvth) ||(findTherteenth) ||(findFourteenth) ||(findFifteenth)  ||(findSixteenth)  ||(findSeventeenth)  ||(findEighteenth)  ||(findNingteenth)  ||(findtwenteenth)
					||(findtwentyone)  ||(findtwentytwo)  ||(findtwentythree) ||(findtwentyfour)  ||(findtwentyfive) ||(findtwentysix) ||(findtwentyseven) ||(findtwentyEight) ||(findtwentynine))))
					{					    
					    
					    faults[0][0]++;
			      		    faults[faultrow][0]=1;
		   			    faults[faultrow][1]=numStations+3;
					    faults[faultrow][2]=CALL_NO_MISSING;
					    faultrow++;
					}
					
					if( ((findEighth)    &&   (!findFirst))   )
					{
						faults[0][0]++;
						faults[faultrow][0]=1;
	   				        faults[faultrow][1]=numStations+3;
					        faults[faultrow][2]=INVALID_NODEID;
					        faultrow++;
					}


					
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) && (!findFifth) && (!findSixth)  && (!findSeventh) && (!findEighth) && (!findNinth)&&(!findTenth) &&(!findEleventh) &&
					(!findTwelvth)   &&  (!findTherteenth) )
					{
					    //blStations = false;
					    numStations = numStations;
					}
					else
					  numStations++;
					
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;findTherteenth=false;				
					findFourteenth=false; findFifteenth=false; findSixteenth=false; findSeventeenth=false; findEighteenth=false; findNingteenth=false; findtwenteenth=false;
					findtwentyone=false; findtwentytwo=false; findtwentythree=false; findtwentyfour=false; findtwentyfive=false; findtwentysix=false; findtwentyseven=false; findtwentyEight=false; findtwentynine=false;

					
					firstEmpty=false; secondEmpty=false; thirdEmpty=false;   fourthEmpty=false;   fifthEmpty=false; sixthEmpty=false; seventhEmpty=false;   eighthEmpty=false;	
					ninthEmpty=false; tenthEmpty=false; eleventhEmpty=false; twelvthEmpty=false; therteenthEmpty=false;fourteenthEmpty=false; fifteenthEmpty=false; 
					sixteenthEmpty=false; seventeenthEmpty=false; eighteenthEmpty=false; nineteenthEmpty=false; twentyteenthEmpty=false;twentyoneEmpty=false; twentytwoEmpty=false;
					twentythreeEmpty=false; twentyfourEmpty=false; twentyfiveEmpty=false; twentysixEmpty=false; twentysevenEmpty=false; twentyEightEmpty=false; twentynineEmpty=false;

					strtmpNumDid="";
					strtmpFaxDid = "";
				}
				
								


			} // END if(blStations)
//---------------------------------------------- END STATIONS--------------------------------------------------------------------------------------------------------------			
			//-----------------------------------------------GROUPS START-----------------------------------------------------------------------------------------------------------			
			else if( (blGroups))
			{				
				//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlGroupsNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[0].headerrecord)!= 0 ) )
				{
					//numGroups++;
					if ( strcmp(strData.c_str(),"empty") == 0 ) // Check if GRoup Internal Number Is Emprty 
					{										   
					     firstEmpty = true;	
					     //numGroups--;			    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true; 
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {					       
					       faults[0][0]++;
				      	       faults[faultrow][0]=3;
		   			       faults[faultrow][1]=numGroups+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					       faults[0][0]++;
				      	       faults[faultrow][0]=3;
		   			       faults[faultrow][1]=numGroups+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
					    }
					    else
					    {
				
					    
					    }					    					    		

					    delete [] tmpNumbers;
					}     	
					numberoflines++;
					
					
				}
				//------------------------------DID NUMBER -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlGroupsNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[1].headerrecord)!= 0 ) )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  ) // Check if GRoup Internal Number Is Emprty 
					{										   
					     secondEmpty = true;
				    
					}
					else // Check If Valid Call Number 
					{
					    findSecond=true; 
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
				               faults[0][0]++;
				      	       faults[faultrow][0]=3;
		   			       faults[faultrow][1]=numGroups+3;
					       faults[faultrow][2]=INVALID_DUWA;
					       faultrow++;
					    }
					    else if (strData.length() > ((DID_SIZE*2) -1) )
		   			    {
				               faults[0][0]++;
				      	       faults[faultrow][0]=3;
		   			       faults[faultrow][1]=numGroups+3;
					       faults[faultrow][2]=INVALID_DUWA;
					       faultrow++;
					    }
					    else
					    {
					     		
					    }
					    
					    
					    delete [] tmpNumbers;
					}    
					 	
				}
				//------------------------------DISPLAY NAME -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlGroupsNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[2].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}
					else 
					{	klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=INVALID_NAME;
						       faultrow++;
						}
						else if ( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=INVALID_NAME;
						       faultrow++;	
						}
						findThird=true; 
					}
					
				}
				//------------------------------Voicemail -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlGroupsNameTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[3].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}
					else 
					{							
						if(  (strcmp(strData.c_str(),"x")!=0) && (strcmp(strData.c_str(),"X")!=0)  )	
						{
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=WRONG_VOICEMAIL_FORMAT;
						       faultrow++;
						}
						findThird=true; 
					}
					
				}
				//------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlGroupsNameTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[4].headerrecord)!= 0)  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     fourthEmpty = true;
					}					
					else 
					{
						if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{	       
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;						       
	
						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;						       
						}
						else if ( strData.length() > 4) 
						{
						       faults[0][0]++;
					      	       faults[faultrow][0]=3;
			   			       faults[faultrow][1]=numGroups+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;						       
						}
					
						findFourth=true; 
					}
					
					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) )
					{
					   // blGroups = false;
					   numGroups=numGroups;
					}
					else
					   numGroups++;


					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) && (fourthEmpty) )
					{
					    blGroups = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
					    fourthEmpty=false;
				        }
				       
					if( (findFirst) && (findSecond) && (findThird)  && (findFourth)  )
					{
						findFirst=false; findSecond=false; findThird=false; findFourth=false; 
					} 
					else if( (!findFirst) &&  ((findSecond) || (findThird)  || (findFourth) ) )
					{	
						faults[0][0]++;
				      	    	faults[faultrow][0]=3;
		   			    	faults[faultrow][1]=numGroups+3;
					    	faults[faultrow][2]=CALL_NO_MISSING;
					    	faultrow++;					
					}
					
					   
					firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;

					
				}
				
								
			}// END blGroups
			
else if( (blVirtual)  )
			{

	  			//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlVirtualNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[0].headerrecord)!= 0 ) )
				{
					//numVirtual++;
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     firstEmpty = true;	
					     //numVirtual--;			    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true;   
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
				           	faults[0][0]++;
				      	    	faults[faultrow][0]=3;
		   			    	faults[faultrow][1]=numVirtual+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;						       					    
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					        faults[0][0]++;
				      	    	faults[faultrow][0]=3;
		   			    	faults[faultrow][1]=numVirtual+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;	
					    
					    }
					    else
					    {
						    
					    }
					    					    
					    delete [] tmpNumbers;
					}
					   	
					numberoflines++;
				}
				//------------------------------DID NUMBER -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVirtualNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[1].headerrecord)!= 0 ) )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  ) // Check if GRoup Internal Number Is Emprty 
					{										   
					     secondEmpty = true;
				    
					}
					else // Check If Valid Call Number 
					{
					    findSecond=true;  
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
					        faults[0][0]++;
 			      	    		faults[faultrow][0]=3;
		   			    	faults[faultrow][1]=numVirtual+3;
					    	faults[faultrow][2]=INVALID_DUWA;
					    	faultrow++;
	
					    }
					    else if (strData.length() > ((DID_SIZE*2) -1) )
					    {
					        faults[0][0]++;
 			      	    		faults[faultrow][0]=3;
		   			    	faults[faultrow][1]=numVirtual+3;
					    	faults[faultrow][2]=INVALID_DUWA;
					    	faultrow++;
					    }
					    else
					    {
					    						    }					    					    
					    
					    delete [] tmpNumbers;
					}    
						
				}
				//------------------------------DISPLAY NAME -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVirtualNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[2].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}
					else 
					{

						klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						   faults[0][0]++;
	 			      	    	   faults[faultrow][0]=3;
			   			   faults[faultrow][1]=numVirtual+3;
						   faults[faultrow][2]=INVALID_NAME;
						   faultrow++;	
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
	 			      	    	   	faults[faultrow][0]=3;
			   			   	faults[faultrow][1]=numVirtual+3;
						   	faults[faultrow][2]=INVALID_NAME;
						   	faultrow++;		
						}
						findThird=true;
					}
				}
				//----------------------------STATION TYPE ------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVirtualNameTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(),xmlVirtualNameTable[3].headerrecord)!=0) )
				{
					if ( strcmp(strData.c_str(),"empty") == 0 )
					{	
					     fourthEmpty = true;
					}					
					else
					{ 
						if(blX1)
						{
							if(strcmp ( strData.c_str(),  xmlVirtualStationTypes[5].name ) != 0  )
							{
								faults[0][0]++;
								faults[faultrow][0]=3;
		   						faults[faultrow][1]=numVirtual+3;
						        	faults[faultrow][2]=STN_TYP_UNKNOWN;
						        	faultrow++;
							}
							
							findFourth=true;
						
						}
						else
						{
						if( !CheckStationTypeVirtual(strData.c_str()) ) // ||  (strcmp(strData.c_str(),"empty") == 0) )
						{					    					    
						    faults[0][0]++;
	  			      	    	    faults[faultrow][0]=3;
			   			    faults[faultrow][1]=numVirtual+3;
						    faults[faultrow][2]=STN_TYP_UNKNOWN;
						    faultrow++;
						}
						findFourth=true;
						}
					}
				}
				//------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVirtualNameTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[4].headerrecord)!= 0)  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     fifthEmpty = true;
					}					
					else 
					{
						if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{
						    faults[0][0]++;
  				      	    	    faults[faultrow][0]=3;
			   			    faults[faultrow][1]=numVirtual+3;
						    faults[faultrow][2]=INVALID_NODEID;
						   faultrow++;

						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						    faults[0][0]++;
	  			      	    	    faults[faultrow][0]=3;
		   				    faults[faultrow][1]=numVirtual+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;
						}
						else if(strData.length() > 4)
						{
						    faults[0][0]++;
  			      		    	    faults[faultrow][0]=3;
		   				    faults[faultrow][1]=numVirtual+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;
						}
															
						findFifth=true; 
					}
					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) && (!findFifth)  )
					{
					    blVirtual = false;
					   numVirtual = numVirtual;
					}
					else
					   numVirtual++;
						
					
					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) && (fourthEmpty) && (fifthEmpty))
					{
					    blVirtual = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
					    fourthEmpty=false;
					    fifthEmpty=false;
				        }
				       /*
				        else if(  (firstEmpty)  && ( (!secondEmpty) || (!thirdEmpty) || (!fourthEmpty)  || (!fifthEmpty)  )  )
				        {
					    faults[0][0]++;
  			      	    	    faults[faultrow][0]=4;
		   			    faults[faultrow][1]=numVirtual+2;
					    faults[faultrow][2]=CALL_NO_MISSING;
					    faultrow++;
					    
					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
					    fourthEmpty=false;
					    fifthEmpty = false;
 				        }
					*/
					if( (findFirst) && (findSecond) && (findThird)  && (findFourth) && (findFifth)  )
					{
						findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; 
					}
					else if(  (findFirst) &&  (!findFourth) )
					{
						 faults[0][0]++;
	  			      	    	 faults[faultrow][0]=3;
			   			 faults[faultrow][1]=numVirtual+3;
						 faults[faultrow][2]=STN_TYP_UNKNOWN;
						 faultrow++;						
					} 
					else if( (!findFirst) &&  ((findSecond) || (findThird)  || (findFourth) || (findFifth)  ) )
					{		
						faults[0][0]++;
  			      	    	   	faults[faultrow][0]=3;
		   			    	faults[faultrow][1]=numVirtual+3;
					   	faults[faultrow][2]=CALL_NO_MISSING;
					   	faultrow++;	
					}
					
					firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
					//numVirtual++;
				}
			

				


			}// END If VIRTUAL
//-----------------------------------------------VIRTUAL END-----------------------------------------------------------------------------------------------------------									
			
//-----------------------------------------------TRUNK GROUPS---------------------------------------------------------------------------------------------------------			
			else if( (blTrunkGroup) )
			{

				//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlTrunkGrpNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlTrunkGrpNameTable[0].headerrecord)!= 0 ) )
				{
					//numTrunkGroups++;
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     firstEmpty = true;	
					    // numTrunkGroups--;			    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true; 
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
						faults[0][0]++;
  			      	    	    	faults[faultrow][0]=4;
		   			    	faults[faultrow][1]=numTrunkGroups+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
						faults[0][0]++;
  			      	    	    	faults[faultrow][0]=4;
		   			    	faults[faultrow][1]=numTrunkGroups+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;
					    }
					    else
					    {

						     
					    					    
					    }
					    
					    delete [] tmpNumbers;
					}     	
					numberoflines++;
					
				}
				//------------------------------DISPLAY NAME -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlTrunkGrpNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlTrunkGrpNameTable[1].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     secondEmpty = true;
					}
					else 
					{
						
						klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						    faults[0][0]++;
  			      	    		    faults[faultrow][0]=4;
		   				    faults[faultrow][1]=numTrunkGroups+3;
						    faults[faultrow][2]=INVALID_NAME;
						    faultrow++;
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
						    faults[0][0]++;
  			      	    		    faults[faultrow][0]=4;
		   				    faults[faultrow][1]=numTrunkGroups+3;
						    faults[faultrow][2]=INVALID_NAME;
						    faultrow++;	
						}
						findSecond=true;
					}
				}
				//------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlTrunkGrpNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlTrunkGrpNameTable[2].headerrecord)!= 0)  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}					
					else 
					{
						if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{					       
						    faults[0][0]++;
  				      	    	    faults[faultrow][0]=4;
			   			    faults[faultrow][1]=numTrunkGroups+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;					       					       
						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						    faults[0][0]++;
  				      	    	    faults[faultrow][0]=4;
			   			    faults[faultrow][1]=numTrunkGroups+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;					       					       
						}
						else if (strData.length() > 4)
						{
						    faults[0][0]++;
  				      	    	    faults[faultrow][0]=4;
			   			    faults[faultrow][1]=numTrunkGroups+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;					       					       
						}
						findThird=true; 
					}
						
					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) && (!findFifth) && (!findSixth)  && (!findSeventh) && (!findEighth) && (!findNinth) && (!findTenth) && (!findEleventh) && (!findTwelvth)  )
					{
					    numTrunkGroups=numTrunkGroups;
					}
					else
						numTrunkGroups++;
					
					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) )
					{
					    blTrunkGroup = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
				        }
				        /*else if(  (firstEmpty)  && ( (!secondEmpty) || (!thirdEmpty)  )  )
				        {
					    faults[0][0]++;
  			      	    	    faults[faultrow][0]=5;
		   			    faults[faultrow][1]=numTrunkGroups+2;
					    faults[faultrow][2]=CALL_NO_MISSING;
					    faultrow++;					       					       
					    					    
					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
 				        }	
					*/
					if( (findFirst) && (findSecond) && (findThird)  )
					{
						findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
					} 
					else if( (!findFirst) &&  ((findSecond) || (findThird)  ) )
					{	
						faults[0][0]++;
  			      	    	    	faults[faultrow][0]=4;
		   			    	faults[faultrow][1]=numTrunkGroups+3;
					    	faults[faultrow][2]=CALL_NO_MISSING;
					    	faultrow++;					       					       					    				
					}
					
					
					firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
					
				}				
				

			}
			else if( (blVoicemail) )
			{

				//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlVoiceMailNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVoiceMailNameTable[0].headerrecord)!= 0 ) )
				{
					//numVoicemail++;
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     firstEmpty = true;	
					     //numVoicemail--;			    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true; 
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {					       
					       faults[0][0]++;
	  			      	       faults[faultrow][0]=5;
			   		       faults[faultrow][1]=numVoicemail+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					       faults[0][0]++;
	  			      	       faults[faultrow][0]=5;
			   		       faults[faultrow][1]=numVoicemail+3;
					       faults[faultrow][2]=INVALID_CALL_NO;
					       faultrow++;
				            }
					    else
					    {
						     
					    }
					    delete [] tmpNumbers;
					}     	
					numberoflines++;
					
				}
				//------------------------------DISPLAY NAME -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVoiceMailNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVoiceMailNameTable[1].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     secondEmpty = true;
					}
					else
					{
						klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE)  )
						{
					       		faults[0][0]++;
	  			      	       		faults[faultrow][0]=5;
				   		       	faults[faultrow][1]=numVoicemail+3;
						       	faults[faultrow][2]=INVALID_NAME;
						       faultrow++;
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
	  			      	       		faults[faultrow][0]=5;
				   		       	faults[faultrow][1]=numVoicemail+3;
						       	faults[faultrow][2]=INVALID_NAME;
						       faultrow++;	
						}
						findSecond=true; 
					}
				}
				//------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlVoiceMailNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVoiceMailNameTable[2].headerrecord)!= 0)  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}					
					else
					{
						 if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{					       
					       		faults[0][0]++;
		  			      	       	faults[faultrow][0]=5;
				   		       faults[faultrow][1]=numVoicemail+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;
						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						       faults[0][0]++;
		  			      	       faults[faultrow][0]=5;
				   		       faults[faultrow][1]=numVoicemail+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;
						}
						else if(strData.length() > 4)
						{
						       faults[0][0]++;
		  			      	       faults[faultrow][0]=5;
				   		       faults[faultrow][1]=numVoicemail+3;
						       faults[faultrow][2]=INVALID_NODEID;
						       faultrow++;
						}
						
						findThird=true; 
					}					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					
					if( (!findFirst) && (!findSecond) && (!findThird) )
					{
						numVoicemail = numVoicemail;
						
					} 
					else
						numVoicemail++;
						
					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) )
					{
					    blVoicemail = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
				        }										
					
					else if( (!findFirst) &&  ((findSecond) || (findThird) ) )
					{		
						faults[0][0]++;
	  			      	  	faults[faultrow][0]=5;
			   		    	faults[faultrow][1]=numVoicemail+3;
					    	faults[faultrow][2]=CALL_NO_MISSING;
					    	faultrow++;		
					}
					findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;	
					firstEmpty=false;secondEmpty=false;thirdEmpty=false;fourthEmpty=false;fifthEmpty=false;sixthEmpty=false;seventhEmpty=false;eighthEmpty=false;ninthEmpty=false;tenthEmpty=false;eleventhEmpty=false;
					//numVoicemail++;
				}
				
			} // end if voicemail
			
//-----------------------------------------------SipConfig-----------------------------------------------------------------------------------------------------------									
			
			else if( (blSipConfig) )
			{

	  			//------------------------------INTERNAL NUMBER-----------------------------------------------------------------------------------------------
				if( ( strcmp(strCell.c_str(),xmlSipConfigTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[0].headerrecord)!= 0 ) )
				{
					
					if ( strcmp(strData.c_str(),"empty") == 0 ) 
					{										   
					     firstEmpty = true;	
					     		    
					}
					else // Check If Valid Call Number 
					{
					    findFirst=true;   
					    
					    tmpNumbers = new char[strData.length()+1];  
					    strcpy(tmpNumbers,strData.c_str());

					    if(!checkvalidCallDuwa(tmpNumbers))
					    {
				           	faults[0][0]++;
				      	    	faults[faultrow][0]=6;
		   			    	faults[faultrow][1]=numSipConfig+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;						       					    
					    }
					    else if (strData.length() > ((RUFNR_SIZE*2) -2 ) )
					    {
					        faults[0][0]++;
				      	    	faults[faultrow][0]=6;
		   			    	faults[faultrow][1]=numSipConfig+3;
					    	faults[faultrow][2]=INVALID_CALL_NO;
					    	faultrow++;	
					    
					    }
					    else
					    {
						     
					    }
					    					    
					    delete [] tmpNumbers;
					}
					   	
					numberoflines++;
				}
				//------------------------------Password Sip -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlSipConfigTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[1].headerrecord)!= 0 ) )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  ) // Check if GRoup Internal Number Is Emprty 
					{										   
					     secondEmpty = true;
				    
					}
					else // Check If Valid Call Number 
					{
					    findSecond=true;  
					    klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						   faults[0][0]++;
	 			      	    	   faults[faultrow][0]=6;
			   			   faults[faultrow][1]=numSipConfig+3;
						   faults[faultrow][2]=INVALID_PASSWORD;
						   faultrow++;	
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
	 			      	    	   	faults[faultrow][0]=6;
			   			   	faults[faultrow][1]=numSipConfig+3;
						   	faults[faultrow][2]=INVALID_PASSWORD;
						   	faultrow++;		
						}
					    // Here will check the type of password					    
					}    
						
				}
				//------------------------------UserId/Username  -----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlSipConfigTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[2].headerrecord)!= 0)  )
				{
					
					if ( (strcmp(strData.c_str(),"empty") == 0) ||  (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     thirdEmpty = true;
					}
					else 
					{

						klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						   faults[0][0]++;
	 			      	    	   faults[faultrow][0]=6;
			   			   faults[faultrow][1]=numSipConfig+3;
						   faults[faultrow][2]=INVALID_USERID_USERNAME;
						   faultrow++;	
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
	 			      	    	   	faults[faultrow][0]=6;
			   			   	faults[faultrow][1]=numSipConfig+3;
						   	faults[faultrow][2]=INVALID_USERID_USERNAME;
						   	faultrow++;		
						}
						findThird=true;
					}
				}
				//----------------------------Realm ------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlSipConfigTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(),xmlSipConfigTable[3].headerrecord)!=0) )
				{
					if ( strcmp(strData.c_str(),"empty") == 0 )
					{	
					     fourthEmpty = true;
					}					
					else
					{ 						
						klen = 0;
						klen = my_strlen_utf8_c(strData.c_str());
						if( (strData.length() >  (TLN_NAME_SIZE+1) )    &&   (klen>TLN_NAME_SIZE )  )
						{
						   faults[0][0]++;
	 			      	    	   faults[faultrow][0]=6;
			   			   faults[faultrow][1]=numSipConfig+3;
						   faults[faultrow][2]=INVALID_REALM;
						   faultrow++;	
						}
						else if( (strData.find("\"")  != -1)  || (strData.find("\\")  != -1)  || (strData.find("quot")  != -1)  || (strData.find("/")  != -1)   )
						{
							faults[0][0]++;
	 			      	    	   	faults[faultrow][0]=6;
			   			   	faults[faultrow][1]=numSipConfig+3;
						   	faults[faultrow][2]=INVALID_REALM;
						   	faultrow++;		
						}   
					  findFourth=true;						
					}
				}
				//------------------------------NODE-----------------------------------------------------------------------------------------------
				else if( ( strcmp(strCell.c_str(),xmlSipConfigTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[4].headerrecord)!= 0)  )
				{
					if ( (strcmp(strData.c_str(),"empty") == 0) || (strcmp(strData.c_str(),"-") == 0)  )
					{	
					     fifthEmpty = true;
					}					
					else 
					{
						if ( (atoi(strData.c_str()) == 0)  && (strData !="0") && (strData!="empty")  ) 
						{
						    faults[0][0]++;
  				      	    	    faults[faultrow][0]=6;
			   			    faults[faultrow][1]=numSipConfig+3;
						    faults[faultrow][2]=INVALID_NODEID;
						   faultrow++;

						}					
						else if(  (atoi(strData.c_str())  < 0)   ||  (atoi(strData.c_str())  > 999 ))
						{
						    faults[0][0]++;
	  			      	    	    faults[faultrow][0]=6;
		   				    faults[faultrow][1]=numSipConfig+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;
						}
						else if(strData.length() > 4)
						{
						    faults[0][0]++;
  			      		    	    faults[faultrow][0]=6;
		   				    faults[faultrow][1]=numSipConfig+3;
						    faults[faultrow][2]=INVALID_NODEID;
						    faultrow++;
						}
															
						findFifth=true; 
					}
					
				}
				else if( strcmp(strData.c_str(),"</Row>")  == 0  )
				{
					if( (!findFirst) && (!findSecond) && (!findThird) && (!findFourth) && (!findFifth)  )
					{
					   // blVirtual = false;
					   numSipConfig = numSipConfig;
					}
					else
					   numSipConfig++;
						
					
					if ( (firstEmpty) && (secondEmpty) && (thirdEmpty) && (fourthEmpty) && (fifthEmpty))
					{
					    blSipConfig = false;

					    firstEmpty=false;
					    secondEmpty=false;
					    thirdEmpty=false;
					    fourthEmpty=false;
					    fifthEmpty=false;
				        }
				       
				}
			

				


			}// END If SipConfig
//-----------------------------------------------SipConfig-----------------------------------------------------------------------------------------------------------									
			


		}  // END // If the Record is OK
		

	countLine++;//increase countLines number to numberring Lines   
	
    }// ----end while read lines-------
    
   
    type[0] = numStations; // Licenses Number
    type[1] = numLicenses; // Licenses Number
    type[2] = numGroups;   // Group Number
    type[3] = numVirtual;   //  Virtual Number
    type[4] = numTrunkGroups; // Trunk number
    type[5] = numVoicemail;   // Voicemail Number 
    type[6] = numSipConfig;   // Voicemail Number 
    
    
    if(corXml==0)
    {
	    faults[0][0]++;
	    faults[faultrow][0]=1;
	    faults[faultrow][1]= 0; // invalid Xml with no contents 
	    faults[faultrow][2]=INVALID_FILE_FORMAT;
	    faultrow++;	
    }
    
    errorCount = faultrow; 

	printf("\n ilias faultrow=%d---numStations=%d",faultrow,numStations);

    fclose(fxml);

    if(faults[0][0]==0)
    return  0; 
    else 
    return errorCount;  

    
  //
}
bool writeXmlStationsUsa(char* fname,int numStations)
{
  
  //
	return true;
}

void readXmlUsa(char* fname, int faults[21][3] , bool blBooster)
{
 // 
   char line [128]; 
    FILE *fxml = fopen(fname,"r");
    int fLast,fFirst,intLen,wksFound,findNameCell=0,findCell=0,countLine=0,wksRowFound,fFiltDb=0;
    string tempstr,totalstr,strData,strCell ;  
    //bool blStations=false,blCellEnd=false,blEndRecord=false,firstEmpty=false,blwriteXmlStations=false ;  
    bool blStations=false,blLicenses=false,blGroups=false,blVirtual=false,blTrunkGroup=false,blVoicemail=false,blCellEnd=false,blEndRecord=false,firstEmpty=false,blSipConfig=false;   
    bool blwriteXmlStations=false, blwriteXmlLicenses=false,  blwriteXmlGroups=false, blwriteXmlVirtual=false, blwriteXmlTrunks=false, blwriteXmlVoicemail=false,blwritexmlSipConfig=false;    
    int i=0,pos=0,numberoflines=0,returnvalue=0,isumNodeStVir=0;	
    char **stnNumber,**stnDuwa,**stnNode,**stnLicnum, **stnStType,**stnStTypeNode,**stnAccessUP0,**stnAccessAnalog,**stnVoicemail, **stnFaxCallno, **stnFaxDid ,**stnAllStations, **stnAllFaxes,**stnSipStations,**stnSipConfig;
    int dublicatepos[20], icurrentitem=0;
    int faultrow=0,ievmCounter=0;
    int arrayNumRecords[7];   
    int num_count=0, duwa_count=0, node_count=0,lic_count=0,stType_count=0, stTypeNode_count=0,countAccessUP0=0,countAccessAnalog=0,ifaxCallnoCount=0, ifaxDidCount=0,icountAllst=0,icountAllFax=0,icountSip=0,icountSipConfig=0; 
    int numStation=0,numLic=0,numGroup=0,numVirtual=0,numTrnk=0,numVoicemail=0, numSipConfig=0;
    int curNode=0, countNodeTrunksGr=0,countNodeVoicemail=0,countNodeGroups=0;
    RD_KDS_RETURN	kdsretNode;
    int  stSipCounter=0, stSipFaxCounter=0, stUp0Counter=0, stIpCounter=0, stRasCounter=0, stDeskCounter=0, stabFaxCounter=0, stabCounter=0, stIsdnCounter=0, stDectCounter=0, stRasAdminCounter=0, stRasLicCounter=0;
    int syscountUp0=0,syscountAn=0,syscountDect=0,syscountIsdn=0; 
    int syscountPark=0, syscountConf=0,syscountAutoAt=0, syscountCCFax=0, sysCountFaxGroup=0,sysCountVirtual=0,sysCountMeetMe=0;
    bool findFirst=false,findSecond=false,findThird=false,findFourth=false,findFifth=false,findSixth=false,findSeventh=false,findEighth=false,findNinth=false,findTenth=false,findEleventh=false,findTwelvth=false,blX1=false;
    double div=0;   
    char **stnCallPick;
    int icountCallPick=0;
    bool blisBooster=false;
     int  curNodeAtoi=0;



    RD_KDS_RETURN           kdsreturnX1;
    
    

   // if(kdsreturnX1.inhalt[0]== DS_BPL_ONE_X1)  //DS_BPL_ONE
  	//blX1=true; // means system is X1
	kdsretNode.inhalt[3]  = 1;


   
    for(i=0;i<21;i++)
    {
	for(pos=0;pos<3;pos++)
		faults[i][pos]=0;
    }

   //--- Check if The File Extension Is .xml
   
   
   returnvalue = compare_extension(fname,".xml" );
   if(returnvalue ==0)
   {  	
	faults[0][0]++;
	faults[faultrow+1][0]=1;	// invalid file format 
	faults[faultrow+1][1]=999;	
	faults[faultrow+1][2]=INVALID_FILE_FORMAT;	
	faultrow++;	
	return;			
    }
    else 
       returnvalue = 0;
    
  //-------------------------CHECK THE NUMER OF RECORDS AND THE VALIDATION-------------------	
     blisBooster=blBooster;
     
     returnvalue = checkXmlFormatErrorsUsa11(fname,arrayNumRecords,faultrow,faults,blisBooster); // ) no fault , 1 there are faults


    if(returnvalue > 1)
    {    	
	fclose(fxml);
	return;
    }    
    else 
      faultrow++;
    
  //  Db_rddtb(KDS_NODE_ID,KEINE_ZEILE,KEINE_SPALTE,(RD_KDS_RETURN*)&kdsretNode);
    
    
    numStation = arrayNumRecords[0] ;
    numLic = arrayNumRecords[1] ; 
    numGroup = arrayNumRecords[2];
    numVirtual = arrayNumRecords[3];
    numTrnk = arrayNumRecords[4];
    numVoicemail = arrayNumRecords[5];
    numSipConfig = arrayNumRecords[6];    
       
    
    stnNumber = new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic]; 
    stnDuwa   = new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic];
    stnNode   = new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic];
    stnLicnum = new char*[numLic];
    stnStType = new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic]; 
    stnStTypeNode= new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic]; 
    stnAccessAnalog = new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic]; 
    stnAccessUP0 = new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic]; 
    stnVoicemail= new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic]; 
    stnFaxCallno= new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic]; 
    stnFaxDid= new char*[numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic]; 
    stnAllStations=new char*[numStation*2];
    stnAllFaxes=new char*[numStation*2];
    stnCallPick = new char*[65];
    
    for(i=0;  i<65; i++)
    {
    	stnCallPick[i]=new char[(RUFNR_SIZE*2)+1];
    }
    
    for(i=0;  i<65; i++)
    {
    	for(pos=0;pos<RUFNR_SIZE*2;pos++)
	{
	  stnCallPick[i][pos]='\0';
	}
    }
    
    /*----------------------sip config --------------------*/
    stnSipStations=new char*[numStation+1];
    stnSipConfig=new char*[numSipConfig+1];
    
    
    for(i=0;  i<numStation+1; i++)
    {
    	stnSipStations[i]=new char[(RUFNR_SIZE*2)+1];
    }
    for(i=0;  i<numSipConfig+1; i++)
    {
    	stnSipConfig[i]=new char[(RUFNR_SIZE*2)+1];
    }
    /*-----------------------------------------------*/
    
    
    for(i=0; i<(numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic); i++)
    {
	stnNumber[i]=new char[(RUFNR_SIZE*2)+1];
	stnDuwa[i]=new char[(RUFNR_SIZE*2)+1];
	stnNode[i]=new char[(RUFNR_SIZE*2)+1];
	stnStType[i]=new char[(RUFNR_SIZE*2)+1];
	stnStTypeNode[i]=new char[(RUFNR_SIZE*2)+1];
	stnAccessAnalog[i] =new char[(RUFNR_SIZE*2)+1]; 
	stnAccessUP0[i] =new char[(RUFNR_SIZE*2)+1];
	stnVoicemail[i] =new char[(RUFNR_SIZE*2)+1];
	stnFaxCallno[i] =new char[(RUFNR_SIZE*2)+1];
	stnFaxDid[i] =new char[(RUFNR_SIZE*2)+1];
    }
    
    for(i=0; i<numLic; i++)
    {
        stnLicnum[i] = new char[(RUFNR_SIZE*2)+1];	
    }
    
   for(i=0; i<numStation*2; i++)
    {
    	stnAllStations[i]=new char[(RUFNR_SIZE*2)+1];
	    stnAllFaxes[i]=new char[(RUFNR_SIZE*2)+1];
    }
    
    for(i=0;i<(numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic);i++)
    {
	for(pos=0;pos<RUFNR_SIZE*2;pos++)
	{
		stnNumber[i][pos]='\0';
		stnDuwa[i][pos]='\0';
		stnNode[i][pos]='\0';
		stnStType[i][pos]='\0';
		stnStTypeNode[i][pos]='\0';
		stnAccessAnalog[i][pos]='\0';
		stnAccessUP0[i][pos]='\0';
		stnVoicemail[i][pos]='\0';
		stnFaxCallno[i][pos]='\0';
		stnFaxDid[i][pos]='\0';
	}
    }
    
    for(i=0;i<numLic;i++)
    {
	for(pos=0;pos<RUFNR_SIZE*2;pos++)
	{
		stnLicnum[i][pos]='\0';
	}
    }
    
    for(i=0; i<numStation*2; i++)
    {
	stnAllStations[i][pos]='\0';
	stnAllFaxes[i][pos]='\0';
    }
    
    
    for(i=0;i<(numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic);i++)
    {
	strcpy(stnNumber[i],"empty");
	strcpy(stnDuwa[i],"empty");
	strcpy(stnNode[i],"empty");
	strcpy(stnStType[i],"empty");	
	strcpy(stnStTypeNode[i],"empty");	 
	strcpy(stnAccessAnalog[i],"empty");	 
	strcpy(stnAccessUP0[i],"empty");
	strcpy(stnVoicemail[i],"empty");
	strcpy(stnFaxCallno[i],"empty");
	strcpy(stnFaxDid[i],"empty");		 
    }
    
    for(i=0; i<numStation*2; i++)
    {
	strcpy(stnAllStations[i],"");
	strcpy(stnAllFaxes[i],"");
    }
    
      //-------------------------CHECK THE NUMER OF RECORDS AND THE VALIDATION-------------------	
    
    // -- Prepei na mpoun edo kai Safe Conditions an Skasei        
    while(fgets ( line,128,fxml ) != NULL ) // read a line by line
    {
	
	tempstr=line; // this temp str contains the current line
	intLen = strlen(line);


	//---1-find----WorkSheet name ------------------------------
	wksFound= tempstr.find("Worksheet ss:Name");
	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
	        fFirst= tempstr.find("\"");
	        fLast=tempstr.find_last_of("\"");   
	        tempstr = tempstr.substr(fFirst+1,(fLast-(fFirst+1)));		

		if(tempstr == "Customer")
	   	   blStations = true;
		else if(tempstr =="Groups")		
		   blGroups = true;		    
		else if(tempstr =="Virtual")		
		   blVirtual = true;
		else if(tempstr =="Trunk Groups")
		   blTrunkGroup = true;		
		else if(tempstr =="Voicemail")	
		   blVoicemail = true;
		else if(tempstr == "SipConfig")
		  blSipConfig = true;
    	}// end worksheet search 

	//---2 find the End of WorkSheet-------------
	wksFound= tempstr.find("</Worksheet>");
	if ( wksFound > -1) // vrike to onoma tou Worksheet
	{		
		if(blStations)
		{
			blStations = false;
		}		
		else if(blGroups)
		{
			blGroups = false;
		}
		else if(blVirtual)
		{
			blVirtual = false;
		}
		else if(blTrunkGroup)
		{
			blTrunkGroup = false;
		}
		else if(blVoicemail)
		{
			blVoicemail = false;
		}
		else if(blSipConfig)
		{
		    blSipConfig = false;
		}
	}


	blEndRecord = false;

	wksFound = tempstr.find("</Data>");
	findNameCell = tempstr.find("<NamedCell");
	findCell = tempstr.find("</Cell>");
	wksRowFound =  tempstr.find("</Row>");
	fFiltDb = tempstr.find("FilterDatabase");


	//  CASE  A -- Check if the line is empty, has no data, only namedcell
	if((findNameCell > -1) && (wksFound == -1) && (fFiltDb==-1)   ) 
	{
		fLast = tempstr.find("</Cell>");
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		strData = "empty";
		blEndRecord = true;
	}
	// CASE B scenario we had Data and NameCell Filled in the Same Line 		
	else if( (wksFound > -1) && (findNameCell > -1)  && (findCell >-1) )
	{			
		fLast = tempstr.find("</Cell>");
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		fLast = wksFound;  //tempstr.find("</Data>");
		fFirst = tempstr.rfind("\">");
		strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));
		blEndRecord = true;
	}
	// CASE C -- Has Data and NameCell but the Cell END is in the next Line
	else if( (wksFound > -1) && (findNameCell > -1)  && (findCell == -1) )
	{
		fLast = wksFound;  //tempstr.find("</Data>");
		fFirst = tempstr.rfind("\">");
		strData = tempstr.substr(fFirst+2,(fLast-(fFirst+2)));
		if(strData.length() == 0 )
		    strData = "empty";
		blCellEnd = true; // wait the end of the Cell		
	}
	else if( (findCell > -1) &&  (blCellEnd)  ) // find the end of Cell
	{
		blCellEnd = false;
		//cell name
		fLast = tempstr.find("</Cell>"); 
		fLast = fLast -3;
		fFirst = tempstr.rfind("=\"");
		fFirst  = fFirst+2;
		strCell = tempstr.substr(fFirst,(fLast-fFirst));
		blEndRecord = true;	
	}
	else if(wksRowFound > -1)	
	{
		blEndRecord = true;
		strData = "</Row>";
		blEndRecord = true;
		strCell="";	
	}
	
	if(blEndRecord && blStations )
	   icurrentitem++;

	// If the Record is OK
	if(  blEndRecord  )// &&  icurrentitem>35)
	{
	
	
//--------------SIP CONFIG -----------------------------------------------
	
      if((blSipConfig)   &&  (numSipConfig > 0) )
      { 
		if ( ( strcmp(strCell.c_str(),xmlSipConfigTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlSipConfigTable[0].headerrecord)!= 0 )  )			
		{
			if (strData =="empty")
			{
				firstEmpty=true;
				blSipConfig = false;
			}
			else
			{
				firstEmpty=false;
				strcpy(stnSipConfig[icountSipConfig],strData.c_str());
				icountSipConfig++;							
			 }			  			
		}   
      }	
	
	
//-----------------------STATIONS------------------------------------------------------------------------------------------	    
	  

	    if((blStations)   &&  (numStation > 0) && (icurrentitem>35))
	    {
		//---- internal numbers------------------------------------------
		if ( ( strcmp(strCell.c_str(),xmlUsaElements[7].element) ==0 )  )  			
		{
			if (strData =="empty")
			{
				firstEmpty=true;
				blStations = false;
				
				if(findSixth  )
				{
				   stTypeNode_count--;		
				  node_count--;
				}
			}
			else
			{
				firstEmpty=false;
				strcpy(stnNumber[num_count],strData.c_str());
				cout << strData.c_str() << endl;
				num_count++;			
				findFirst=true;
				
				strcpy(stnAllStations[icountAllst],strData.c_str());
				icountAllst++;				
			 }
			  			
		}
		//-- DID duwa numbers 
		else if ( ( strcmp(strCell.c_str(),xmlUsaElements[8].element) ==0 )  &&  (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
					strcpy(stnDuwa[duwa_count],"-");
				else
				{
					if(  (strcmp(strData.c_str(),"x")==0) || (strcmp(strData.c_str(),"X")==0))	
					{
					   strcpy(stnDuwa[duwa_count],stnNumber[num_count-1]);
					   duwa_count++;
					  findSecond=true; 					
					  strcpy(stnAllStations[icountAllst],stnNumber[num_count-1]);
					  icountAllst++;
					}
					else
					{
					  strcpy(stnDuwa[duwa_count],strData.c_str());	
					  duwa_count++;
					  findSecond=true; 					
					  strcpy(stnAllStations[icountAllst],strData.c_str());
					  icountAllst++;
					}
					
					
				}
			}						
		}
		
		//------Station Type-----------------------------------
		else if ( ( strcmp(strCell.c_str(),xmlUsaElements[11].element) ==0 ) 	&& (firstEmpty==false) )			
		{						
			if(findFirst)
			{
				if( !strcmp(strData.c_str(),xmlDevType[0].name) )
				{
					stSipCounter++;
					// sip for sipconfig compare 
					strcpy(stnSipStations[icountSip],stnNumber[num_count-1]);	
					icountSip++;									
				}
				else if( !strcmp(strData.c_str(),xmlDevType[1].name) )
				{
					stSipFaxCounter++;
					// sip for sipconfig compare 
					strcpy(stnSipStations[icountSip],stnNumber[num_count-1]);	
					icountSip++;
				}
				else if( !strcmp(strData.c_str(),xmlDevType[2].name) )
				{
					stUp0Counter++;
				}
				else if( !strcmp(strData.c_str(),xmlDevType[3].name) )
				{
					stIpCounter++;
				}
				else if( !strcmp(strData.c_str(),xmlDevType[4].name) )
				{
					stRasCounter++;
				}
				else if( !strcmp(strData.c_str(),xmlDevType[5].name) )
				{
					stDeskCounter++;
				}
				else if( !strcmp(strData.c_str(),xmlDevType[6].name) )
				{
					stabFaxCounter++;
				}
				else if( !strcmp(strData.c_str(),xmlDevType[7].name) )
				{
					stabCounter++;
				}
				else if( !strcmp(strData.c_str(),xmlDevType[8].name) )
				{
					stIsdnCounter++;
				}
				else if( !strcmp(strData.c_str(),xmlDevType[9].name) )
				{
					stDectCounter++;
				}
				else if( !strcmp(strData.c_str(),xmlDevType[12].name) )
				{
					stabCounter++;
				}
				else if( !strcmp(strData.c_str(),xmlDevType[13].name) )
				{
					stIsdnCounter++;
				}
			
				findThird=true; 
				
				strcpy(stnStType[stType_count],strData.c_str());
				stType_count++;
			}						
		}		
		
		//CallPick Up Groupp
		else if ( ( strcmp(strCell.c_str(),xmlUsaElements[4].element) ==0 ) 	&& (firstEmpty==false) )			
		{
			if(findFirst  && icountCallPick<65)
			{
			    strcpy( stnCallPick[icountCallPick] , strData.c_str() );
			    icountCallPick++;
			}
			
						
		}
		
		//---------------Fax Callno  		 
		else if ( ( strcmp(strCell.c_str(),xmlUsaElements[16].element) ==0 )  && (firstEmpty==false) )			
		{
		        if(findFirst)
			{
				strcpy( stnFaxCallno[ifaxCallnoCount] , strData.c_str() );
				ifaxCallnoCount++;
				
				strcpy(stnAllFaxes[icountAllFax],strData.c_str());
				icountAllFax++;
				
				findFourth = true;
			}	
		}
		//---------------Fax DID
		else if ( ( strcmp(strCell.c_str(),xmlUsaElements[17].element) ==0 )  && (firstEmpty==false) )			
		{
		        if(findFirst)
			{
			  if(  (strcmp(strData.c_str(),"x")==0) || (strcmp(strData.c_str(),"X")==0))	
			  {	
				strcpy( stnFaxDid[ifaxDidCount] , stnFaxCallno[ifaxCallnoCount-1] );
				ifaxDidCount++;
				
				strcpy(stnAllFaxes[icountAllFax],stnFaxCallno[ifaxCallnoCount-1]);
				icountAllFax++;
				
				findFifth = true;
			  }
			  else
			  {
				strcpy( stnFaxDid[ifaxDidCount] , strData.c_str() );
				ifaxDidCount++;
				
				strcpy(stnAllFaxes[icountAllFax],strData.c_str());
				icountAllFax++;
				
				findFifth = true;
			  }
			}	
		}
		/*
		//---------------Class of service
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[7].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[7].headerrecord)!= 0 )	&& (firstEmpty==false) )			
		{
		}
		
		//---------------Call pickup
		else if ( ( strcmp(strCell.c_str(),xmlStationsNameTable[8].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlStationsNameTable[8].headerrecord)!= 0 )	&& (firstEmpty==false) )			
		{
		}
		
		*/
		// --------------ACCESS----------------------------
		else if ( ( strcmp(strCell.c_str(),xmlUsaElements[28].element) ==0 )  &&  (firstEmpty==false) )			
		{
			if(findFirst)
			{
				int k =  num_count-1;
				string str_k ="";
				//sprintf(str_k.c_str(),"%d",k);
				

				if( strcmp( stnStType[stType_count-1] , xmlStationTypes[2].name ) == 0 ) // UP0
				{
					strcpy( stnAccessUP0[countAccessUP0], strData.c_str()) ;
					strcat( stnAccessUP0[countAccessUP0], "," );
					strcat( stnAccessUP0[countAccessUP0] , str_k.c_str() );
					countAccessUP0++;
				}
				else if ( (strcmp( stnStType[stType_count-1] , xmlStationTypes[7].name ) == 0)   ||   (strcmp( stnStType[stType_count-1] , xmlStationTypes[6].name ) == 0) ) // Analog -Analog Fax
				{								        	
					strcpy( stnAccessAnalog[countAccessAnalog] ,  strData.c_str());					
					strcat( stnAccessAnalog[countAccessAnalog] , ",");
					strcat( stnAccessAnalog[countAccessAnalog] , str_k.c_str() );
					countAccessAnalog++;
				}
			}						

		}
		//--VoiceMail
		else if ( ( strcmp(strCell.c_str(),xmlUsaElements[12].element) ==0 ) && (firstEmpty==false) )			
		{
			if(findFirst)
			{
				strcpy( stnVoicemail[num_count-1] , strData.c_str() );
			}						

		}
		
		//---Email Address
		//---Mobile number
		
		//---NODE ID 		
		
		else if ( ( strcmp(strCell.c_str(),xmlUsaElements[0].element) ==0 )     )			
		{			
				
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
				{
  				  //strcpy(stnNode[node_count],"0");
					if(node_count <  numStation)
					{
					curNodeAtoi == kdsretNode.inhalt[3] ;
				  string snd="";
				  snd = curNodeAtoi;
				  strcpy(stnNode[node_count],snd.c_str());
				  sprintf(stnNode[node_count],"  %d ",kdsretNode.inhalt[3]);	
				  
				  printf("\n ilias  stnNode[%i]= %s",  node_count , stnNode[node_count]);


				  
				strcpy(stnStTypeNode[stTypeNode_count] ,stnNode[node_count]);
				stTypeNode_count++;
				
				
				
				node_count++;
				findSixth=true; 

					}
				  
				}
				else
				{

				   if(node_count <  numStation)
					{
					strcpy(stnNode[node_count],strData.c_str());
				   printf("\n ilias  stnNode[%i]= %s",  node_count , stnNode[node_count]);


				   
				strcpy(stnStTypeNode[stTypeNode_count] ,stnNode[node_count]);
				stTypeNode_count++;
				
				
				
				node_count++;
				findSixth=true; 

				   }
				}
			
				

			
						
			
		}

		else if( strcmp(strData.c_str(),"</Row>")  == 0  )
		{
		
			if(findFirst)
			{						
				if(!findSecond) // DUWA DID
				{
					strcpy(stnDuwa[duwa_count],"");
					duwa_count++;
				}
				
				if(!findSixth)// NODE 
				{
					/*
					strcpy(stnNode[node_count],"0");
					node_count++;
					*/
					//strcpy(stnNode[node_count],"0");
				  curNodeAtoi == kdsretNode.inhalt[3] ;
				  string snd="";
				  snd = curNodeAtoi;
				  strcpy(stnNode[node_count],snd.c_str());
				  sprintf(stnNode[node_count],"  %d ",kdsretNode.inhalt[3]);	
					
				}
				
				
				if(!findFourth) // fax callno
				{
					strcpy( stnFaxCallno[ifaxCallnoCount] , "empty");
					ifaxCallnoCount++;

					strcpy( stnAllFaxes[icountAllFax] , "empty" );
					icountAllFax++;
					
				}
				if(!findFifth) // fax did
				{
					strcpy( stnFaxDid[ifaxDidCount] ,  "empty"  );
					ifaxDidCount++;
					
					strcpy( stnAllFaxes[icountAllFax] ,  "empty"  );
					icountAllFax++;
				}
				
				
				
				findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
			
			}
			
			findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
			
		}
		
		numberoflines++;
	      }//  END BLSTATION 
//-----------------------END STATIONS------------------------------------------------------------------------------------------	    
//------------------------LICENSES-----------------------------------------------------------------------------------------------
	      else if((blLicenses)  && (numLic > 0) )
	      {
		
		if ( ( strcmp(strCell.c_str(),xmlLicensesNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[0].headerrecord)!= 0 )  )			
		{
			if (strData =="empty")
			{
				firstEmpty=true;
				blLicenses = false;

			}
			else
			{
				firstEmpty=false;
				strcpy(stnLicnum[lic_count],strData.c_str());
				lic_count++;
				
				findFirst=true; 
			 }
		}
		
		//---NODE ID 
		else if ( ( strcmp(strCell.c_str(),xmlLicensesNameTable[12].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlLicensesNameTable[12].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{									
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
  				  strcpy(stnNode[node_count],"0");
				else	
				  strcpy(stnNode[node_count],strData.c_str());
				node_count++;
			
				findSecond=true; 
			}
		}
		else if( strcmp(strData.c_str(),"</Row>")  == 0  )
		{
		
			if(findFirst)
			{						
				if(!findSecond)// NODE 
				{
					strcpy(stnNode[node_count],"0");
					node_count++;
				}
	
		 	}
			findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
		}		
		
		
	      
	      }// END LICENSES	      	
//-----------------------------GROUPS---------------------------------------------------------------------------------------------------	      
	      else if((blGroups)  && (numGroup > 0) )
	      {
							
		
		if ( ( strcmp(strCell.c_str(),xmlGroupsNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[0].headerrecord)!= 0 )  )			
		{			
			//if (strData =="empty")
			if ( strcmp(strData.c_str(),"empty") == 0 ) 
			{
				firstEmpty=true;
				blGroups = false;
			}
			else
			{
				firstEmpty=false;
				strcpy(stnNumber[num_count],strData.c_str());				
				num_count++;
				
				findFirst=true; 
			 }			
		}
		//-- DID duwa numbers 
		else if ( ( strcmp(strCell.c_str(),xmlGroupsNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[1].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
					strcpy(stnDuwa[duwa_count],"-");
				else
					   strcpy(stnDuwa[duwa_count],strData.c_str());
			
				duwa_count++;
				findSecond=true; 
			}
			
		}
		// Voicemail
		else if ( ( strcmp(strCell.c_str(),xmlGroupsNameTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[3].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{

			if(findFirst)
			{
				strcpy( stnVoicemail[num_count-1] , strData.c_str() );
			}						
		}
		
		//---NODE ID 
		else if ( ( strcmp(strCell.c_str(),xmlGroupsNameTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlGroupsNameTable[4].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
  				  strcpy(stnNode[node_count],"0");
				else	
				strcpy(stnNode[node_count],strData.c_str());
			
				node_count++;
			
				if ( (strData.length() ==0) || (strData=="empty") )
				   curNode = 0;
				else			
				   curNode = atoi(strData.c_str());						
						
				/*
				if(curNode == 0)		
				{
					countNodeGroups++;			
					if( countNodeGroups >22)
					{
						   faults[0][0]++;
			      			   faults[faultrow][0]=3;
			   			   faults[faultrow][1]=num_count - numStation-numGroup+ 2;
						   faults[faultrow][2]=22;
						   faultrow++;	
					   }
				   }
				   */
				   findThird=true; 
			}
						
		}
		else if( strcmp(strData.c_str(),"</Row>")  == 0  )
		{
		
			if(findFirst)
			{						
				if(!findSecond) // DUWA DID
				{
					strcpy(stnDuwa[duwa_count],"");
					duwa_count++;
				}
				if(!findThird)// NODE 
				{
					strcpy(stnNode[node_count],"0");
					node_count++;
				}							
			}

		 	findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
		}	
		

		numberoflines++;
	      
	      }	      
//---------------------------VIRTUALS-------------------------------------------------------------------------------------------------------	      
	      else if((blVirtual)  &&  (numVirtual>0) )
	      {
	      	
		if ( ( strcmp(strCell.c_str(),xmlVirtualNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[0].headerrecord)!= 0 )  )			
		{			
			if ( strcmp(strData.c_str(),"empty") == 0 ) 
			{
				firstEmpty=true;
				blVirtual = false;
			}
			else
			{
				firstEmpty=false;
				strcpy(stnNumber[num_count],strData.c_str());
				num_count++;
				findFirst=true; 
			 }			
		}
		//-- DID duwa numbers 
		else if ( ( strcmp(strCell.c_str(),xmlVirtualNameTable[1].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[1].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
					strcpy(stnDuwa[duwa_count],"");
				else
					strcpy(stnDuwa[duwa_count],strData.c_str());
				duwa_count++;
				findSecond=true; 
			}
		}
		
		//------Station Type-----------------------------------
		else if ( ( strcmp(strCell.c_str(),xmlVirtualNameTable[3].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[3].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if( !strcmp(strData.c_str(),xmlVirtualStationTypes[0].name) )
				{
					syscountAutoAt++;
				}
				else if( !strcmp(strData.c_str(),xmlVirtualStationTypes[1].name) )
				{
					syscountCCFax++;
				}
				else if( !strcmp(strData.c_str(),xmlVirtualStationTypes[2].name) )
				{
					syscountPark++;
				}
				else if( !strcmp(strData.c_str(),xmlVirtualStationTypes[3].name) )
				{
					syscountConf++;
				}									
				else if( !strcmp(strData.c_str(),xmlVirtualStationTypes[4].name) )
				{
					sysCountFaxGroup++;
				}	
				else if( !strcmp(strData.c_str(),xmlVirtualStationTypes[5].name) )
				{
					sysCountVirtual++;
				}
				else if( !strcmp(strData.c_str(),xmlVirtualStationTypes[6].name) )
				{
					sysCountMeetMe++;
				}
				strcpy(stnStType[stType_count],strData.c_str());
				stType_count++;
			}
		}
		//---NODE ID 
		else if ( ( strcmp(strCell.c_str(),xmlVirtualNameTable[4].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVirtualNameTable[4].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
  				  strcpy(stnNode[node_count],"0");
				else	
				strcpy(stnNode[node_count],strData.c_str());	
				strcpy(stnStTypeNode[stTypeNode_count] ,stnNode[node_count]);
				stTypeNode_count++;


				node_count++;	
				findThird=true; 
			}
		}
		//---Secondary Gateway
		
		else if( strcmp(strData.c_str(),"</Row>")  == 0  )
		{
		
			if(findFirst)
			{						
				if(!findSecond) // DUWA DID
				{
					strcpy(stnDuwa[duwa_count],"");
					duwa_count++;
				}
				if(!findThird)// NODE 
				{
					strcpy(stnNode[node_count],"0");
					node_count++;
				}
			}
		 	findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
		}		

		numberoflines++;
	      
	      }//END VIRTUAL
      
//---------------------------TRUNKS-------------------------------------------------------------------------------------------------------	        	      	      
	      else if((blTrunkGroup) && (numTrnk>0))
	      {
		if ( ( strcmp(strCell.c_str(),xmlTrunkGrpNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlTrunkGrpNameTable[0].headerrecord)!= 0 )  )			
		{			
			if ( strcmp(strData.c_str(),"empty") == 0 ) 
			{
				firstEmpty=true;
				blTrunkGroup = false;
			}
			else
			{
				firstEmpty=false;
				strcpy(stnNumber[num_count],strData.c_str());				
				num_count++;
				findFirst=true; 
			 }			
		}
		//---NODE ID 
		else if ( ( strcmp(strCell.c_str(),xmlTrunkGrpNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlTrunkGrpNameTable[2].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
  				  strcpy(stnNode[node_count],"0");
				else				
				strcpy(stnNode[node_count],strData.c_str());
			
				node_count++;
			
				if ( (strData.length() ==0) || (strData=="empty") )
				   curNode = 0;
				else			
				   curNode = atoi(strData.c_str());
			
		
				if(curNode == kdsretNode.inhalt[3] )
				{
					countNodeTrunksGr++;			
					if(countNodeTrunksGr >10)
					{
						   faults[0][0]++;
			      			   faults[faultrow][0]=5;
		   				   faults[faultrow][1]=num_count - numStation-numGroup-numVirtual+ 2;
						   faults[faultrow][2]=TOO_MANY_TRUNK;
						   faultrow++;
	  					//blTrunkGroup = false;
					}
				}
				findSecond=true;
			}
							
		}
		else if( strcmp(strData.c_str(),"</Row>")  == 0  )
		{
		
			if(findFirst)
			{						
				if(!findSecond)// NODE 
				{
					strcpy(stnNode[node_count],"0");
					node_count++;
				}
						
			}
		 	findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
		}	

		numberoflines++;

	      }
//---------------------------VOICEMAIL-------------------------------------------------------------------------------------------------------	      	      
	      else if((blVoicemail) && (numVoicemail>0) )
	      {
		
      		if ( ( strcmp(strCell.c_str(),xmlVoiceMailNameTable[0].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVoiceMailNameTable[0].headerrecord)!= 0 )  )			
		{			
			if ( strcmp(strData.c_str(),"empty") == 0 ) 
			{
				firstEmpty=true;
				blVoicemail = false;
			}
			else
			{
				firstEmpty=false;
				strcpy(stnNumber[num_count],strData.c_str());
				num_count++;
				findFirst=true; 
			 }			
		}
		//---NODE ID 
		else if ( ( strcmp(strCell.c_str(),xmlVoiceMailNameTable[2].namedcell) ==0 )  &&  ( strcmp(strData.c_str(), xmlVoiceMailNameTable[2].headerrecord)!= 0 )
		&& (firstEmpty==false) )			
		{			
			
			if(findFirst)
			{
				if( (strcmp(strData.c_str(),"empty") ==0) || (strcmp(strData.c_str(),"-") ==0) )
  				  strcpy(stnNode[node_count],"0");
				else	
				strcpy(stnNode[node_count],strData.c_str());

				node_count++;			
			
				if ( (strData.length() ==0) || (strData=="empty") )
				   curNode = 0;
				else			
				   curNode = atoi(strData.c_str());						
						
				if(curNode == 0)		
				{
					countNodeVoicemail++;			
					if( countNodeVoicemail >1)
					{
						faults[0][0]++;
			      			   faults[faultrow][0]=6;
			   			   faults[faultrow][1]=num_count - numStation-numGroup-numVirtual-numTrnk+ 2;
						   faults[faultrow][2]=TOO_MANY_VOICEMAIL;
						   faultrow++;	
					   }
				   }
				   findSecond=true; 
			}
			
		}
		else if( strcmp(strData.c_str(),"</Row>")  == 0  )
		{
		
			if(findFirst)
			{						
				if(!findSecond)// NODE 
				{
					strcpy(stnNode[node_count],"0");
					node_count++;
				}
			}
		 	findFirst=false; findSecond=false; findThird=false; findFourth=false; findFifth=false; findSixth=false; findSeventh=false; findEighth=false; findNinth=false; findTenth=false; findEleventh=false; findTwelvth=false;
		}	
		
		numberoflines++;
	      } // END VOICE MAIL
	      	
	} //end If blEndRecord
		
	countLine++;//increase countLines number to numberring Lines   
	
    }// ----end while read lines-------

    fclose(fxml);
            
    for(i=0; i<20; i++)
    	{
           dublicatepos[i]=0;	
    	}		
	//-------------------Check Double Records In INTERNAL NUMBERS -------------------------------------------
	// Check the Duplicates Numbers in Internal Numbers
	if(num_count > 0)
	{
		if(!checkdouble(stnNumber,num_count,dublicatepos))
		{
			for(i=0;i<20;i++)
			{
				if(faultrow!=21 && dublicatepos[i])
				{
				//numStation+numGroup+numVirtual+numTrnk+numVoicemail
					faults[0][0]++;								
					if (dublicatepos[i] <= numStation)
					{
					   faults[faultrow][0]=1;
					   faults[faultrow][1]=dublicatepos[i]+2;
					}
					else if( (dublicatepos[i] > numStation) && (dublicatepos[i] <= (numStation+numGroup) )  )
					{
					   faults[faultrow][0]=3;
					   faults[faultrow][1]=dublicatepos[i]-numStation+2;
					}
					else if(  (dublicatepos[i] > (numStation+numGroup) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual) ))  
					{
	 					faults[faultrow][0]=4;	
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup+ 2;									
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk) ))  
					{
	 					faults[faultrow][0]=5;						
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual+ 2;														
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual+numTrnk) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk+numVoicemail) ))  
					{
 						faults[faultrow][0]=6;		
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual-numTrnk+ 2;			
					}
					faults[faultrow][2]=CALL_NO_NOT_UNIQUE;
					faultrow++;	
				}
			}
		}
	}
    	
	
	/* Check doubledigits */
	if(num_count > 0)
	{
		if(!checkdoubledigits(stnNumber,num_count,dublicatepos))
		{
			for(i=0;i<20;i++)
			{
				if(faultrow!=21 && dublicatepos[i])
				{
				//numStation+numGroup+numVirtual+numTrnk+numVoicemail
					faults[0][0]++;								
					if (dublicatepos[i] <= numStation)
					{
					   faults[faultrow][0]=1;
					   faults[faultrow][1]=dublicatepos[i]+2;
					}
					else if( (dublicatepos[i] > numStation) && (dublicatepos[i] <= (numStation+numGroup) )  )
					{
					   faults[faultrow][0]=3;
					   faults[faultrow][1]=dublicatepos[i]-numStation+2;
					}
					else if(  (dublicatepos[i] > (numStation+numGroup) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual) ))  
					{
	 					faults[faultrow][0]=4;	
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup+ 2;									
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk) ))  
					{
	 					faults[faultrow][0]=5;						
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual+ 2;														
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual+numTrnk) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk+numVoicemail) ))  
					{
 						faults[faultrow][0]=6;		
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual-numTrnk+ 2;			
					}
					faults[faultrow][2]=CALL_NO_NOT_UNIQUE;
					faultrow++;	
				}
			}
		}
	}
    	for(i=0;i<20;i++)
    	{
           dublicatepos[i]=0;	
    	}	
		
	//-------------------Check Double Records In DID Numbers -------------------------------------------
	// Check the Did Numbers  for Doule records 
	if(duwa_count > 0)
	{
		if(!checkdouble(stnDuwa,duwa_count,dublicatepos))
		{
				for(i=0;i<20;i++)
				{
					if(faultrow!=21 && dublicatepos[i])
					{				
					//numStation+numGroup+numVirtual+numTrnk+numVoicemail	
					faults[0][0]++;								
					if (dublicatepos[i] <= numStation)
					{
					   faults[faultrow][0]=1;
					   faults[faultrow][1]=dublicatepos[i]+2;
					}
					else if( (dublicatepos[i] > numStation) && (dublicatepos[i] <= (numStation+numGroup) )  )
					{
					   faults[faultrow][0]=3;
					   faults[faultrow][1]=dublicatepos[i]-numStation+2;
					}
					else if(  (dublicatepos[i] > (numStation+numGroup) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual) ))  
					{
	 					faults[faultrow][0]=4;	
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup+ 2;									
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk) ))  
					{
	 					faults[faultrow][0]=5;					
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual+ 2;														
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual+numTrnk) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk+numVoicemail) ))  
					{
	 					faults[faultrow][0]=6;		
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual-numTrnk+ 2;			
					}
					faults[faultrow][2]=DUWA_NOT_UNIQUE;
					faultrow++;
				}
			}
		}
	}


	
	// Check the Did digits  for Doule 
	if(duwa_count > 0)
	{
		if(!checkdoubledigits(stnDuwa,duwa_count,dublicatepos))
		{
				for(i=0;i<20;i++)
				{
					if(faultrow!=21 && dublicatepos[i])
					{				
					//numStation+numGroup+numVirtual+numTrnk+numVoicemail	
					faults[0][0]++;								
					if (dublicatepos[i] <= numStation)
					{
					   faults[faultrow][0]=1;
					   faults[faultrow][1]=dublicatepos[i]+2;
					}
					else if( (dublicatepos[i] > numStation) && (dublicatepos[i] <= (numStation+numGroup) )  )
					{
					   faults[faultrow][0]=3;
					   faults[faultrow][1]=dublicatepos[i]-numStation+2;
					}
					else if(  (dublicatepos[i] > (numStation+numGroup) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual) ))  
					{
	 					faults[faultrow][0]=4;	
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup+ 2;									
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk) ))  
					{
	 					faults[faultrow][0]=5;					
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual+ 2;														
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual+numTrnk) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk+numVoicemail) ))  
					{
	 					faults[faultrow][0]=6;		
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual-numTrnk+ 2;			
					}
					faults[faultrow][2]=DUWA_NOT_UNIQUE;
					faultrow++;
				}
			}
		}
	}	
	//------------sipConfig check double -------------------------
	for(i=0;i<20;i++)
    	{
           dublicatepos[i]=0;	
    	}
	// Check the Did digits  for Doule 
	if(icountSipConfig > 0)
	{
		if(!checkdoubledigits(stnSipConfig,icountSipConfig,dublicatepos))
		{
				for(i=0;i<20;i++)
				{
					if(faultrow!=21 && dublicatepos[i])
					{				
						
					faults[0][0]++;								
					if (dublicatepos[i] <= icountSipConfig)
					{
					   faults[faultrow][0]=7;/* tab index for sipconfig */
					   faults[faultrow][1]=dublicatepos[i]+2;
					}					
					faults[faultrow][2]=CALL_NO_NOT_UNIQUE; /*new error definition */
					faultrow++;
				}
			}
		}
	}

	for(i=0;i<20;i++)
    	{
           dublicatepos[i]=0;	
    	}
	
	//------------Check Node Type If is valid or Mixed Up----------------------
	if(node_count > 0 )
	{
		if(!checkNodeType(stnNode,node_count,dublicatepos))
		{
		        for(i=0;i<20;i++)
			{
			 if(faultrow!=21 && dublicatepos[i])
			 {
				//numStation+numGroup+numVirtual+numTrnk+numVoicemail
				faults[0][0]++;								
				if (dublicatepos[i] <= numStation)
				{
				   faults[faultrow][0]=1;
				   faults[faultrow][1]=dublicatepos[i]+2;
					}
					else if( (dublicatepos[i] > numStation) && (dublicatepos[i] <= (numStation+numGroup) )  )
					{
					   faults[faultrow][0]=3;
					   faults[faultrow][1]=dublicatepos[i]-numStation+2;
					}
					else if(  (dublicatepos[i] > (numStation+numGroup) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual) ))  
					{
	 					faults[faultrow][0]=4;	
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup+ 2;									
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk) ))  
					{
 						faults[faultrow][0]=5;					
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual+ 2;														
					}
					else if(  (dublicatepos[i] > (numStation+numGroup+numVirtual+numTrnk) )  &&    (dublicatepos[i] <= (numStation+numGroup+numVirtual+numTrnk+numVoicemail) ))  
					{
	 					faults[faultrow][0]=6;		
						faults[faultrow][1]=dublicatepos[i]- numStation-numGroup-numVirtual-numTrnk+ 2;			
					}
					faults[faultrow][2]=NODE_ID_MIXUP;
					faultrow++;
					
				}
			}
		}
	}
	


       bool fre =   checkVoicemailNumbers( stnVoicemail, stnNode, num_count);
       if (!fre)
       {
       		faults[0][0]++;		 						
		faults[faultrow][0]=1;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANYVOICEMAIL_EVM;// ENUM 68 wrong format all filled or all empty
		faultrow++;	
       }
    
    
    if(num_count > 0)
 {
       bool blCheckAccResult=false;
       
       	for(i=0;i<20;i++)
    	{
           dublicatepos[i]=0;	
    	}	
              
     if(countAccessAnalog > 0)
     {
       // -----------------Analog--------------------Check if All the Analog have Filled or Empty ------------------------------------------------------
       blCheckAccResult = checkAccessType(stnAccessAnalog, countAccessAnalog,dublicatepos,0,0); // Check Analog  Format Access Type
       if(!blCheckAccResult)
       {
	       for(i =0; i<20; i++)
	       {
			if(faultrow!=21 && dublicatepos[i])
			{
				faults[0][0]++;								
				faults[faultrow][0]=1;
				faults[faultrow][1]=dublicatepos[i]+3;								
				faults[faultrow][2]=WRONG_ACCESS_TYPE; // ENUM 66 wrong format all filled or all empty
				faultrow++;	
			}
		}
	}
       if(blCheckAccResult) 
       {
	       checkAccessType(stnAccessAnalog, countAccessAnalog,dublicatepos,0,1); // Check Analog  Slots
	       for(i =0; i<20; i++)
	       {
			if(faultrow!=21 && dublicatepos[i])
			{
				faults[0][0]++;								
				faults[faultrow][0]=1;
				faults[faultrow][1]=dublicatepos[i]+3;								
				faults[faultrow][2]=NO_ANALOG_SLOT; //  63 enum
				faultrow++;	
			}

       		}

	}
     }
	for(i=0;i<20;i++)
    	{
           dublicatepos[i]=0;	
    	}	

       //-----------------------UP0---------------------------- Check if All the UP0 have Filled or Empty --------------------------------------------------
      if(countAccessUP0 > 0 )
      {
        blCheckAccResult = checkAccessType(stnAccessUP0, countAccessUP0,dublicatepos,1,0); // Check UP0  Access Type Format 
       if(!blCheckAccResult)
       {
	       for(i =0; i<20; i++)
	       {
			if(faultrow!=21 && dublicatepos[i])
			{
				faults[0][0]++;								
				faults[faultrow][0]=1;
				faults[faultrow][1]=dublicatepos[i]+3;								
				faults[faultrow][2]=WRONG_ACCESS_TYPE; // ENUM 65 wrong format all filled or all empty
				faultrow++;	
			}
		}
       }

       if(blCheckAccResult)
       {      
	       checkAccessType(stnAccessUP0, countAccessUP0,dublicatepos,1,1); // Check UP0 Slot exists
	       for(i =0; i<20; i++)
	       {
			if(faultrow!=21 && dublicatepos[i])
			{
				faults[0][0]++;								
				faults[faultrow][0]=1;
				faults[faultrow][1]=dublicatepos[i]+3;								
				faults[faultrow][2]=NO_UP0_SLOT; //  64 enum	
				faultrow++;	
			}
	
	       }
	}
     }//if(countAccessUP0 > 0 )
     
     if((icountCallPick > 0)  &&  (icountCallPick <65) )
     {       
	      if(!checkdouble(stnCallPick,icountCallPick,dublicatepos))
		{
			for(i=0;i<20;i++)
			{
				if(faultrow!=21 && dublicatepos[i])
				{
				//numStation+numGroup+numVirtual+numTrnk+numVoicemail
					faults[0][0]++;								
				        faults[faultrow][0]=1;
					faults[faultrow][1]=dublicatepos[i]+2;				
					faults[faultrow][2]=11;
				        faultrow++;			
				}
			}
		}
     }
       
     /*----------------------------Faxes Checks--------------------------------------------------------*/
	
	if(ifaxCallnoCount > 0)
	{
		if(!checkdouble(stnFaxCallno,ifaxCallnoCount,dublicatepos))
		{
			for(i=0;i<20;i++)
			{
				if(faultrow!=21 && dublicatepos[i])
				{
				//numStation+numGroup+numVirtual+numTrnk+numVoicemail
					faults[0][0]++;								
				        faults[faultrow][0]=1;
					faults[faultrow][1]=dublicatepos[i]+2;				
					faults[faultrow][2]=FAX_CALL_NOT_UNIQUE;
				        faultrow++;			
				}
			}
		}
		
		if(!checkdoubledigits(stnFaxCallno,ifaxCallnoCount,dublicatepos))
		{
			for(i=0;i<20;i++)
			{
				if(faultrow!=21 && dublicatepos[i])
				{
				//numStation+numGroup+numVirtual+numTrnk+numVoicemail
					faults[0][0]++;								
				        faults[faultrow][0]=1;
					faults[faultrow][1]=dublicatepos[i]+2;				
					faults[faultrow][2]=FAX_CALL_NOT_UNIQUE;
				        faultrow++;			
				}
			}
		}

		
	}

	if(ifaxDidCount > 0)
	{
		if(!checkdouble(stnFaxDid,ifaxDidCount,dublicatepos))
		{
			for(i=0;i<20;i++)
			{
				if(faultrow!=21 && dublicatepos[i])
				{
					faults[0][0]++;								
				        faults[faultrow][0]=1;
					faults[faultrow][1]=dublicatepos[i]+2;				
					faults[faultrow][2]=FAX_DID_NOT_UNIQUE;
				        faultrow++;			
				}
			}
		}
		if(!checkdoubledigits(stnFaxDid,ifaxDidCount,dublicatepos))
		{
			for(i=0;i<20;i++)
			{
				if(faultrow!=21 && dublicatepos[i])
				{
					faults[0][0]++;								
				        faults[faultrow][0]=1;
					faults[faultrow][1]=dublicatepos[i]+2;				
					faults[faultrow][2]=FAX_DID_NOT_UNIQUE;
				        faultrow++;			
				}
			}
		}
	}		
	  
	if(!checkFaxDuplicate(stnAllStations,stnFaxCallno,icountAllst, ifaxCallnoCount,dublicatepos))
	{
		for(i=0;i<20;i++)
		{
			if(faultrow!=21 && dublicatepos[i])
			{
				//numStation+numGroup+numVirtual+numTrnk+numVoicemail
				faults[0][0]++;								
				faults[faultrow][0]=1;
				faults[faultrow][1]=dublicatepos[i]+2;								
				faults[faultrow][2]= FAX_CALL_NOT_UNIQUE; 
				faultrow++;	
			}
		}			
	}
		
	
     
	     		
	if(ifaxDidCount>0)
	{
		if(!checkFaxDuplicate(stnAllStations,stnFaxDid,icountAllst, ifaxDidCount,dublicatepos))
		{
			for(i=0;i<20;i++)
				{
				if(faultrow!=21 && dublicatepos[i])
				{
					//numStation+numGroup+numVirtual+numTrnk+numVoicemail
					faults[0][0]++;								
					faults[faultrow][0]=1;
					faults[faultrow][1]=dublicatepos[i]+2;								
					faults[faultrow][2]= FAX_DID_NOT_UNIQUE; // ENUM 42
					faultrow++;	
				}
			}	
		
		}
	}
	
	
	if(ifaxDidCount>0)
	{
		if(!checkFaxDuplicate(stnAllStations,stnFaxDid,icountAllst, ifaxDidCount,dublicatepos))
		{
			for(i=0;i<20;i++)
				{
				if(faultrow!=21 && dublicatepos[i])
				{					
					faults[0][0]++;								
					faults[faultrow][0]=1;
					faults[faultrow][1]=dublicatepos[i]+2;								
					faults[faultrow][2]= FAX_DID_NOT_UNIQUE; // ENUM 42
					faultrow++;	
				}
			}	
		
		}
	}

	if(icountSipConfig > 0)
	{
	
		if(!checkSipConfigInStations(stnSipStations,stnSipConfig,icountSip,icountSipConfig, dublicatepos))
		{
			for(i=0;i<20;i++)
				{
				if(faultrow!=21 && dublicatepos[i])
				{					
					faults[0][0]++;								
					faults[faultrow][0]=7; // tabshett SIpConfig
					faults[faultrow][1]=dublicatepos[i]+2;								
					faults[faultrow][2]= SIP_NOT_EXIST; // new enum duplicate SipConfig
					faultrow++;	
				}
			}	
		
		}
	
	}

 
 }
 
 if(blisBooster)
 {
 

 
 LXsumNodeStationsType(stnStType,stnStTypeNode, stType_count , stSipCounter, stIpCounter, stDeskCounter, syscountAutoAt, syscountCCFax, syscountPark, syscountConf ,sysCountFaxGroup , sysCountVirtual,stRasAdminCounter, stRasLicCounter,sysCountMeetMe);


  
  isumNodeStVir = stSipCounter+stUp0Counter+stIpCounter+stRasCounter+stDeskCounter+stabCounter+stIsdnCounter+stDectCounter+syscountAutoAt+syscountCCFax+syscountPark+syscountConf+sysCountFaxGroup+sysCountVirtual+sysCountMeetMe;
   
   if(!stIpCounter)
   {
	if(faultrow!=21)
	{
		faults[0][0]++;
		faults[faultrow][0]=1;	
		faults[faultrow][1]=1;	
		faults[faultrow][2]=IP_CLIENT_MISSING;  
		faultrow++;	
	}
   }

   if(ifaxCallnoCount>AMOUNT_OF_VP_FAX   ||  ifaxDidCount>AMOUNT_OF_VP_FAX )
   {
   
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=1;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_FAXES;
		faultrow++;			   	
	}
   }
   
   
   if( isumNodeStVir > NUM_OF_LOG_TLN_PORT )
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=1;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_STATIONS;
		faultrow++;			   	
	}
    }
  
   if(  stDeskCounter >  AMOUNT_OF_IP_PORTS_V2_S) 
   {
	if(faultrow!=21)
	{
		faults[0][0]++;
		faults[faultrow][0]=1;	
		faults[faultrow][1]=999;	
		faults[faultrow][2]= TOO_MANY_DESK;/*48*/  
		faultrow++;	
	}
   }
    
   
   if( stIpCounter > AMOUNT_OF_IP_PORTS_V2_S)
   {
	if(faultrow!=21)
	{
		faults[0][0]++;
		faults[faultrow][0]=1;	
		faults[faultrow][1]=999;	
		faults[faultrow][2]=TOO_MANY_IP;  
		faultrow++;	
	}
   }
   
   
   if( stSipCounter > AMOUNT_OF_IP_PORTS_V2_S )
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=1;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_SIP;
		faultrow++;	
	}
   }

   if( syscountAutoAt > AMOUNT_OF_VP_AUTO_ATTENDANT )
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=4;
		faults[faultrow][1]=999;								
		faults[faultrow][2]= TOO_MANY_VP_AUTO_ATTENDANT; 
		faultrow++;	
	}
   
   }
   if( syscountCCFax > AMOUNT_OF_VP_CALL_CENTER_FAX )
   {	
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=4;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_VP_AUTO_ATTENDANT; 
		faultrow++;
	}
   }
   
   if( syscountConf > AMOUNT_OF_CONFERENCE_ROOMS )
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=4;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_OSO_CONFERENCE; 
		faultrow++;	
	}
   }

   if( syscountPark > AMOUNT_OF_PARK_POSITION )
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=4;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_PARK;
		faultrow++;			   	
	}
   }
   

   if( sysCountFaxGroup > AMOUNT_OF_VP_FAX_GROUPS )
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=4;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_FAXGROUPS;
		faultrow++;			   	
	}
   }
   
   
   if(sysCountMeetMe  > AMOUNT_OF_VP_MEETME) 
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=1;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_MEET_ME;
		faultrow++;			   	
	}         
   }

 
 }
  
  else // if system is embedded  X1/3/5/8
  {
 
 if(!blX1)
   checkNumberOfStations(syscountUp0,syscountAn,syscountDect,syscountIsdn);/*  Count he Number Of System Available Stations Ports*/
   

   
   
   sumNodeStationsType(stnStType,stnStTypeNode, stType_count , stSipCounter, stUp0Counter, stIpCounter, stRasCounter, stDeskCounter, stabCounter, stIsdnCounter, stDectCounter,syscountAutoAt, syscountCCFax, syscountPark, syscountConf ,sysCountFaxGroup , sysCountVirtual,stRasAdminCounter, stRasLicCounter,sysCountMeetMe);

  
  isumNodeStVir = stSipCounter+stUp0Counter+stIpCounter+stRasCounter+stDeskCounter+stabCounter+stIsdnCounter+stDectCounter+syscountAutoAt+syscountCCFax+syscountPark+syscountConf+sysCountFaxGroup+sysCountVirtual+sysCountMeetMe;

    
   if (blX1)	
   {   
     
     
     if(stSipCounter  > AMOUNT_IP_X1  )
     {
	faults[0][0]++;								
	faults[faultrow][0]=1;
	faults[faultrow][1]=999;								
	faults[faultrow][2]=TOO_MANY_SIP;
	faultrow++;
     }
     if(stUp0Counter > AMOUNT_UP0_X1)
     {
	faults[0][0]++;								
	faults[faultrow][0]=1;
	faults[faultrow][1]=999;								
	faults[faultrow][2]=TOO_MANY_UP0;
	faultrow++;
     
     }
     if(stIpCounter > AMOUNT_IP_X1 )
     {
	faults[0][0]++;								
	faults[faultrow][0]=1;
	faults[faultrow][1]=999;								
	faults[faultrow][2]=TOO_MANY_IP;
	faultrow++;
     }
     if(stRasCounter > AMAOUNT_RAS_X1) // TOO_MANY_RAS_REMOTE
     {
	faults[0][0]++;								
	faults[faultrow][0]=1;
	faults[faultrow][1]=999;								
	faults[faultrow][2]=TOO_MANY_RAS_REMOTE;
	faultrow++;

     }
     if(stDeskCounter>AMOUNT_IP_X1) // TOO_MANY_DESK
     {
	faults[0][0]++;								
	faults[faultrow][0]=1;
	faults[faultrow][1]=999;								
	faults[faultrow][2]=TOO_MANY_DESK;
	faultrow++;  
     }
     if(stabCounter > AMOUNT_ANALOG_X1) // TOO_MANY_ANALOG
     {
	faults[0][0]++;								
	faults[faultrow][0]=1;
	faults[faultrow][1]=999;								
	faults[faultrow][2]=TOO_MANY_ANALOG;
	faultrow++;     
     }     
     if(stIsdnCounter > AMOUNT_ISDN_X1) // TOO_MANY_ISDN
     {
	faults[0][0]++;								
	faults[faultrow][0]=1;
	faults[faultrow][1]=999;								
	faults[faultrow][2]=TOO_MANY_ISDN;
	faultrow++;     
     }
     if(stDectCounter > AMOUNT_DECT_X1 )//TOO_MANY_DECT
     {
	faults[0][0]++;								
	faults[faultrow][0]=1;
	faults[faultrow][1]=999;								
	faults[faultrow][2]=TOO_MANY_DECT;
	faultrow++;     
     }
     if(sysCountVirtual > AMAOUNT_VIRTUAL_X1)
     {
	faults[0][0]++;								
	faults[faultrow][0]=4;
	faults[faultrow][1]=253;								
	faults[faultrow][2]=TOO_MANY_STATIONS;
	faultrow++;
     }
     
     if( stSipCounter +stIsdnCounter+ stIpCounter >  AMOUNT_IP_X1)
     {	
     	faults[0][0]++;								
	faults[faultrow][0]=1;
	faults[faultrow][1]=999;								
	faults[faultrow][2]=TOO_MANY_STATIONS;
	faultrow++;	
     }
     if(numGroup > AMOUNT_GROUPS_X1)
     {
     	faults[0][0]++;								
	faults[faultrow][0]=2;
	faults[faultrow][1]=800;								
	faults[faultrow][2]=TOO_MANY_GROUPS;
	faultrow++;	
     
     }
     
   
    
				

   }
   else ///    In System X3x5x8
   {
   if(ifaxCallnoCount>AMOUNT_OF_VP_FAX   ||  ifaxDidCount>AMOUNT_OF_VP_FAX )
   {
   
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=4;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_FAXES;
		faultrow++;			   	
	}
   }
   
   
   
   if( isumNodeStVir > NUM_OF_LOG_TLN_PORT )
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=1;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_STATIONS;
		faultrow++;			   	
	}
    }
  
   
   if(  stRasAdminCounter >  1) // RAS-ADMIN
   {
	if(faultrow!=21)
	{
		faults[0][0]++;
		faults[faultrow][0]=1;	
		faults[faultrow][1]=999;	
		faults[faultrow][2]=TOO_MANY_RAS_ADMIN; 
		faultrow++;	
	}
   }
   
   if(  stRasLicCounter >  1)  // RAS-LIC
   {
	if(faultrow!=21)
	{	
		faults[0][0]++;
		faults[faultrow][0]=1;	
		faults[faultrow][1]=999;	
		faults[faultrow][2]=TOO_MANY_RAS_LIC; 
		faultrow++;	
	}
   }

   if(  stDectCounter >  syscountDect) 
   {
	if(faultrow!=21)
	{	
		faults[0][0]++;
		faults[faultrow][0]=1;	
		faults[faultrow][1]=999;	
		faults[faultrow][2]=TOO_MANY_DECT; /*42*/
		faultrow++;	
	}
   }


   if(  stDeskCounter >  AMOUNT_OF_IP_PORTS) 
   {
	if(faultrow!=21)
	{
		faults[0][0]++;
		faults[faultrow][0]=1;	
		faults[faultrow][1]=999;	
		faults[faultrow][2]= TOO_MANY_DESK;/*48*/  
		faultrow++;	
	}
   }
   
   
   if( stRasCounter > AMOUNT_OF_RAS_TOTAL)
   {			   	
	if(faultrow!=21)
	{		
		faults[0][0]++;
		faults[faultrow][0]=1;	
		faults[faultrow][1]=999;	
		faults[faultrow][2]=TOO_MANY_RAS_REMOTE;  
		faultrow++;		
	}
   }
   
   if( stIpCounter > AMOUNT_OF_IP_PORTS)
   {
	if(faultrow!=21)
	{
		faults[0][0]++;
		faults[faultrow][0]=1;	
		faults[faultrow][1]=999;	
		faults[faultrow][2]=TOO_MANY_IP;  
		faultrow++;	
	}
   }
   

   
   if( stUp0Counter > syscountUp0) // from system Card 
   {	
	if(faultrow!=21)
	{		
		faults[0][0]++;
		faults[faultrow][0]=1;	
		faults[faultrow][1]=999;	
		faults[faultrow][2]=TOO_MANY_UP0;  
		faultrow++;				   	
	}
   }

   if( stabCounter > syscountAn )
   {
	if(faultrow!=21)
	{	
		faults[0][0]++;
		faults[faultrow][0]=1;	
		faults[faultrow][1]=999;	
		faults[faultrow][2]=TOO_MANY_ANALOG;
		faultrow++;
	}
   }
   
   
   if( stIsdnCounter > syscountIsdn)
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=1;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_ISDN;
		faultrow++;	
	}
   }
   
   if( stSipCounter > AMOUNT_OF_IP_PORTS )
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=1;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_SIP;
		faultrow++;	
	}
   }

   if( syscountAutoAt > AMOUNT_OF_VP_AUTO_ATTENDANT )
   {
	if(faultrow!=21)
	{	
		faults[0][0]++;								
		faults[faultrow][0]=4;
		faults[faultrow][1]=999;								
		faults[faultrow][2]= TOO_MANY_VP_AUTO_ATTENDANT; 
		faultrow++;	
	}
   
   }
   if( syscountCCFax > AMOUNT_OF_VP_CALL_CENTER_FAX )
   {	
	if(faultrow!=21)
	{	
		faults[0][0]++;								
		faults[faultrow][0]=4;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_VP_AUTO_ATTENDANT; 
		faultrow++;
	}
   }
   
   if( syscountConf > AMOUNT_OF_CONFERENCE_ROOMS )
   {

	if(faultrow!=21)	
	{
		faults[0][0]++;								
		faults[faultrow][0]=4;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_OSO_CONFERENCE; 
		faultrow++;	
	}
   }

   if( syscountPark > AMOUNT_OF_PARK_POSITION )
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=4;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_PARK;
		faultrow++;			   	
	}
   }
   

   if( sysCountFaxGroup > AMOUNT_OF_VP_FAX_GROUPS )
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=4;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_FAXGROUPS;
		faultrow++;			   	
	}
   }
   
   
   if(sysCountMeetMe  > AMOUNT_OF_VP_MEETME) 
   {
	if(faultrow!=21)
	{
		faults[0][0]++;								
		faults[faultrow][0]=1;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=TOO_MANY_MEET_ME;
		faultrow++;			   	
	}         
   }
    
  }// else if no X1 
    
 }   
    //----------------------------delete memory location--------------------------
   for(i=0;i<(numStation+numGroup+numVirtual+numTrnk+numVoicemail+numLic);i++)
   {
	delete []stnNumber[i];
	delete []stnDuwa[i];
	delete []stnNode[i];
	delete []stnStType[i];
	delete []stnStTypeNode[i];
	delete []stnAccessAnalog[i];
	delete []stnAccessUP0[i];
	delete []stnVoicemail[i];
	delete []stnFaxCallno[i];
	delete []stnFaxDid[i];
   }
   
   for(i=0; i<numLic; i++)
   {
   	delete []stnLicnum[i];
   }
   
   for(i=0;  i<65; i++)
   {
      delete []stnCallPick[i];
   }
   
   
    for(i=0;  i<numStation+1; i++)
    {
    	delete []stnSipStations[i];
    }
    for(i=0;  i<numSipConfig+1; i++)
    {
    	delete []stnSipConfig[i];
    } 
   
   delete []stnNumber;
   delete []stnDuwa;
   delete []stnNode;
   delete []stnLicnum;
   delete []stnStType;
   delete []stnStTypeNode;
   delete []stnAccessAnalog;
   delete []stnAccessUP0;
   delete []stnVoicemail;
   delete []stnFaxCallno;
   delete []stnFaxDid;
   delete []stnSipStations;
   delete []stnSipConfig;
   delete []stnCallPick;
   
    if( faultrow <2 )
    {
     
     if(numStation > 0)
     {      
       blwriteXmlStations =  writeXmlCustomer(fname, numStation, ievmCounter);   
     }
      
     if(numVirtual >0 )
     {      	
	//blwriteXmlVirtual = writeXmlVirtuals(fname, numVirtual);   
     }
     
     if(numTrnk >0 )
     {
     // 	blwriteXmlTrunks = writeXmlTrunkGroups(fname, numTrnk);
     }	
     
     if(numVoicemail >0 ) 
     {
	//   blwriteXmlVoicemail = writeXmlVoiceMail(fname, numVoicemail);
     }
     
     if(numGroup >0) 
     {
    //   blwriteXmlGroups = writeXmlGroups(fname, numGroup, ievmCounter);
     }
     
     if(numSipConfig>0)
     {

     //  blwritexmlSipConfig = writeXmlSipConfig(fname,numSipConfig);

     }
     
     
     	/*Check if stored data for the vurrent node*/
     	if( (!blwriteXmlStations)  && (!blwriteXmlVirtual)  && (!blwriteXmlTrunks) && (!blwriteXmlVoicemail) && (!blwriteXmlGroups) && (!blwritexmlSipConfig) )
	{
		faults[0][0]++;	   							
		faults[faultrow][0]=1;
		faults[faultrow][1]=999;								
		faults[faultrow][2]=NO_DATA_NODE; //No data found for your node Id
		faultrow++;	
	}
     
     
    }
   
  
    
}


int _tmain(int argc, _TCHAR* argv[])
{
	int error[21][3];
	char  lias[5];
enum MyEnum
{  A_ENUM_VALUE,
   B_ENUM_VALUE,
   C_ENUM_VALUE
};

//char * filename="CustomerDataD1.xml" ;

//string tempstr=filename;


 //printf("My enum Value : %d\n", (int)C_ENUM_VALUE);
 readXmlUsa("CustomerData333.xml",error, true);	
 //preadxml("katsinas.xml",error);

	getch();
	return 0;
}

/*
typedef struct TAG_DB_KW_CHK_KWZ_NAME
{
    int* rufnr_ptr;
    int  rn_length;
    int  rtg_ind;
    int port;
    int kwz_index;

}DB_KW_CHK_KWZ_NAME;



*/