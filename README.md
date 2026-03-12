## Proje Hakkında

Bu proje, C/C++ kullanılarak geliştirilmiş bir yapay sinir ağı uygulamasıdır. Program, kullanıcıya grafik arayüz üzerinden veri noktaları ekleme, sinir ağı mimarisini belirleme, modeli eğitme ve sonuçları görselleştirme imkanı sunmaktadır.

Uygulama Windows Forms tabanlı bir arayüz kullanarak veri noktalarını iki boyutlu bir düzlem üzerinde göstermekte ve eğitim sonrasında modelin sınıflandırma veya regresyon sonuçlarını görsel olarak sunmaktadır.

## Projenin Amacı

Bu projenin temel amacı:

- Yapay sinir ağlarının çalışma mantığını düşük seviyeli programlama ile göstermek
- Sinir ağı eğitim sürecini görselleştirmek
- Kullanıcının kendi veri noktalarını ekleyerek modeli eğitebilmesini sağlamak
- Sınıflandırma ve regresyon problemlerinin nasıl çözüldüğünü göstermek

## Özellikler

Uygulama aşağıdaki özellikleri içermektedir:

- Grafik arayüz üzerinden veri noktası ekleme
- Birden fazla sınıf ile sınıflandırma yapabilme
- Katman ve nöron sayısını kullanıcı tarafından belirleyebilme
- Eğitim sürecinde hata grafiğinin gösterilmesi
- Eğitim sonrası karar sınırlarının görselleştirilmesi
- Veri ve model ağırlıklarını dosyaya kaydetme
- Dosyadan veri ve model parametrelerini yükleyebilme

## Sinir Ağı Yapısı

Projede çok katmanlı bir yapay sinir ağı (Multi Layer Neural Network) kullanılmaktadır.

Sinir ağı aşağıdaki katmanlardan oluşmaktadır:

- Giriş Katmanı (Input Layer)
- Gizli Katmanlar (Hidden Layers)
- Çıkış Katmanı (Output Layer)

Modelde ileri besleme (Forward Propagation) ve geri yayılım (Backpropagation) algoritmaları kullanılarak eğitim yapılmaktadır.

## Eğitim Süreci

Model eğitimi sırasında aşağıdaki işlemler gerçekleştirilmektedir:

1. Veri setinin normalize edilmesi (Z-Score normalization)
2. İleri besleme ile çıktıların hesaplanması
3. Hata değerinin hesaplanması
4. Geri yayılım algoritması ile ağırlıkların güncellenmesi
5. Momentum yöntemi ile öğrenmenin hızlandırılması

Eğitim süreci sırasında hata değerleri grafik üzerinde gösterilmektedir.

## Kullanım

Program çalıştırıldıktan sonra aşağıdaki adımlar izlenir:

1. **Network Architecture** bölümünden sınıf sayısı ve katman sayısı belirlenir.
2. Her katman için nöron sayısı girilir.
3. Grafik alanına mouse ile veri noktaları eklenir.
4. **Training** seçeneği ile model eğitilir.
5. **Testing** seçeneği ile modelin sonuçları görselleştirilir.

## Dosya İşlemleri

Program veri ve model parametrelerini dosyaya kaydedebilir veya dosyadan yükleyebilir.

- `Samples.txt` → Veri noktaları ve etiketleri
- `weights.txt` → Sinir ağı ağırlıkları ve bias değerleri

## Kullanılan Teknolojiler

- C / C++
- Windows Forms (C++/CLI)
- Visual Studio
- Grafik görselleştirme
