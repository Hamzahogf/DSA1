#include <iostream>
#include <string>
void natur(int i){
    std::cout<<i<< " ";
    i++;
     if (i<=50)
     {
        natur(i);
     }
 
}
int sum_N(int N) {
    if (N == 1) {
        return 1;  // Base case
    } else {
        return N + sum_N(N - 1);  // Recursive case
    }
}
int HCF(int m , int n){
    if(m<n){
        if(n-m==1 || n-m==-1){
            return 1;
        } else if(n-m==m || n-m==-m){
            return m;
        } else {
            return HCF(m, n-m);
        }
    }
}
int power(int A , int B){
    if(B==1){
     return A;
    } else {
        return A*power(A, B-1);
    }
}
bool power_2(int A) {
    if (A == 1) {
        return true;  
    } else if (A % 2 == 0) {
        return power_2(A / 2);
    } else {
        return false;
    }
}

int max_arr(int A[], int n) {
    int i = 0;
    do {
        i++;
    } while (i < n && A[0] >= A[i]);

    if (i == n) {
        return A[0];  
    } else {
        int B[n - 1];
        for (int j = 1; j < n; j++) {
            B[j - 1] = A[j];
        }
        return max_arr(B, n - 1);
    }
}
int countDigits(int N) {
    if (N < 10) {
        return 1;
    } else {
        return 1 + countDigits(N / 10);
    }
}
int countsum(int N){
  if(countDigits(N)==1){
    return N;
  } else {
    return countsum(N%10)+countsum(N/10);
  }
}
int countsumsum(int N) {
    if (N < 10) {
        return N;
    } else {
        return countsumsum(countsum(N));
    }
}
std::string reverse(const std::string S) {
    int size = S.size();
    if (size == 2) {
        std::string reversed = S;
        std::swap(reversed[0], reversed[1]);
        return reversed;
    } else {
        char N = S[0];
        std::string T = S.substr(1);

        return reverse(T) + N;
    }
}
int Binom_coff(int n , int k){
    if (k==n || k==0 )
    {
     return 1;
    }else if (k==1)
    {
        return n;
    } else {
        return Binom_coff(n-1 , k-1)+Binom_coff(n-1 , k);
    }

    
}
std::string quick_sort(std::string& s){
    int size=s.size();
    if(size==1){
        return s;
    } else if (size==2){
       if (s[0]<s[1])
       {
        return s;
       } else if(s[0]>s[1]) {
        std::swap(s[0] , s[1]);
        return s;
       }
       
    } else if (size==3)
    {
        int pivot=s[size-1];
        int i=0 , j=size-2;
        if (s[i]>pivot && s[j]<pivot)
        {
            std::swap(s[i] , s[j]);
            return s;
        } else if (s[i]<pivot && s[j]<pivot)
        {
            return s;
        } else if (s[i]>pivot && s[j]>pivot)
        {
            std::swap(s[size] , s[i]);
            return s;
        } else if (s[i]<pivot && s[j]>pivot)
        {
            std::swap(s[size-1] , s[j]);
            return s;
        }
        
    } else {
                
        int pivot=s[size-1];
        int i=0 , j=size-2; 
        while (i<=j)
        {
           if(s[i]>pivot && s[j]<pivot){
             std::swap(s[i] , s[j]);
           } else if(s[i]>pivot && s[j]>pivot){
              do
              {
                j--;
              } while (s[i]>pivot && s[j]>pivot);
                if( i<=j  && (s[i]>pivot && s[j]<pivot)){
                  std::swap(s[i] , s[j]);
                } else if(i>j){
                    std::swap(s[size-1] , s[i+1]);

                }
                 else if (s[i]<pivot && s[j]<pivot){
                  do
                  {
                 j--;
                   } while (s[i]<pivot && s[j]<pivot);
                  if( i<=j  && (s[i]>pivot && s[j]<pivot)){
                   std::swap(s[i] , s[j]);
                  } else if(i>j){
                    std::swap(s[size-1] , s[i+1]);
                     
                 }
               }
            } else if (s[i]<pivot && s[j]>pivot)
            {
              continue;
            } else if (s[i]<pivot && s[j]<pivot)
            {
                /* code */
            }
            
             i++;
             j--;

            }
              std::swap(s[size-1] , s[i+1]);

            std::string A=s.substr(0 , i);
            std::string B=s.substr(i+2 , size);
            if(i+1==size){
                return quick_sort(A)+s[i+1];
            } else if (i+1==0)
            {
                return s[i+1]+quick_sort(B);
            } else {
                return quick_sort(A)+s[i+1]+quick_sort(B);
            }
            
          }
}
        

int main() {

    int A[] = {11, 10, 13, 18, 8};
    int maxElement = max_arr(A, 5);
    std::cout << "Max Element: " << maxElement << std::endl;

    int num = 1235;
    int digits = countDigits(num);
    std::cout << "Number of Digits: " << digits << std::endl;

    int sumOfDigits = countsum(num);
    std::cout << "Sum of Digits: " << sumOfDigits << std::endl;

    int sumOfSums = countsumsum(num);
    std::cout << "Sum f S Digits: " << sumOfSums << std::endl;

    std::string S;
    std::cin >> S;

    std::string R = reverse(S);
    std::cout << "Reversed String: " << R << std::endl;
    int n=8 , k=3;
    int b=Binom_coff(n , k);
    std::cout<<b<<std::endl;
  std::string K;
  std::cin>>K;
  std::cout<<K.size()<<std::endl;
    std::string op=quick_sort(K );
    std::cout<<op<<std::endl;
    return 0;
}