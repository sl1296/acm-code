
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
char pca[10200]="AbeAdatiAizawaAkimotoAkiyamaAndouAoyagiAraiArakiArayaAsadaAsanoAzumaBabaEgutiEndouFukazawaFukudaFukuiFukumotoFukunagaFukuokaFukusimaFurukawaFuziiFuzimotoFuzimuraFuzinoFuzitaFuziwaraHamadaHamagutiHamanoHaraHaradaHaragutiHasegawaHatakeyamaHatanakaHattoriHayakawaHayasiHayasidaHidakaHigaHigutiHiramatuHiranoHirataHirayamaHiroseHirotaHonmaHorigutiHorikawaHoriutiHosiHosokawaHottaIidukaIizimaIkedaIkegamiImamuraInadaInagakiInoueIsibasiIsidaIsiguroIsiharaIsiiIsiyamaItikawaItouIwaiIwamotoIwaseIwataIzumiKamataKameiKamiyaKanaiKanazawaKanedaKanesiroKannoKanouKasaharaKasiwagiKataokaKawabataKawagutiKawaharaKawaiKawamotoKawamuraKawasimaKawataKaziwaraKimuraKitagawaKitanoKitazimaKobayasiKogaKoideKoizumiKomatuKomoriKondouKonisiKosakaKoudaKounoKoyanagiKozimaKuboKubotaKudouKumagayaKuriharaKuritaKurodaKurokawaKurosawaMaedaMakinoMatubaraMatuiMatumotoMatumuraMatunoMatuokaMatusitaMatuyamaMatuzakiMikiMinamiMisimaMiuraMiwaMiyagawaMiyaharaMiyamotoMiyasitaMiyataMiyazakiMiyazawaMiyazimaMiyosiMizogutiMizunoMizutaniMogiMoriMorikawaMoriokaMorisitaMoritaMotidukiMukaiMuraiMurakamiMuraseMurayamaNagaokaNagasimaNagataNaitouNakagawaNakaharaNakanisiNakaoNakataNakataniNakayamaNakazimaNaritaNegisiNemotoNinomiyaNisiNisidaNisiharaNisikawaNisimotoNisimuraNisioNisiokaNisiyamaNisizawaNiwaNodaNogutiNomuraNozakiNumataOdaOgasawaraOgataOgawaOginoOikawaOkaOkabeOkamotoOkanoOkazakiOkudaOkumuraOkuyamaOnoOnoderaOobaOohiraOokawaOokuboOomoriOomuraOonisiOonoOosakiOosawaOosimaOosiroOotaOotakeOotukaOoutiOtiOtiaiOzawaSaekiSaitouSakagutiSakaiSakakibaraSakamotoSakataSakumaSakuraiSatouSekiSekineSendaSetoSibataSibuyaSimadaSimamuraSimizuSimuraSindenSinodaSinoharaSinozakiSiraisiSonodaSudaSudouSugaharaSugeSugiharaSugimotoSugitaSugiuraSuzukiSyouziTabataTagutiTaharaTakadaTakagiTakahasiTakaiTakaseTakasimaTakedaTakeiTakemuraTakenakaTakesitaTaketaTakeutiTakizawaTamuraTanabeTaniTanigawaTanoueTasiroTazimaTeradaTerazimaTibaTomitaToyodaTudaTukadaTukamotoTutiyaTutuiTutumiTuziUedaUeharaUemuraUmedaUnoUsuiUtiyamaWadaYagiYagutiYamagutiYamamotoYamamuraYamanakaYamaneYamaokaYamazakiYanoYasudaYazimaYokawaYokoiYokotaYokoyamaYosidaYosiharaYosiiYosimotoYosimuraYosinoYosizawaYuasa";
char pcb[42000]="AaiAdukiAdumiAeAeriAguriAihaAihoAikiAikoAiruAiseAitoAkaeAkahoAkanaAkaneAkariAkehaAkenoAkeoAkiAkiharuAkihikoAkihiroAkihisaAkihitoAkiiAkimasaAkinoAkinobuAkiraAkitakaAkitomoAkiyoAkoAmiAmiruAmuAnamuAnanAnbiAnkaAnmiAnonAnsyaAnzuAoAobaAohaAokaAomiAonaAonoAoriAoseAozoraArataAreiArihaArikaArimiArisaAruhaArunaAsaeAsahiAsaiAsanaAsariAsatoAsayoAsuhiAsukaAsumiAtomuAtueAtuhiroAtukaAtukiAtunaAtuneAtunoAtuoAtusaAtutoAwanaAwanoAyaAyaeAyahaAyahoAyaiAyakaAyakiAyakoAyamiAyaneAyariAyasaAyatoAyukiAyumeAyumiAyunaAyuriAyutoAzukiAzumiAzunaBieiDaigoDaikiDaisakuDaitoDerutaEhanaEhoEiEigorouEihaEikoEinaEiriEizirouEkoEmaEmikoEminaEmioEmiriEoEreiErenErikoErunaEruruEtukiEtumiEturouFeiFuaFubukiFumiFumiakiFumieFumihideFumikaFumikazuFumioFumitosiFumiyaFusaFusaeFusanaFusanoFusatuguFusaziFutabaFutosiFuugaFuukaFuukiFuunaFuuneFuunoFuyueFuyuhiFuyumiFuyunoFuzikaFuzinaGaiGakuGakutoGenGouGuntaHaineHamiHanaeHanakoHanatuHannaHanoHanonHareHaruakiHaruhiHaruhoHarukiHarukoHarumaHarumeHarumiHarumoHaruneHarunoHarunobuHaruoHaruseHaruyaHaruyoHasumiHatuhoHatukaHatukiHatukuHatumiHatunaHatuneHatunoHayaHayakaHayamiHayasaHayaseHayatoHayumaHazimeHazyuHideakiHidehitoHidekazuHidekiHidemiHidenagaHidenariHidenobuHidenoriHideriHidetoHidetuguHideyaHideyasuHideyosiHideyukiHihoHiinaHiiraHiizuHikariHinaHinakiHinakoHinanoHinatuHinonHioHioriHirohisaHirokazuHirokiHiromikiHironaHironariHironobuHironoriHirotadaHirotakaHirotarouHirotatuHirotosiHiroyasuHiroyosiHiroyukiHisafumiHisakiHisanariHisanoHisuiHitokaHitoseHitosiHituziHiyoriHiyuHiziriHokutoHomareHonaHonamiHonokaHononHononeHonoriHosihaHosimiHosinaHosineHosinoHoukaHozumiHyakusigeHyougaIeyasuIkkouIkuIkueIkuhoIkukoIkuyoImariImiInaInatuInoriIonIppeiIriIrukaIsaIsaeItidouItieItihaItimiItinaItinoItirikiItirouItoItuhoIzuhoKaaiKadumiKadusaKaeKahaneKahoKairiKaitoKakeruKakiKamiKanKanaKanaeKananKananaKanataKanatuKanawaKantaKaoriKareiKariKarinaKasakiKasaneKasuiKatuhiroKatuhisaKatuitiKatumiKatunariKatunobuKatunoriKatuoKatusiKatutarouKatuyosiKatuziKayokoKayouKayumeKazituKazuakiKazueKazuhisaKazumaKazuneKazunoKazusaKazusigeKazutarouKazutiKazutoKazuyosiKazuyukiKeigoKeigouKeiitiKeiitirouKeikiKeimiKeinoKeiriKeisaKeisukeKeizouKengoKenitirouKenkitiKensakuKentarouKentoKenziKieKiharuKihiroKihoKiiKikaKikiKikuKikukoKikunoKimiKimiakiKimieKimikaKimiyukiKinaKinamiKinoriKinueKinziKiranKirinKirinaKirineKisaKisakiKiseiKisyaKitinoKiyaKiyoeKiyofumiKiyohaKiyohiKiyokaKiyomiKiyonaKiyonoKiyoraKiyosiKiyuiKiyukiKobatoKohanaKohaneKoharuKohinaKoimiKokoeKokohaKokoruKomoeKonatuKonoeKonokaKorinKosatoKotoKotoeKotohoKotokaKotokiKotokoKotomeKotomiKotoneKotoseKotoyoKoudaiKoueKouheiKoumiKouriKouseiKousienKousukeKoutarouKouzirouKouzouKoyumeKoyumiKozumiKumikoKunKuniharuKuniyosiKurehaKureiKurenoKurumiKurutiKuuKyoukiKyounaKyounoKyouziMaaiMaayaMabukiMadohaMadokaMaeMafumiMahiroMahoMahonaMaihoMaikiMainaMaineMairaMakieMakihaMakikoMakinoMamiMamoruManabuManahaManamaManamiMananManaoManariManaseManayaManoManonMaouMareiMaremuMarenMarikaMarikoMarinMarioMariyaMasahiroMasahitoMasaiMasakazuMasakiMasakoMasamiMasanaMasanagaMasanaoMasanoMasaoMasasiMasatakaMasatosiMasatuguMasayoMasayosiMasayukiMasazumiMasihoMasuhiroMatukiMatumiMayaMayakaMayakoMayoMayuMayumeMayumiMayumuMayunaMayuraMayuriMayuzumiMebaeMegukaMeguriMeiraMeiranMeiyaMemiMeoMeyaMiaMiakaMiakiMiakoMiasaMibukiMidueMidukiMieiMifukiMihaMihatoMihayuMihiroMihokaMihokoMihonaMiihaMiinaMikaeMikakoMikanMikawaMikihiroMikikazuMikikoMikinaMikoMikuMikuhoMimaMimariMimiMimoriMinaMinaeMinagiMinakaMinakiMinamiMinaseMinatoMineMinekaMinekiMineyukiMinoMinoruMiokaMionMioraMioriMireMiruMirukaMisahoMisakiMisaoMisonoMisyuriMitieMitihiroMitikaMitinaMituakiMitugiMituhaMituhiroMituhoMitukiMitukoMitunoMitunoriMituruMitusiMituyoMituyosiMiuMiwaMiyakoMiyokaMiyouMiyukaMiyusaMizueMizuhaMizuhoMizuneMizunoMizuoMizuseMizyuMoaMoekaMoeriMoiMokaMokoMomohiMomokaMomokoMomokuMomomiMomonaMomoneMomooMonanMonoMoreMorihiroMorimitiMorioMotoMotoiMotokaMotomiMotoyukiMumeMuneoMusasiMutekiMutukiMutukoMutumiMutuyoNaeNahokoNainaNaitoNamihaNamikiNamikoNaminaNanahaNanahoNanakaNanakiNanakoNananaNanariNanaseNanasiNanatoNanayaNankaNanohaNanokaNanokoNanonNaoNaohikoNaohisaNaohitoNaokiNaokoNa
char pda[4500]="ABaeBaekBakBanBangBeomBeonBiBinBingBongBuChaChangChoChoeChongChuChunDaDaeDamDanDangDeungjeongDokDokgoDonDongDongbangDuEoEogeumEomEumGaeGalGamGeumGeunGiGilGimGoGongGukGungGwakGwanGwonGyeonGyeongGyoHaHaeHakHamHanHeoHoHongHuHwaHwanHwangHwangboHwangmokHyeongIImInJamJangJeJeoJeongJeupJinJuJunKwaeMaeMaengManMangjeolMiMinMoMokMuMukMyeongMyoNaNaeNoNoeNuOOngPanPoPungPyeonPyeongPyoRaRanRangRoeRyeoSaSagongSamSeoSeokSeomunSeongSeonuSeungSiSimSinSoSongSuSunTaeTakTanTangUUnWanWangWonYaYeongYeopYoYongYuYuk";
char pdb[42000]="AjinAjungAkAljiAnnaArangAseopBaekhoBaekhyeonBaeksuBangeonBangheonBangrinBangyongBauBaulBawiBeomgiBeomgonBeomgyeBeomhyeonBeomjuBeommoBeomsanBeoprinBinBingbingBinsonBogeunBogyeongBohuiBokgeoBokgiBokhyeonBokhyeongBongcheolBonggiBonggilBonggonBonghakBongilBongjuBongsuBongyeonBonneungBonsangBonyeongBoseonBoyeongBoyunBujinBuseongBusikByeongcheolByeongchunByeongdonByeonggwonByeonghoByeonghuByeonghuiByeonghyeonByeongjaeByeongjikByeongjoByeongjuByeongryeolByeongseokByeongsuByeonguByeongukByeongwiByeongwonChaeaChaewonChaeyeongChanChanbeopChanggeukChanggwonChanghyeonChangiChangilChangmuChangsikChangsonChangukChangwonChangyeongChangyongChanhyeonChanmiChansukChanukChanungChanyongCheolhwanCheoljuCheolminCheolsuCheolyongCheondeukCheongaCheongsuCheongwonCheonsikCheonsuChidoChijungChilseungChiwonChiyangChiyeolChiyongChorongChowonChulguChunChunggiChunggilChungiChungilChungseonChungsikChungsuChunhuiChunhwaChunhyangChunsaengChunseongDaegiDaegwanDaehoDaehuiDaejungDaemyeongDaerakDaeseongDaeseungDaesikDaesuDaeyongDahaeDahuiDaimDainDalhuiDalhwanDalhyeongDalsuDamDaniDanyeongDaranDaseongDayeongDeokbaeDeokgyuDeokhanDeokhoeDeokhuiDeokhunDeokhwaDeokhwanDeokimDeokjuDeokjukDeokseonDeoksulDeoksunDeukchulDeulimDingyoDoeonDogyeomDohaDohyangDongbinDongchanDonggapDonggeunDongguDonghanDonghunDonghwaDonghwanDonghyeokDonghyeonDongikDongjinDongjuDongjunDongminDongripDongseoDongseokDongsikDongsuDonguDongunDongyeolDongyeonDongyeopDoniDoraeDosunDuchiDugwanDujinDujunDunaDuokDupyoDuseokDusikDusunEokgiEoniEulnaEunaEunaeEunbeomEunbinEunbyeolEungchunEungduEungiEungmoEungnoEungryongEungseopEungsikEungwangEungyeongEungyoEunhaEunhoEuniEunjaeEunjeongEunjinEunjuEunjungEunryeongEunryulEunseoEunseongEunsuGaengyoGaeulGahyeGakgyuGamchanGamdoGaneGangchanGanggukGanghoGangminGangseokGangtoGangyongGapgyeongGapseongGapsuGaramGayeonGayunGeolryunGeomsuGeonGeonchangGeonhoGeonhuiGeonmoGeonpyeongGeonpyoGeukbaeGeukgyeomGeukjeungGeukyeongGeumseokGeumyeongGeunchanGeungyeonGeunhyeongGeunjiGeunpyoGeunyeongGeurinGiakGibeomGichanGigapGiguGiheungGihyeonGijeongGiljongGilseungGipyoGiriGiryongGiseokGisuGitaeGitaekGiuGiungGiwanGiyunGoengpilGokpaGonggeunGongjuGounGuGuanGuhanGuhongGukGukgangGukhyeonGukjinGukuiGumanGuraGwangakGwangcheolGwangeunGwanghongGwanghuiGwanghyeonGwangjoGwangjuGwangmoGwangnamGwanguGwangyeolGwangyeonGwansikGwansuGwanuGwanyeongGwijaGwinamGyeheungGyejuGyeongGyeongaeGyeongchanGyeongcheolGyeongeunGyeonggiGyeongguGyeonghakGyeongheumGyeonghuiGyeonghwaGyeongjaGyeongjaeGyeongjikGyeongjinGyeongjungGyeongmanGyeongmunGyeongpilGyeongrokGyeongsikGyeongsuGyeonguGyeongukGyeongwanGyeongwonGyeongyeongGyeongyeopGyeonuGyepaGyoanGyoikGyoilGyubaekGyubeomGyucheolGyudeokGyugapGyuheonGyuhoGyuhyeokGyuhyeonGyujeGyujinGyumanGyunamGyuokGyupyoGyuriGyuseolGyuseonGyuseongGyuseopGyuseungGyusuHaeHaechanHaechangHaejinHaejoHaemiHaenyeongHaeseokHaeseongHaesikHaesongHaesukHaesunHaeunHaewonHaeyeonHajinHakgyuHaknyeonHakryeolHakseoHakyeonHangiHangseoHangukHanhuiHanikHansangHansolHansuHanuiHarimHarinHayanHayeonHayeongHayunHeonchangHeonjaeHeonpyoHeonseongHeonseopHeunggiHeunggilHeungminHeungmunHeungpyoHeungyongHoechanHoguHogyeongHohyeonHojeHojeongHojunHojungHongeunHonggeunHongjeHongjiHongseokHongsikHosanHoseonHoseongHowonHoyeolHuiHuibeomHuichanHuicheolHuidoHuigyeongHuijaeHuijiHuijungHuipalHuipyoHuiraHuisangHuiseonHuiseopHuiseungHuisikHuisuHuiwonHuiyeonHunHunhyeonHunjeongHwanHwanduHwanghuHwangyuHwapyeongHwaseonHwayeongHwimanHyeinHyeokHyeokbinHyeokjunHyeonHyeonbinHyeoncheonHyeondeukHyeongbinHyeongboHyeongcheolHyeongdoHyeonggeunHyeonggonHyeonggwangHyeongilHyeongjiHyeongjinHyeongjunHyeongmoHyeongonHyeongryeolHyeongseokHyeongsikHyeongtaeHyeongukHyeongwonHyeongyuHyeonhoHyeonhoeHyeonhwakHyeonjeHyeonjongHyeonjungHyeonmanHyeonmoHyeonseonHyeonseongHyeonseopHyeonseungHyeonsilHyeonsuHyeonsukHyeontaeHyeontakHyeonyeongHyeranHyerimHyeryeonHyeseokHyeseonHyeseongHyesuHyesukHyewonHyocheonHyojeongHyojinHyomyeongHyoriHyoseongHyosinHyosukHyoyeonIbaeIcheomIgyeongIhwaIhyeonIkhuiIkjeomIkjungIkseonIlduIlguIlhuIlhwanIljunIlmokIlseongIlseungIlsunIluInaInbeomInbongInchangIncheomIncheonIndeukInguIngukIngwonInhaInhoInhuInhunInhwanI
char a[100],b[100];
map<string,int> ca,cb,da,db;
int cca=1,ccb=1,cda=1,cdb=1;
char sa[10010][100],sb[10010][100];
int ans[10010];
int pre[10010],pren;
int main(){
//    FILE *fp=fopen("train.txt","a+");
//    fclose(fp);
//    fp=fopen("train.txt","r");
//    int nn,len;
//    fscanf(fp,"%d",&nn);
//    for(int i=0;i<nn;++i){
//        fscanf(fp,"%s%s",a,b);
//        len=strlen(b);
//        b[len-4]=0;
//        if(b[len-1]=='n'){
//            if(!ca[a])ca[a]=cca++;
//            if(!cb[b])cb[b]=ccb++;
//        }else{
//            if(!da[a])da[a]=cda++;
//            if(!db[b])db[b]=cdb++;
//        }
//    }
//    fclose(fp);
//    for(auto i:cb){
//        printf("%s",i.first.c_str());
//    }
    int now=0,pos=0;
    char tmp[100];
    for(int i=0;i<338;++i){
        do{
            tmp[now++]=pca[pos++];
        }while(pca[pos]>'Z');
        tmp[now]=0;
        ca[tmp]=1;
        now=0;
    }
    now=0;pos=0;
    for(int i=0;i<1409;++i){
        do{
            tmp[now++]=pcb[pos++];
        }while(pcb[pos]>'Z');
        tmp[now]=0;
        cb[tmp]=1;
        now=0;
    }
    now=0;pos=0;
    for(int i=0;i<144;++i){
        do{
            tmp[now++]=pda[pos++];
        }while(pda[pos]>'Z');
        tmp[now]=0;
        da[tmp]=1;
        now=0;
    }
    now=0;pos=0;
    for(int i=0;i<1387;++i){
        do{
            tmp[now++]=pdb[pos++];
        }while(pdb[pos]>'Z');
        tmp[now]=0;
        db[tmp]=1;
        now=0;
    }
    int t;
    scanf("%d",&t);
    pren=t;
    for(int i=0;i<t;++i){
        scanf("%s%s",sa[i],sb[i]);
        pre[i]=i;
    }
    while(1){
        int cnt=0,en=pren;
        pren=0;
        for(int i=0;i<en;++i){
            if(pre[i]>=t || pre[i]<0)while(1);
            int fa=ca[sa[pre[i]]];
            int fb=cb[sb[pre[i]]];
            int ga=da[sa[pre[i]]];
            int gb=db[sb[pre[i]]];
            if(fa && !ga){
                ans[pre[i]]=0;
                if(!fb){
                    cb[sb[pre[i]]]=1;
                    ++cnt;
                }
            }else if(!fa && ga){
                ans[pre[i]]=1;
                if(!gb){
                    db[sb[pre[i]]]=1;
                    ++cnt;
                }
            }else if(fb && !gb){
                ans[pre[i]]=0;
                if(!fa){
                    ca[sa[pre[i]]]=1;
                    ++cnt;
                }
            }else if(!fb && gb){
                ans[pre[i]]=1;
                if(!ga){
                    da[sa[pre[i]]]=1;
                    ++cnt;
                }
            }else if((!fa && !ga)||(!fb && !gb)){
                pre[pren++]=pre[i];
            }
        }
        if(cnt==0)break;
    }
    for(int i=0;i<t;++i){
        printf("%s %s-%s\n",sa[i],sb[i],ans[i]?"ssi":"san");
    }
    return 0;
}

