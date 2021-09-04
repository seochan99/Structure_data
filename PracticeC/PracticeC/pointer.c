#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int level;
int arrayFish[6];
int *cursor;

int checkFishAlive(void);
void printFishes(void);
void initData(void);
void decreaseWater(long elapsedTime);
// 물고기 6마리
// 사막
// 건조 빨리 증발
// 증발전에 어항에 물넣어서 물고기 살라 !
// 물고기는 시간이 지날 수록 점점 커져서 나중에는 냠냠ㄴ ... !
int main(void)
{
    long startTime = 0 ; // 게임 시작 시간
    long totalElapsedTime = 0; // 총 경과 시간
    long prevElapsedTime = 0; // 직전 경과 시간(최근에 물을 준 시간 간격)
    
    int num; // 몇 번 어항에 물을 줄 것인지, 사용자 입력
    initData();
    
    cursor = arrayFish;
    
    startTime = clock(); //현재시간을 1000분의 1초 단위로 반환
    while(1)
    {
        printFishes();
//        getchar(); // 임시로 사용자 입력대기
        printf("몇 번 어항에 물을  주시겠어요 ? ");
        scanf("%d",&num);
        
        // 입력값 체크
        if(num<1 || num>6)
        {
            printf("\n Wrong Number !\n");
            continue;
        }
        totalElapsedTime = (clock()-startTime)/CLOCKS_PER_SEC;
        printf("총 경과 시간 : %ld sec \n",totalElapsedTime);
        
        //직전 물 준 시간 -> 마지막 으로 물 준시간 이후로 흐른 시간
        prevElapsedTime = totalElapsedTime - prevElapsedTime;
        printf("최근 경과 시간 : %ld sec \n",prevElapsedTime);
        
        // 어항의 물을 감소
        decreaseWater(prevElapsedTime);
        
        //사용자가 입력한 어항에 물을 준다
            // 어항의 묾이 0이면 -> 물x
        if(cursor[num-1]<=0)
        {
            printf("%d fish is dead ... cnat water",num);
        }
        //2 over 100 ?
        else if(cursor[num-1]+1<=100)
        {
            printf("%d 번 어항에 물을 줍니다",num);
            cursor[num-1]+=1;//
        }
        
        // level up ? 20 sec..!
        if(totalElapsedTime/20>level-1)
        {
            // level up
            level++;
            printf("** 축 레벨업 ! 기존 %d 레벨에서 %d 레벨로 업그레이드 *** \n\n",level-1,level);
            
            // last level = 5
            if(level==5)
            {
                printf("U Success !! End Game");
                exit(0);
                
            }
            
        }
        // 모든 물고기가 죽었는지 확인
        if(checkFishAlive()==0)
        {
            // all fish die
            printf("모든 물고기 뒤짐,,,, ㅠㅠ \n");
            exit(0);
        }else
        {
            // at least 1 fish alive
            printf("물고기가 아직 살아있습니당 ! ");

        }
        prevElapsedTime = totalElapsedTime;
        
        //10 sec -> 15 sec
        
    }
    return 0;
}
int checkFishAlive(void)
{
    for(int i=0;i<6;i++)
    {
        if(arrayFish[i]>0)
            return 1; //live !
        
    }
    return 0; // dead,,,,
}


void initData(void)
{
    level = 1;
    for(int i =0;i<6;i++)
    {
        arrayFish[i]=100;
    }
}

void printFishes(void)
{
    printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n",1,2,3,4,5,6);
    for(int i=0;i<6;i++)
    {
        printf(" %3d ",arrayFish[i]);
    }
    printf("\n\n");
}

void decreaseWater(long elapsedTime)
{
    for(int i=0;i<6;i++){
        arrayFish[i]-=(level*3*(int)elapsedTime); // 3은 난이도 조절을 위한 값
        if(arrayFish[i]<0)
        {
            arrayFish[i]=0;
        }
    }
}
