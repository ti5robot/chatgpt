#ifndef ENCODE_H
#define ENCODE_H
#define IDNUM 6
#define BUF_SIZE (7*IDNUM+3)
#include<iostream>
#include <srl/serial.h>
#include <move/tool.h>
//#include <vector>
//#include <string.h>
using namespace std;
uint8_t canidList[IDNUM],cmdList1[IDNUM],cmdList2[IDNUM],cmdList3[IDNUM],cmdList4[IDNUM];
serial::Serial sp;
int32_t crc32_table[256]={0,1996959894,-301047508,-1727442502,124634137,1886057615,-379345611,-1637575261,	249268274,2044508324,-522852066,-1747789432,162941995,2125561021,-407360249,-1866523247,498536548,1789927666,-205950648,-2067906082,450548861,1843258603,-187386543,-2083289657,325883990,1684777152,-43845254,-1973040660,	335633487,1661365465,-99664541,-1928851979,997073096,1281953886,-715111964,-1570279054,1006888145,1258607687,-770865667,-1526024853,901097722,1119000684,-608450090,-1396901568,853044451,1172266101,-589951537,-1412350631,	651767980,1373503546,-925412992,-1076862698,565507253,1454621731,-809855591,-1195530993,671266974,1594198024,-972236366,-1324619484,795835527,1483230225,-1050600021,-1234817731,1994146192,31158534,-1731059524,-271249366,	1907459465,112637215,-1614814043,-390540237,2013776290,251722036,-1777751922,-519137256,2137656763,141376813,-1855689577,-429695999,1802195444,476864866,-2056965928,-228458418,1812370925,453092731,-2113342271,-183516073,	1706088902,314042704,-1950435094,-54949764,1658658271,366619977,-1932296973,-69972891,1303535960,984961486,-1547960204,-725929758,1256170817,1037604311,-1529756563,-740887301,1131014506,879679996,-1385723834,-631195440,	1141124467,855842277,-1442165665,-586318647,1342533948,654459306,-1106571248,-921952122,1466479909,544179635,-1184443383,-832445281,1591671054,702138776,-1328506846,-942167884,1504918807,783551873,-1212326853,-1061524307,-306674912,-1698712650,62317068,1957810842,-355121351,-1647151185,81470997,1943803523,-480048366,-1805370492,225274430,2053790376,-468791541,-1828061283,167816743,2097651377,-267414716,-2029476910,503444072,1762050814,-144550051,-2140837941,426522225,1852507879,-19653770,-1982649376,282753626,1742555852,-105259153,-1900089351,397917763,1622183637,-690576408,-1580100738,953729732,1340076626,-776247311,-1497606297,1068828381,1219638859,-670225446,-1358292148,906185462,1090812512,-547295293,-1469587627,829329135,1181335161,-882789492,-1134132454,628085408,1382605366,-871598187,-1156888829,570562233,1426400815,-977650754,-1296233688,733239954,1555261956,-1026031705,-1244606671,752459403,1541320221,-1687895376,-328994266,1969922972,40735498,-1677130071,-351390145,1913087877,83908371,-1782625662,-491226604,2075208622,213261112,-1831694693,-438977011,2094854071,198958881,-2032938284,-237706686,1759359992,534414190,-2118248755,-155638181,1873836001,414664567,-2012718362,-15766928,1711684554,285281116,-1889165569,-127750551,1634467795,376229701,-1609899400,-686959890,1308918612,956543938,-1486412191,-799009033,1231636301,1047427035,-1362007478,-640263460,1088359270,936918000,-1447252397,-558129467,1202900863,817233897,-1111625188,-893730166,1404277552,615818150,-1160759803,-841546093,1423857449,601450431,-1285129682,-1000256840,1567103746,711928724,-1274298825,-1022587231,1510334235,755167117};

int16_t table_s[]={12336,12592,12848,13104,13360,13616,13872,14128,14384,14640,16688,16944,17200,17456,17712,17968,12337,12593,12849,13105,13361,13617,13873,14129,14385,14641,16689,16945,17201,17457,17713,17969,12338,12594,12850,13106,13362,13618,13874,14130,14386,14642,16690,16946,17202,17458,17714,17970,12339,12595,12851,13107,13363,13619,13875,14131,14387,14643,16691,16947,17203,17459,17715,17971,12340,12596,12852,13108,13364,13620,13876,14132,14388,14644,16692,16948,17204,17460,17716,17972,12341,12597,12853,13109,13365,13621,13877,14133,14389,14645,16693,16949,17205,17461,17717,17973,12342,12598,12854,13110,13366,13622,13878,14134,14390,14646,16694,16950,17206,17462,17718,17974,12343,12599,12855,13111,13367,13623,13879,14135,14391,14647,16695,16951,17207,17463,17719,17975,12344,12600,12856,13112,13368,13624,13880,14136,14392,14648,16696,16952,17208,17464,17720,17976,12345,12601,12857,13113,13369,13625,13881,14137,14393,14649,16697,16953,17209,17465,17721,17977,12353,12609,12865,13121,13377,13633,13889,14145,14401,14657,16705,16961,17217,17473,17729,17985,12354,12610,12866,13122,13378,13634,13890,14146,14402,14658,16706,16962,17218,17474,17730,17986,12355,12611,12867,13123,13379,13635,13891,14147,14403,14659,16707,16963,17219,17475,17731,17987,12356,12612,12868,13124,13380,13636,13892,14148,14404,14660,16708,16964,17220,17476,17732,17988,12357,12613,12869,13125,13381,13637,13893,14149,14405,14661,16709,16965,17221,17477,17733,17989,12358,12614,12870,13126,13382,13638,13894,14150,14406,14662,16710,16966,17222,17478,17734,17990};
std::vector<std::string> vStringSplit(const  std::string& s, const std::string& delim="\n")
{
    std::vector<std::string> elems;
    size_t pos = 0;
    size_t len = s.length();
    size_t delim_len = delim.length();
    if (delim_len == 0) return elems;
    while (pos < len)
    {
        int find_pos = s.find(delim, pos);
        if (find_pos < 0)
        {
            elems.push_back(s.substr(pos, len - pos));
            break;
        }
        elems.push_back(s.substr(pos, find_pos - pos));
        pos = find_pos + delim_len;
    }
    return elems;
}
void getdata(char* l,char* v,int a,int b)
{
        int j=0;
        for(int i=a;i<b;i++){
                v[j]=l[i];
                j++;
        }
	std::cout<<v<<std::endl;
}

void ivs(char* u,string& inv,int l)
{
        int j=0;
        for(int i=l-1;i>0;i-=2){
            inv[j++]=u[i-1];
                inv[j++]=u[i];
        }
}

int translate(string& inv,int l)
{
        unsigned int value=0;
        char OX2H[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
        unsigned int j;
        for(int i=0;i<l;i++){
                for(j=0;j<16;j++)
                        if(OX2H[j]==inv[i])
                                value=value*16+j;
        }
        return (int)value;
}


int u2int(unsigned int u)
{
        unsigned int a=32708;
        int v;
	if(u>=a){
                v=u%a;
		v=v-a;
	}
        else
                v=u;
        return v;


}
uint32_t calcCRC32(uint32_t crc, uint8_t *string, uint32_t size)
{
    while(size--)
        crc = (crc >> 8)^(crc32_table[(crc ^ *string++)&0xff]);
    return crc;
}
size_t MemToStrStream(char* dest, const char* sourse, uint32_t size,char head,char end)
{
    uint32_t i = 0;
    uint8_t *pindex = (uint8_t *)sourse;
    *dest = head;
    int16_t *p = (int16_t *)(dest+1);
    for(i=0;i<size;i++)
    {
        p[i] = table_s[pindex[i]];
    }
    p[i] = end;
    return size*2+2;
}
void initserial()
{

    serial::Timeout tot= serial::Timeout::simpleTimeout(100);
    sp.setPort("/dev/ttyUSB0");
    sp.setBaudrate(2000000);
    sp.setTimeout(tot);
    try {sp.open();}
    catch(serial::IOException& e) {cout<<"IO error"<<endl;}
    get_cmdlist(cmdList1,36);
    get_cmdlist(cmdList2,37);
    get_cmdlist(cmdList3,30);
    get_cmdlist(cmdList4,29);
    get_canidlist(canidList);
};

void package_void_cmd()
{
    char uartTxBuf[2000];
    uint8_t buf[12]={0};
    uint32_t index=0;
    buf[index++] = 0;
    buf[index++] = 0;
    buf[index++] = 8;
    buf[index++] = 0;
    index+=4;
    *(uint32_t *)(buf+index) = calcCRC32(0,buf,index);
    index+=4;
    uint32_t byteToWrite = MemToStrStream(uartTxBuf,(char*)buf,index,'<','\n');
    sp.write(uartTxBuf);
};
void package_set_cmd(uint8_t numOfActuator, uint8_t *commandList, uint32_t *parameterList)
{
    char uartTxBuf[2000];
    uint8_t buf[400]={0};
    uint32_t index=0;
    
    buf[index++] = numOfActuator;
    for(int i=0;i<numOfActuator;i++) buf[index++] = canidList[i];
    for(int i=0;i<numOfActuator;i++) buf[index++] = commandList[i];
    for(int i=0;i<numOfActuator;i++){
        *(uint32_t *)(buf+index) = parameterList[i];
        index+=4;
    }
    *(uint32_t *)(buf+index) = calcCRC32(0,buf,index);
    index+=4;
    uint32_t byteToWrite = MemToStrStream(uartTxBuf,(char*)buf,index,'<','\n');
    sp.write(uartTxBuf);
};
bool getCommand(uint32_t parameterList[IDNUM])
{
    int sock;   
    int return_num;
    int i,count,r=0;
    char uartTxBuf[2000];
    package_void_cmd();
    std::string bbuffer = sp.read(1024);
    auto res=vStringSplit(bbuffer);
    for(int i=0;i<res.size();i++) {
	    std::cout<<"+++"<<res[i]<<std::endl;
	    if (res[i].size()>140){
			uint8_t IdToIndexMap[256];
			std::string strStream;
			int index = res[i].size();
			uint8_t mem[400]={0}, memIndex=0;
			if(res[i].at(0)=='<' && index==143)//the data from serialPort ,the first CHAR is "<"
			{
			char line[143];
			strncpy(line,res[i].c_str(),res[i].length()+1);
			char I[4],V[4],S[8];
			int Iv,Vv,Sv;
			std::string inv1;
			std::string inv2;
			//ifstream infile;
			//infile.open("3.txt");//´ò¿ªÎÄ¼þ
			int k=31;
			for (int j=0;j<IDNUM;j++){
				getdata(line,I,k+j*16,k+j*16+4);
				getdata(line,V,k+j*16+4,k+j*16+8);
				getdata(line,S,k+j*16+8,k+j*16+16);
				ivs(I,inv1,4);
				Iv=u2int(translate(inv1,4));
				ivs(V,inv1,4);
				Vv=u2int(translate(inv1,4));
				ivs(S,inv2,8);
				Sv=(int)translate(inv2,8);
				parameterList[j]=Sv;
				cout<<"ID:"<<j<<" I:"<<Iv<<" v:"<<Vv<<" s:"<<Sv<<endl;
			}
			}
	    }
    }
    return true;
};
#endif
