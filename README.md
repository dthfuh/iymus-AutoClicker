# IYMUS CLICKER

Terminalde çalışan, ayarlanabilir bir otomatik tıklayıcı (autoclicker).

## İndirme ve Çalıştırma
1. [Releases](../../releases) sayfasından `iymus_clicker.exe` dosyasını indir.
2. Çift tıklayarak çalıştır. Kurulum veya derleme gerekmez.

## Antivirüs Uyarısı
Program fare tıklaması simüle ettiği için bazı antivirüsler (Windows Defender dahil) yanlışlıkla zararlı olarak işaretleyebilir. Bu bir **yanlış pozitiftir**; program herhangi bir zararlı işlem yapmaz.
- Kaynak kodun tamamı bu repoda açık olarak bulunuyor, istediğin zaman inceleyebilirsin.
- Windows SmartScreen uyarısında "Daha fazla bilgi" → "Yine de çalıştır" seçeneğini kullanabilirsin.

## Özellikler
- Sol ve sağ tık desteği
- Aralığı ayarlanabilir tıklama
- Açma ve kapatma işlemi
- Tuş ataması
- Türkçe arayüz

## Gereksinimler
- Windows

## Kaynak Koddan Derleme (isteğe bağlı)
```
g++ auto.cpp -o iymus_clicker.exe -static
```

## Bilinen Sorunlar
- Yapılan ayarlar program kapatılınca kayboluyor.
- Şu an sadece Türkçe dil desteği var.

## Yapılacaklar
- [ ] Ayarların dosyaya kaydedilmesi
- [ ] Çoklu dil desteği

## Sürüm
v1.0 (ilk sürüm)