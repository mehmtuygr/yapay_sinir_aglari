Bu proje, C/C++ kullanılarak geliştirilmiş bir yapay sinir ağı uygulamasıdır. Program, kullanıcıya grafik arayüz üzerinden veri noktaları ekleme, sinir ağı mimarisini belirleme, modeli eğitme ve sonuçları görselleştirme imkanı sunmaktadır.

Uygulama Windows Forms tabanlı bir arayüz kullanarak veri noktalarını iki boyutlu bir düzlem üzerinde göstermekte ve eğitim sonrası modelin sınıflandırma veya regresyon sonuçlarını görsel olarak sunmaktadır.

Projenin Amacı

Bu projenin temel amacı:

Yapay sinir ağlarının çalışma mantığını düşük seviyeli programlama ile göstermek

Sinir ağı eğitim sürecini görselleştirmek

Kullanıcının kendi veri noktalarını ekleyerek modeli eğitebilmesini sağlamak

Sınıflandırma ve regresyon problemlerinin nasıl çözüldüğünü göstermek

Özellikler

Uygulama aşağıdaki özellikleri içermektedir:

Grafik arayüz üzerinden veri noktası ekleme

Birden fazla sınıf ile sınıflandırma yapabilme

Katman ve nöron sayısını kullanıcı tarafından belirleyebilme

Eğitim sürecinde hata grafiğinin gösterilmesi

Eğitim sonrası karar sınırlarının görselleştirilmesi

Veri ve model ağırlıklarını dosyaya kaydetme

Dosyadan veri ve ağırlık yükleme

Sinir Ağı Yapısı

Projede çok katmanlı bir yapay sinir ağı (Multi Layer Neural Network) kullanılmaktadır.

Sinir ağı aşağıdaki katmanlardan oluşmaktadır:

Giriş katmanı

Bir veya daha fazla gizli katman

Çıkış katmanı

Modelde ileri besleme (Forward Propagation) ve geri yayılım (Backpropagation) algoritmaları kullanılarak eğitim yapılmaktadır.

Eğitim Süreci

Model eğitimi sırasında aşağıdaki işlemler gerçekleştirilir:

Veri setinin normalize edilmesi (Z-score normalization)

İleri besleme ile çıktı hesaplanması

Hata değerinin hesaplanması

Geri yayılım ile ağırlıkların güncellenmesi

Momentum yöntemi ile öğrenmenin hızlandırılması

Eğitim sırasında hata değeri grafik üzerinde gösterilmektedir.

Kullanım

Program çalıştırıldıktan sonra aşağıdaki adımlar izlenir:

Network Architecture bölümünden sınıf sayısı ve katman sayısı belirlenir.

Her katmandaki nöron sayısı girilir.

Grafik alanına mouse ile veri noktaları eklenir.

Training seçeneği ile model eğitilir.

Testing seçeneği ile model çıktıları görselleştirilir.

Dosya İşlemleri

Program veri ve model parametrelerini dosyaya kaydedebilir veya dosyadan yükleyebilir.

Samples.txt → Veri noktaları ve etiketleri

weights.txt → Sinir ağı ağırlıkları ve bias değerleri

Kullanılan Teknolojiler

C / C++

Windows Forms (C++/CLI)

Visual Studio

Grafik görselleştirme

Proje Yapısı
project/
│
├── Form1.h
├── Process.h
├── Data/
│   ├── Samples.txt
│   └── weights.txt
└── README.md