#include <iostream>
#include <string>
const int MAX_COL=Max_ROW=MAX=100;
void MatrixText( std::string Mat[][MAX_COL] ,int &Row_size , int Col_size[]){
     for(int i=0 ; i<Row_size ; i++){
        for(int j=0 ; j< ; j++){
            std::getline(std::cin , Mat[i][j]);
            for(char ch : M[i][j] ){
                 if(!isalpha(ch)){
                    M[i][j].erase(ch , 1);
                 }
            }
            
                }
            }    
    for(int i=0 ; i<Row_size ; i++){
        for(int j=0 ; j< ; j++){
            std::getline(std::cin , Mat[i][j]);
            for(char ch : M[i][j] ){
                 if(ch==' '){
                    M[i][j].substr(ch , 1);
                    Col_size[]
                 }
            }
            
                }
            }       


}

void DislayMatrix(std::string Mat[][MAX_COL] ,int &Row_size , int Col_size[] ){
    for(int i=0 ; i<Row_size ; i++){
        for(int j=0 ; j< ; j++){
               std::cout<<Mat[i][j]<<" ";
            }
            std::cout<<std::endl;
            
   }
}    

void ShrtestWord(std::string Mat[][MAX_COL] , int &Row_size , int Col_size[]){
    int short=Mat[0][0].size();
    std::string short_sent=Mat[0][0];
    for(int i=0 ; i<Row_size ; i++){
        for(int j=0 ; j< ; j++){
             if(short<Mat[i][j].size()){
                short=Mat[i][j].size();
                short_sent=Mat[i][j];
             }
            }
            
            
   }
   std::cout << short_sent<<std::endl;

}

void Unique(std::string Mat[][MAX_COL] ,int &Row_size , int Col_size[]){

}


int main(){
  std::string Mat[Max_ROW][MAX_COL] ;
  int Col_size[MAX];
  int Row_size;
  std::cin <<Row_size;
  MatrixText[Mat , Row_size , Col_size];
  DislayMatrix[Mat , Row_size , Col_size];
  short_sent[Mat , Row_size , Col_size];
  Unique[Mat , Row_size , Col_size];
  return 0;
}

    