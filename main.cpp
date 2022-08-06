#include <iostream>
#include <random>
//#include <string.h>

using namespace std;

int main()
{
  int cardnum;//カードの番数
  int playerjudge;//チェンジの実行
  int change;//チェンジ実行の意思
  int playercount;//交換する枚数
  int playernum;//交換する番数
  int tmp;//数用の空箱
  char ctmp;//カテゴリー用の空箱
  char category[4]={'H','D','C','S'};//カテゴリー
  int num[13]={1,2,3,4,5,6,7,8,9,10,11,12,13};//数
  int nstr[5];//手札のカードのそれぞれの数
  char cstr[5];//手札のカードのそれぞれのカテゴリー
  int numcount;//手札の数の配布
  char num_result;//手札の数が１，１１，１２，、１３の場合、文字に置き換える
  int scount;//ストレートの判定
  int fcount;//フラシュの判定
  int jcount;//役のカウント
  int categorycount;//手札のカテゴリーの配布

  srand((unsigned int)time(NULL));
  
  //配布
    for(cardnum=0;cardnum<=4;cardnum++)
    {
      numcount=rand()%13+1;
      categorycount=rand()%4;
      nstr[cardnum]=numcount;
      cstr[cardnum]=category[categorycount];
      //配布したカードが前のカードかぶっていたら変更する
      if(cardnum>1)
      {
        for(int count=0;count<=cardnum;count++)
          {
            if(cstr[count]==cstr[count-1])
              {
              if(nstr[count]==nstr[count-1])
              {
                if(cstr[count]==cstr[count-1])
                {
                  if(count<3)
                  {
                    count++;
                  }
                  else
                  {
                    count-=rand()%3+1;
                  }
                cstr[count]=cstr[count];
                }
              }
            }
          }
        }
      nstr[cardnum]=numcount;
      cstr[cardnum]=category[categorycount];
        switch(numcount)
        {
          case 1:
          cout<<cstr[cardnum]<<":"<<'A'<<endl; 
          break;
          case 11:
          cout<<cstr[cardnum]<<":"<<'J'<<endl; 
          break;
          case 12:
          cout<<cstr[cardnum]<<":"<<'Q'<<endl; 
          break;
          case 13:
          cout<<cstr[cardnum]<<":"<<'K'<<endl; 
          break;
          default:
          cout<<cstr[cardnum]<<":"<<nstr[cardnum]<<endl;
          break;
        }   
      }
  cout<<endl;
  //交換
    for(int i=0;i<=4;i++)
    {
      numcount=nstr[i];
        switch(numcount)
        {
          case 1:
          cout<<cstr[i]<<":"<<'A'<<endl; 
          break;
          case 11:
          cout<<cstr[i]<<":"<<'J'<<endl; 
          break;
          case 12:
          cout<<cstr[i]<<":"<<'Q'<<endl; 
          break;
          case 13:
          cout<<cstr[i]<<":"<<'K'<<endl; 
          break;
          default:
          cout<<cstr[i]<<":"<<nstr[i]<<endl;
          break;
        }
      cout<<"交換しますか？（１：yes  ２：no）";
      cin>>change;
      if(change==1)
      {
        int p;
        p=rand()%10;
        if(p>=7)
        {
          nstr[i]=p;
        }
        int y;
        y=rand()%4;
        cstr[i]=category[y];
      }
  switch(numcount)
        {
          case 1:
          cout<<cstr[i]<<":"<<'A'<<endl; 
          break;
          case 11:
          cout<<cstr[i]<<":"<<'J'<<endl; 
          break;
          case 12:
          cout<<cstr[i]<<":"<<'Q'<<endl; 
          break;
          case 13:
          cout<<cstr[i]<<":"<<'K'<<endl; 
          break;
          default:
          cout<<cstr[i]<<":"<<nstr[i]<<endl;
          break;
        }
cout<<endl;
    }

  //最終的な手札の開示
for(int i=0;i<=4;i++)
  {
    numcount=nstr[i];
      switch(numcount)
        {
          case 1:
          cout<<cstr[i]<<":"<<'A'<<endl; 
          break;
          case 11:
          cout<<cstr[i]<<":"<<'J'<<endl; 
          break;
          case 12:
          cout<<cstr[i]<<":"<<'Q'<<endl; 
          break;
          case 13:
          cout<<cstr[i]<<":"<<'K'<<endl; 
          break;
          default:
          cout<<cstr[i]<<":"<<nstr[i]<<endl;
          break;
        }
  }

  //役のジャッジ
  if(scount==5)
  {
    cout<<"この役はストレートです。"<<endl;
    jcount+=1;
  }
  if(fcount==5)
  {
    cout<<"この役はフォーカードです。"<<endl;
    jcount+=1;
  }
  if(cstr[0]==cstr[1]==cstr[2]==cstr[3]==cstr[4])
  {
    cout<<"この役はフラッシュです。"<<endl;
    jcount+=1;
  }
  if(jcount<=0)
  {
    cout<<"この役はブタです。"<<endl;
  }
}