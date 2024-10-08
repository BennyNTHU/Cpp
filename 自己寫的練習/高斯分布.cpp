/* 常態分布表 
   開發者:Benny Lee
   2017/10/15 第二版  
   跪求好心人士翻譯成英文 */ 

#include <iostream>
#include <iomanip>	// 輸出格式 
#include <cmath>	// 數學工具 

#define PI 3.141593
#define E 2.7182818

using namespace std;

float P_density_function ( float );	//宣告機率密度函數乃是以一浮點數為自變數�� 
float define_integral ( float );	//定積分函數是以符點數為自變數�� 

int main()
{	
	cout<<"常態分佈又稱為高斯分布,詳情請自己查維基百科\n"
		<<"我懶得教你la\n"
		<<"本程式將展示常態分佈表,請先將視窗拉寬\n"
		<<"不然你會嚇到吃手手"<<endl;
	system("PAUSE"); 
	
	/*先印出常態分佈表第一列,即z分數小數點以下第二位*/ 
	cout<<"Z\t";
	for ( int i = 0 ; i <= 9 ; i++ )
		cout<<i<<'\t';
	cout<<endl;
	
	/*印出常態分佈表本體*/ 
	float i, var; //i為橫列,即z分數小數點以下第二位;var為第一行,即z分數整數位與小數點以下第一位 
		for ( var = 0.0 ; var <= 3.9 ; var += 0.1 )
		{
			/* 輸出整數位小數點以下第一位為橫列開頭 */ 
			cout << setprecision(1) << setiosflags(ios::fixed|ios::showpoint)
				 << var <<'\t'; 
				 
			/* 輸出從平均數積分到z的定積分值 */ 
			for ( i = 0 ; i <= 9 ; i++ )
			{
				cout << setprecision(4) <<setiosflags(ios::fixed|ios::showpoint)
					 << define_integral( var + i * 0.01 ) << '\t' ;  // 求該格之值,其中var+i*0.01代表定積分的上界 
			}
			
			cout<<endl;
		}
		
	system("PAUSE");
	return 0;
} 

/* 定積分函數��*/ 
float define_integral( float z )	//�此嚝鰷v密度函數進行定積分 
{
	float farea;
	float fsum;
	
	for (float decimal = 0 ; decimal <= z ; decimal += 0.01 ) //decimal是機率密度函數的變數x,代表求黎曼和之遞迴過程 
	{
		if (decimal == 0)
			fsum = 0 ;
		else 
		{
			farea = 0.01 * P_density_function ( decimal );	//計算一小塊的面積,此時設機率密度函數之自變數x=decimal代入�庇� 
			fsum += farea;	//計算黎曼和 
		}
		
	}
	return fsum;	// 傳回黎曼和給主程式 
}

/*�C機率密度函數��*/ 
float P_density_function( float x )	//自變數x是定積分函數中設定的decimal
{	
	float fexpo;	
	float frate;
	
	fexpo = - ( pow ( x , 2 ) ) / 2 ;	//處理指數部分 
	frate  = ( 1 / sqrt( 2 * PI ) ) * pow( E , fexpo );	//再列出機率密度函數之y座標,即該數值在機率密度函數中所佔的比例 
	
	return frate;	//�鰶レ^y座標frate(意義為該數值所佔的比例)給定積分函數 
}


