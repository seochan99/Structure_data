#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
//    int age = 12; // 자료형 작성
//    age = 123;
//    printf("%d \n", age);
//
//    float f = 45.6f;
//    printf("%.2f \n",f);
//    double d = 4.427;
//    printf("%.3lf\n",d);
    
//    const int YEAR = 2000;
//    printf("태어난 년도 : %d \n",YEAR);
    
    //printf
    //연산
//    int add = 3+7;
//    printf("3+7=%d\n",add);
//    printf("%d + %d = %d\n",3,7,add);
    
    //scanf
//    int input;
//    printf("값을 입력하세여 : ");
//    scanf("%d",&input);
//    printf("입력값 : %d \n",input);
//    int one,two,three;
//    printf("3개의 정수를 입력하세요 ");
//    scanf("%d %d %d\n",&one,&two,&three);
//    printf("첫번째 값 : %d\n",one);
//    printf("첫번째 값 : %d\n",two);
//    printf("첫번째 값 : %d\n",three);
    
        //문자(한글자) , 문자열(한 글자 이상의 여러 글자)
//    char c = 'A';
//    printf("%c\n",c);
//
//    char str[256];
//    scanf("%s",str,sizeof(str));
//    printf("%s\n",str);

    //project - 1
    // 경찰관이 범죄자의 정보를 입수
    // ㅇ름? 나이? 몸무게 ? 키, 범죄명 을 물어봄
//    char name[256];
//    printf("what is u r name?");
//    scanf("%s",name,sizeof(name));
//
//    int age;
//    printf("age ?");
//    scanf("%d",&age);
//
//    float weight;
//    printf("Weight?");
//    scanf("%f",&weight);
//
//    double height;
//    printf("Height?");
//    scanf("%lf",&height);
//
//    char what[257];
//    printf("crime?");
//    scanf("%s",what,sizeof(what));
//    printf("\n\n 범죄정보 \n\n");
//    printf("name : %s\n",name);
    
//    int a = 10;
//    printf("a is %d\n",a++);
//    a++;
//    printf("a is %d\n",++a);
    
    //반복문
    // for, do while , while
//    for(int i=1;i<=10;i++)
//    {
//        printf("Hello %d 번쨰\n",i);
//    }
//    int i= 1;
//    while(i<=10){
//        printf("hello %d\n",i);
//        i++;
//    }
    
    // do while
//    int i = 1;
//    do{
//                printf("hello %d\n",i);
//                i++;
//    }while(i<=10);


//2중 반복문
//    for(int i= 1;i<=3;i++ )
//    {
//        for(int j=1;j<=i;j++)
//        {
//            printf("%d is %d\n",i,j);
//        }
//    }
//
    
    //구구단
//    for(int i=2 ;i<=9;i++)
//    {
//        for(int j=1;j<=9;j++)
//        {
//            printf("%d X %d = %d \n ",i,j,i*j);
//        }
//    }
  // 별 쌓기
//    for(int i=1;i<=5;i++)
//    {
//        for(int k=4;k>=i;k--)
//        {
//            printf(" ");
//        }
//        for(int j=0;j<i;j++)
//        {
//            printf("*");
//        }
//        printf("\n");
//
//    }
    
    //피라미드 프로젝트
    // 별 피라미드
//    int floor;
//    printf("몇 층으로 쌓겠음 ? ");
//    scanf("%d",&floor);
//    for(int i=0;i<floor;i++)
//    {
//        for(int j=i;j<floor-1;j++)
//        {
//            printf(" ");
//        }
//        for(int k=0;k<i*2+1;k++)
//        {
//            printf("*");
//
//        }
//        printf("\n");
//    }
//
//
//    int age;
//    scanf("%d",&age);
//    if(age>20)
//    {
//        printf("일반인입니다.");
//    }
//    else if(age>10 && age<20)
//    {
//        printf("유아");
//    }
//    else{
//        printf("노노 ~.  ");
//    }
//
//
//    for(int i=1;i<=30;i++)
//    {
//        if(i>=5)
//        {
//            printf("%d 니넨 집가라 고마 \n",i);
//            continue;
//        }
//
//            printf("%d 번 학생 조별 발표 준비를 하세용 ~\n",i);
//
//    }
    // && , ||
//    srand(time(NULL)); // 난수 초기화
//    for(int i=0;i<10;i++)
//    {
//        printf("%d\n",rand() % 3+1); // 1~3
//    }
    //가위 바위 보

//    if(i==0)
//    {
//        printf("siss");
//    }
//    else if(i==1)
//    {
//        printf("Rock");
//    }
//    else if(i==2)
//    {
//        printf("papaer");
//    }
//    else
//    {
//        printf("what?");
//    }
//    switch (i) {
//        case 0:
//            printf("rock\n");
//            break;
//        case 1 :
//            printf("paper\n");
//            break;
//        case 2 :
//            printf("dsd\n");
//        default:
//            printf("몰라용\n");
//            break;
//    }
//
    // Up and Down
    srand(time(NULL));
    int num = rand()%100 +1 ; // 1~100 return
    printf("숫자 : %d \n",num);
    int ans =0;
    int chance =5;
    while(chance>0)
    {
        printf("남은 기회 : %d \n",chance);
        printf("1~100 숫자를 맞춰보세용 ~ \n");
        scanf("%d",&ans);
        if(ans==num)
        {
            printf("정답입니다 ~ !\n");
            break;
        }
        else if(ans>num)
        {
            printf("DOWN!!");
        }
        else if(ans<num)
        {
            printf("Up");
        }
            chance--;
    }
    
        return 0;
    }
