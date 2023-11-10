using namespace std;
using ll = long long;
#include <bits/stdc++.h>
#include <iostream>

ll Pow_mod ( ll a , ll b, ll n ) {  
    ll power = 1 , i ;  
    for ( i = 1 ; i <= b ; i++) {  
        power = power * a ;
        power = power % n; 
    }  
    return power ;  
} 

int main() {
    int reverse, temp;
   ll n,coprime_numbers_with_n = 0, e, d, encrypted_code_letter, decrypted_code_letter; 
   string encrypted_message, message; 
   vector<ll>  encrypted_messages_vec; 
   vector<int>  decrypted_codes_vec; 
   vector<int> decrypted_messages_vec;
   
   
   cout << "Please enter n value (from the public key)" << endl;
   cin >>  n; 
   
   cout << "Please enter e value (from the public key)" << endl;
   cin >>  e; 
   
   for(ll i = 1; i <n;i++){
       if(__gcd(i,n) == 1){
               coprime_numbers_with_n++;
       }
   }
   cout << "Please enter the encoded message with the spaces" << endl; 
   cin.ignore();
   getline(cin,encrypted_message);
   
   
     
  stringstream ss(encrypted_message);
    
    while (ss >> temp) {
        encrypted_messages_vec.push_back(temp);
        ss.ignore();
    }
    
    for(ll i = 2; i <coprime_numbers_with_n; i++){
        if( ((i*e) % coprime_numbers_with_n == 1) ){
            d = i;
            break;
        }
    }

     /* Start Decryption  Section */ 
    for (int i = 0; i < encrypted_messages_vec.size(); i++){
        decrypted_code_letter = Pow_mod(encrypted_messages_vec[i], d, n);
        decrypted_codes_vec.push_back(decrypted_code_letter);
    }
    
     for(int i = 0; i < decrypted_codes_vec.size();i++){
            reverse = decrypted_codes_vec[i];
            decrypted_messages_vec.push_back(reverse);
    }
    
    for(int i = 0; i < decrypted_messages_vec.size();i++){
         message += char (decrypted_messages_vec[i]);
    }
    cout << "The message is that " << message << endl;
  /*End Decryption  Section*/

}