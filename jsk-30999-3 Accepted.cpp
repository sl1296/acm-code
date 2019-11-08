
#include<cstdio>
#define ll long long
using namespace std;
ll val[]={0,20260,43051,66796,91191,116055,141273,166831,192584,218666,244959,271381,297950,324718,351568,378590,405683,433007,460399,487946,515459,543163,570900,598720,626633,654610,682779,710817,739045,767361,795692,824044,852483,880957,909587,938163,966912,995714,1024390,1053259,1082052,1111086,1140025,1169058,1198114,1227216,1256322,1285467,1314718,1343909,1373276,1402663,1432028,1461383,1490835,1520327,1549817,1579485,1608989,1638560,1668193,1698008,1727545,1757336,1787135,1816856,1846643,1876516,1906390,1936258,1966195,1996049,2026146,2056114,2086096,2116163,2146136,2176339,2206431,2236551,2266667,2296864,2327135,2357244,2387549,2417875,2448152,2478466,2508871,2539289,2569601,2600028,2630462,2660888,2691445,2721945,2752371,2782903,2813462,2843898,2874639,2905255,2935915,2966459,2997158,3027811,3058528,3089264,3120032,3150805,3181515,3212329,3243119,3273893,3304757,3335626,3366520,3397254,3428094,3459009,3489932,3520927,3552044,3582947,3613936,3644934,3675992,3707046,3738181,3769153,3800237,3831345,3862490,3893433,3924649,3955822,3986994,4018098,4049282,4080401,4111735,4142975,4174216,4205429,4236737,4267951,4299181,4330402,4361698,4393009,4424465,4455749,4487066,4518421,4549842,4581288,4612686,4644020,4675533,4706931,4738511,4769879,4801405,4832819,4864289,4895789,4927289,4958914,4990388,5021944,5053627,5085165,5116664,5148340,5179914,5211519,5243229,5274862,5306643,5338274,5369867,5401591,5433318,5465053,5496754,5528486,5560189,5591961,5623791,5655465,5687265,5719066,5750870,5782587,5814434,5846213,5878078,5909937,5941713,5973605,6005474,6037426,6069335,6101268,6133203,6165093,6196958,6228911,6260885,6292735,6324796,6356725,6388725,6420631,6452693,6484693,6516762,6548769,6580831,6612809,6644824,6676872,6708952,6741046,6773127,6805200,6837116,6869313,6901373,6933415,6965625,6997815,7029992,7062059,7094214,7126363,7158539,7190832,7222889,7255189,7287263,7319590,7351801,7384049,7416284,7448486,7480799,7513127,7545416,7577654,7609896,7642205,7674449,7706788,7739107,7771542,7803782,7836079,7868350,7900871,7933207,7965515,7997841,8030139,8062722,8094958,8127413,8159953,8192274,8224654,8257084,8289546,8321906,8354479,8386908,8419457,8451805,8484255,8516711,8549262,8581801,8614308,8646872,8679391,8712055,8744510,8776972,8809648,8842096,8874564,8907197,8939694,8972275,9004840,9037389,9070049,9102547,9135207,9167660,9200312,9232961,9265652,9298285,9331053,9363554,9396189,9428838,9461536,9494157,9526836,9559561,9592347,9625004,9657737,9690447,9723317,9755938,9788640,9821311,9854037,9886950,9919644,9952341,9985228,10017983,10050644,10083336,10116217,10148844,10181632,10214511,10247347,10280203,10312939,10345820,10378492,10411389,10444289,10477188,10509957,10542883,10575635,10608523,10641410,10674240,10707297,10740072,10773097,10805861,10838743,10871705,10904531,10937504,10970237,11003239,11036225,11069223,11102138,11135127,11168017,11201007,11233965,11266950,11299956,11332921,11365865,11398800,11431888,11464883,11497955,11531043,11563996,11597052,11630087,11663081,11696035,11729193,11762177,11795095,11828353,11861262,11894297,11927525,11960646,11993705,12026778,12059801,12092887,12126025,12159117,12192161,12225325,12258400,12291509,12324765,12357794,12391040,12424070,12457206,12490295,12523516,12556761,12589800,12623006,12656166,12689457,12722647,12755746,12789067,12822151,12855435,12888482,12921848,12954965,12988106,13021269,13054579,13087628,13120976,13154206,13187504,13220838,13253953,13287387,13320508,13353815,13387020,13420301,13453602,13486819,13520191,13553515,13586774,13619951,13653326,13686625,13719869,13753305,13786622,13820013,13853247,13886585,13919860,13953211,13986514,14019996,14053203,14086475,14120008,14153320,14186683,14219978,14253309,14286885,14320169,14353520,14386885,14420379,14453540,14486933,14520392,14553748,14587304,14620818,14654166,14687596,14721013,14754506,14788025,14821464,14854944,14888540,14921887,14955432,14988913,15022302,15055781,15089294,15122815,15156225,15189684,15223132,15256723,15290281,15323818,15357178,15390837,15424280,15457662,15491399,15524804,15558424,15591829,15625479,15658940,
ll zs[10010],tot;
int main(){
    for(ll i=2;i<10005;++i){
        if(!zs[i]){
            for(ll j=i*i;j<10005;j+=i){
                zs[j]=1;
            }
        }
    }
    for(ll i=2;i<10005;++i){
        if(!zs[i]){
            zs[tot++]=i;
        }
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int id=n/5000;
        ll ans=val[id];
        for(ll i=id*5000+1;i<=n;++i){
            if(i==1){
                ++ans;
                continue;
            }
            ll tmp=i,c1=0,cx=0;
            for(int j=0;zs[j]*zs[j]<=tmp;++j){
                if(tmp%zs[j]==0){
                    int cnt=0;
                    do{
                        tmp/=zs[j];
                        ++cnt;
                    }while(tmp%zs[j]==0);
                    if(cnt==1)++c1;
                    else if(cnt>2){
                        cx=1;
                        break;
                    }
                }
            }
//            printf("%lld c1=%lld cx=%lld tmp=%lld\n",i,c1,cx,tmp);
            if(!cx){
                if(tmp>1)++c1;
                ans+=(1LL<<c1);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
