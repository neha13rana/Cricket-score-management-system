#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void first_inning(char y[5]);
void second_inning(char y[5],char x[5]);

char Team1[5],Team2[5];
int toss, target, overs, score, wickets, inning=1, balls, playedballs, battingfirst;
float runrate, currentover;

int main()
{
    printf("***************************************************");
    printf("\n \t\t ITNU Cricket scorer\t\t");
    printf("\n***************************************************");
    printf("\nPress enter key to continue");
    getch();
    system("cls");

    printf("Enter the name of team 1: ");
    scanf("%s",Team1);
    printf("Enter the name of team 2: ");
    scanf("%s",Team2);
    printf("Enter the maximum number of overs: ");
    scanf("%d",&overs);
    balls=overs*6;
    re:
    printf("Which team is batting first?\n");
    printf("\n[1] %s\n[2] %s\n",Team1,Team2);
    scanf("%d",&toss);
    switch (toss)
    {
    case 1:
        printf("%s is batting first",Team1);
        first_inning(Team1);
        battingfirst=1;
        break;
    case 2:
        printf("%s is batting first",Team2);
        first_inning(Team2);
        battingfirst=2;
        break;
    
    default:
        printf("Enter a invalid choice!");
        goto re;
    }
    if(target > 0)
    {
        if(battingfirst == 1)
        {
            second_inning(Team2,Team1);
        }
        else
        {
            second_inning(Team1,Team2);
        }
    }
    return 0;
}
void first_inning(char y[5])
{
    playedballs=0;
    score=0;
    wickets=0;
    int j, scorer, r;
    printf("---------------First inning----------------\n");
    for(j=0;j!=balls;j++)
    {
        lebel:
        printf("Last ball...");
        printf("\n[1]Normal delivery\n[2]No ball or wide\n");
        scanf("%d",&scorer);
        printf("\nRuns on last ball\n");
        printf("[0]dotball\n[1]1 run\n[2]2 run\n[3]3 run\n[4]four\n[5]six\n[6]wicket!\n");
        scanf("%d",&r);
        switch(scorer)
        {
            case 1:
            playedballs += 1;
            if(playedballs%6 == 0)
            {
                currentover += 0.5;
            }
            else
            {
                currentover += 0.1;
            }
            break;
            case 2:
            score += 1;
            default:
            break;
        }
        switch (r)
        {
        case 0:
            break;
        case 1:
            score += 1;
            break;
        case 2:
            score += 2;
            break;
        case 3:
            score += 3;
            break;
        case 4:
            score += 4;
            break;
        case 5:
            score += 6;
            break;
        case 6:
            wickets += 1;
            break;
        
        default:
            printf("Enter a valid choice!");
            goto lebel;
            break;
        }
        runrate = (float)score*6/playedballs;
        printf("---------------First inning---------------\n");
        printf("Inning 1|");
        printf("\nSCORE---%s|%d-%d|\t\t |overs:%0.1f|",y,score,wickets,currentover);
        printf("\n Runrate:%.2f",runrate);

        getch();
        system("cls");
        if(wickets==10 || playedballs==balls)
        {
            inning=2;
            if(inning==2)
            {
                target = score + 1;
                printf("Target is %d\n",target);
            }
            break;
        }
    }
}
void second_inning(char y[5],char x[5])
{
    playedballs=0;
    score=0,wickets=0;
    int j;
    int scorer, r;
    currentover=0;
    printf("---------------Second inning---------------\n");
    for (j=0;j!=balls;j++)
    {
        lebel:
        printf("Last ball...\n");
        printf("\n[1]Normal delivery\n[2]No ball or wide\n");
        scanf("%d",&scorer);
        printf("\nRuns on last ball\n");
        printf("[0]dotball\n[1]1 run\n[2]2 run\n[3]3 run\n[4]four\n[5]six\n[6]wicket!\n");
        scanf("%d",&r);
        
        switch(scorer)
        {
            case 1:
            playedballs += 1;
            if(playedballs%6 == 0)
            {
                currentover += 0.5;
            }
            else
            {
                currentover += 0.1;
            }
            break;
            case 2:
            score += 1;
            default:
                break;
        }
        switch (r)
        {
            case 0:
                break;
            case 1:
                score += 1;
                break;
            case 2:
                score += 2;
                break;
            case 3:
                score += 3;
                break;
            case 4:
                score += 4;
                break;
            case 5:
                score += 6;
                break;
            case 6:
                wickets += 1;
                break;
            default:
                printf("Enter a valid choice!");
                goto lebel;
                break;
        }
        runrate=(float)score*6/playedballs;
        printf("\n-----------------Second inning------------------\n");
        printf("Inning 2|");
        printf("\nSCORE---%s|%d-%d|\t\t |overs:%.1f| Target = %d|",y,score,wickets,currentover,target);
        printf("\n Runrate = %.2f",runrate);
        printf("|Need %d of %d to win|",target-score,balls-playedballs);

        getch();
        system("cls");
        if(wickets==10 || playedballs==balls || score>=target)
        {
            if (score>=target)
            {
                printf("%s won the match by %d wickets!",y,10-wickets);
                break;
            }
            else if(score==(target - 1))
            {
                printf("The match is tied");
                break;
            } 
            else
            {
                printf("%s won the match by %d runs!",x,target-1-score);
                break;
            }
            break;
        }
    }
}