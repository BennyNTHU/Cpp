/* 盽篈だガ 
   秨祇:Benny Lee
   2017/10/15 材  
   各―み陆亩Θ璣ゅ */ 

#include <iostream>
#include <iomanip>	// 块Α 
#include <cmath>	// 计厩ㄣ 

#define PI 3.141593
#define E 2.7182818

using namespace std;

float P_density_function ( float );	//诀瞯盞ㄧ计琌疊翴计跑计數 
float define_integral ( float );	//﹚縩だㄧ计琌才翴计跑计數 

int main()
{	
	cout<<"盽篈だ嘿蔼吹だガ,冈薄叫琩蝴膀κ\n"
		<<"и胕眔毙la\n"
		<<"セ祘Α盢甶ボ盽篈だ,叫盢跌怠┰糴\n"
		<<"ぃ礛穦纞もも"<<endl;
	system("PAUSE"); 
	
	/*盽篈だ材,zだ计计翴材*/ 
	cout<<"Z\t";
	for ( int i = 0 ; i <= 9 ; i++ )
		cout<<i<<'\t';
	cout<<endl;
	
	/*盽篈だセ砰*/ 
	float i, var; //i绢,zだ计计翴材;var材︽,zだ计俱计籔计翴材 
		for ( var = 0.0 ; var <= 3.9 ; var += 0.1 )
		{
			/* 块俱计计翴材绢秨繷 */ 
			cout << setprecision(1) << setiosflags(ios::fixed|ios::showpoint)
				 << var <<'\t'; 
				 
			/* 块眖キА计縩だz﹚縩だ */ 
			for ( i = 0 ; i <= 9 ; i++ )
			{
				cout << setprecision(4) <<setiosflags(ios::fixed|ios::showpoint)
					 << define_integral( var + i * 0.01 ) << '\t' ;  // ―赣ぇ,ㄤいvar+i*0.01﹚縩だ 
			}
			
			cout<<endl;
		}
		
	system("PAUSE");
	return 0;
} 

/* ﹚縩だㄧ计數*/ 
float define_integral( float z )	//對癸诀瞯盞ㄧ计秈︽﹚縩だ 
{
	float farea;
	float fsum;
	
	for (float decimal = 0 ; decimal <= z ; decimal += 0.01 ) //decimal琌诀瞯盞ㄧ计跑计x,―兢耙㎝ぇ患癹筁祘 
	{
		if (decimal == 0)
			fsum = 0 ;
		else 
		{
			farea = 0.01 * P_density_function ( decimal );	//璸衡遏縩,砞诀瞯盞ㄧ计ぇ跑计x=decimal帶入 
			fsum += farea;	//璸衡兢耙㎝ 
		}
		
	}
	return fsum;	// 肚兢耙㎝倒祘Α 
}

/*機诀瞯盞ㄧ计數*/ 
float P_density_function( float x )	//跑计x琌﹚縩だㄧ计い砞﹚decimal
{	
	float fexpo;	
	float frate;
	
	fexpo = - ( pow ( x , 2 ) ) / 2 ;	//矪瞶计场だ 
	frate  = ( 1 / sqrt( 2 * PI ) ) * pow( E , fexpo );	//诀瞯盞ㄧ计ぇy畒夹,赣计诀瞯盞ㄧ计い┮ゑㄒ 
	
	return frate;	//傳肚y畒夹frate(種竡赣计┮ゑㄒ)倒﹚縩だㄧ计 
}


