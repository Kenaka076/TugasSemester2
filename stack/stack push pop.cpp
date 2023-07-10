#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool periksaTandaKurung(string inputStr) {
    stack<char> delimiterStack;  // buat sebuah stack bernama delimiterStack
    
    /* operasi yang dapat digunakan pada delimiterStack: 
	 * void delimiterStack.push(c); 	// push elemen c ke stack
	 * void delimiterStack.pop();		// pop elemen dari stack
	 * char delimiterStack.top();		// ambil elemen paling atas dari stack
	 * bool delimiterStack.empty();		// cek apakah stack berisi atau kosong, true=berisi, false=kosong
	 */
    
    //  ambil setiap karakter dari string inputStr ke variable c, lakukan perulangan sampai semua karakter diproses
    for (int i = 0; i < inputStr.length(); i++) {
        char c = inputStr[i];
	// jika c adalah karakter '(' , '[', atau '{', maka masukan c ke delimiterStack
		
        if (c == '(' || c == '[' || c == '{') 

        {
            delimiterStack.push(c);
            
    // jika c adalah karakter ')' , ']', atau '}', maka lakukan tahapan pengecekan berikut:
        } else if (c == ')' || c == ']' || c == '}') 
		
		// Jika delimiterStack kosong, maka tanda kurung buka tidak ada di stack, sehingga pasangan tanda kurung salah (return false)
		{
            if (delimiterStack.empty()) 
            {
                return false; // Tanda kurung buka tidak ada di stack
            }
		//  Ambil elemen teratas dari delimiterStack
            char top = delimiterStack.top();
                        
        // Jika elemen teratas sesuai dengan pasangan karakter c, maka pop delimiterStack
			if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{')) 
			{
				delimiterStack.pop();
			}
			
		// Jika elemen teratas tidak sesuai dengan pasangan karakter c, maka tanda kurung buka dan tutup tidak sesuai (return false)
			else 
			{
				return false; // Tanda kurung buka dan tutup tidak sesuai
			}
        }
    }
    // setelah semua karakter inputStr diproses, periksa apakah masih ada elemen di delimiterStack.
    if (!delimiterStack.empty()) 
    
    //  jika masih ada elemen dalam delimiterStack, maka masih ada tanda kurung buka atau tutup yang tidak ada pasangannya (return false)
    	{
        return false; // Tanda kurung buka atau tutup tidak memiliki pasangan
   	    }
     //  jika tidak ada elemen dalam delimiterStack, maka semua tanda ada pasangannya (return true) 
        {
        return true; // Semua tanda kurung buka dan tutup memiliki pasangan
        }
    
    return delimiterStack.empty(); // Memeriksa apakah masih ada tanda kurung buka yang tidak memiliki pasangan
}

int main() {
    string inputStr;
    cout << "Masukkan ekspresi dengan tanda kurung: ";
    cin >> inputStr;

    bool sesuai = periksaTandaKurung(inputStr);
    if (sesuai) {
        cout << "Tanda kurung buka dan tutup sesuai." << endl;
    } else {
        cout << "Tanda kurung buka dan tutup tidak sesuai." << endl;
    }

    return 0;
}
