
// ANIL AKSU 230103020

#include <iostream>
#include <cstdlib>

using namespace std; 

int main() {
	const int nm_ofstudents = 5; //öğrenci sayısı
	const int nm_ofquestions = 8; //test(soru) sayısı
	const double pointsper_question = 12.5; // 100/8 den soru başı 12.5 puan kazanılır.
	char correctanswers[nm_ofquestions] = { 'A' , 'E' , 'C' , 'D' , 'B' , 'A' , 'C' , 'D' }; //cevapları tutan karakter dizisi

	char** useranswers = new char* [nm_ofstudents]; //kullanıcı cevaplarını alan iki boyutlu dinamik bellek yönetimi ile dizi tanımlıyoruz (öğrenci sayısı kadar)
	double* totalscore = new double[nm_ofstudents]; // her bir öğrenci için toplam skoru belirten dizi tanımlıyoruz. Dinamik bellek yönetimi ile.

	for (int i = 0; i < nm_ofstudents; i++) {
		useranswers[i] = new char[nm_ofquestions]; //her öğrenci için 8 test tanımlatıyoruz.
		totalscore[i] = 0; //ilk değer ataması yapılır.
	}

	for (int i = 0; i < nm_ofstudents; i++) { //kullanıcıdan verileri alıyoruz.
		cout << "Student " << (i + 1) << " Enter the answers:\n";
		for (int j = 0; j < nm_ofquestions; j++) {
			cout << "Question " << (j + 1) << " Enter the answers (A/B/C/D/E): ";
			cin >> useranswers[i][j];

			while (useranswers[i][j] != 'A' && useranswers[i][j] != 'B' && useranswers[i][j] != 'C' && useranswers[i][j] != 'D' && useranswers[i][j] != 'E') {
				cout << "You entered invalid value! Please re-enter one of the options of A , B , C , D or E: ";
				cin >> useranswers[i][j]; //tek tek kontrol edip yanlışsa cevap döndürüyoruz. ve tekrardan kullanıcıdan sonuç verisini alıyoruz.
			}
		}
	}
	 
	for (int i = 0; i < nm_ofstudents; i++) { //cevapların doğruluğunu kontrol ediyoruz.
		for (int j = 0; j < nm_ofquestions; j++) {
			if (useranswers[i][j] == correctanswers[j]) {
				totalscore[i] += pointsper_question;
			}
		}
	}

	cout << "\nStudent test results: " << endl; //sonuçları ekrana yazdırıyoruz.
	for (int i = 0; i < nm_ofstudents; i++) 
	{	
		cout << "Student : " << (i + 1) << " Total Score: " << totalscore[i] <<  " / 100" << endl;
	}

	for (int i = 0; i < nm_ofstudents; i++) { //her bir öğrenci için belleği serbest bırakıyoruz
		delete[] useranswers[i];
	}

	delete[] useranswers; //useranswers için ana kısmı serbest bırakıyoruz.
	delete[] totalscore; //totalscore için ana kısmı serbest bırakıyoruz.


	return 0;

} 