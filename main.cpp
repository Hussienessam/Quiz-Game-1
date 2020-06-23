#include <iostream>

#include <iomanip>

#include <fstream>

#include <time.h>

#include <windows.h>

using namespace std;

struct quiz
{
    int question_id;
    string question;
    string choice[4];
};

void administration_menu(quiz[],int&,int[],int[]);

void questions(quiz[]);

void start(quiz[],int,int[],int&,int[],int[]);

void scores_stats(int[],int);

void view_questions(quiz[],int);

void random(int[],int);

void slicing(string&,int);

int main()
{
    quiz quiz1[50];
    string ans2;
    string name="USER";
    int random_array[50];
    int random_array2[4];
    int ans1,no_of_quizzes=0,no_of_questions=4;
    int scores[50];
    for(int r=0;r<50;r++)
        scores[r]=0;
    questions(quiz1);
    while(1)
    {
    cout<<"Welcome "<<name<<", please choose from the following options:\n"<<"[1] Go to administration menu\n";
    cout<<"[2] Update your name\n"<<"[3] Start a new quiz\n"<<"[4] Display your scores statistics\n";
    cout<<"[5] Display all your scores\n"<<"[6] Exit"<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"My choice: ";
    cin>>ans1;
    cin.clear();
    cin.ignore(10000,'\n');
    switch (ans1)
    {
            case 1:
                system("CLS");
                administration_menu(quiz1,no_of_questions,random_array,random_array2);
                break;
            case 2:
                system("CLS");
                cout<<"Enter your name"<<endl;
                cin>>name;
                break;
            case 3:
                if(no_of_questions<4)
                {
                    cout<<"There are not enough questions for the quiz, you should add more questions"<<endl;
                    break;
                }
                system("CLS");
                start(quiz1,no_of_questions,scores,no_of_quizzes,random_array,random_array2);
                cout<<"---------------------"<<endl;
                cout<<"You have finished the quiz\n"<<"Right answers: "<<scores[no_of_quizzes-1]<<endl;
                cout<<"Wrong answers: "<<4-scores[no_of_quizzes-1]<<endl;
                cout<<"Your scores is: "<<scores[no_of_quizzes-1]<<'/'<<4<<endl;
                cout<<"---------------------"<<endl;
                break;
            case 4:
                if (no_of_quizzes==0)
                {
                    cout<<"-----------------------"<<endl;
                    cout<<"You should take the quiz first"<<endl;
                    cout<<"-----------------------"<<endl;
                    break;
                }
                system("CLS");
                cout<<"-----------------------"<<endl;
                scores_stats(scores,no_of_quizzes);
                cout<<"-----------------------"<<endl;
                cout<<endl<<"Press [b] if you want to go back to the main menu or [e] to exit"<<endl;
                cout<<"My choice: ";
                getline(cin,ans2);
                if(ans2!="b" and ans2!="e")
                {
                    cout<<"-----------------------"<<endl;
                    cout<<"invalid input"<<endl;
                    cout<<"-----------------------"<<endl;
                }
                break;
            case 5:
                if (no_of_quizzes==0)
                {
                    cout<<"-----------------------"<<endl;
                    cout<<"You should take the quiz first"<<endl;
                    cout<<"-----------------------"<<endl;
                    break;
                }
                system("CLS");
                cout<<"- Number of Quizzes taken: "<<no_of_quizzes<<endl;
                for(int i=0;i<no_of_quizzes;i++)
                {
                    cout<<"-----------------"<<endl;
                    cout<<"Quiz "<<i+1<<endl;
                    cout<<"Right answers:\t"<<scores[i]<<endl;
                    cout<<"Wrong answers:\t"<<4-scores[i]<<endl;
                    cout<<"Score:\t"<<scores[i]<<'/'<<4<<endl;
                    cout<<"-----------------"<<endl;
                }
                break;
            case 6:
                break;
            default:
                cout<<"-----------------------"<<endl;
                cout<<"invalid input"<<endl;
                cout<<"-----------------------"<<endl;
    }
    if (ans1==6 || ans2=="e")
    {
        cout<<"\n\n-----------------------------"<<endl;
        cout<<"Thanks for taking the quiz"<<endl;
        cout<<"-----------------------------"<<endl;
        break;
    }
    }
    return 0;
}

void questions(quiz quiz1[50])
    {
        quiz1[0].question="Which one of the following is a flightless bird?";
        quiz1[0].choice[0]="Emu";
        quiz1[0].choice[1]="Hen";
        quiz1[0].choice[2]="Duck";
        quiz1[0].choice[3]="Swan";
        quiz1[0].question_id=1;
        quiz1[1].question="Which is the capital of Egypt?";
        quiz1[1].choice[0]="Cairo";
        quiz1[1].choice[1]="Luxor";
        quiz1[1].choice[2]="Alexandria";
        quiz1[1].choice[3]="Oman";
        quiz1[1].question_id=2;
        quiz1[2].question="The nucleus of an atom consists of ";
        quiz1[2].choice[0]="Protons and neutrons";
        quiz1[2].choice[1]="Electrons and protons";
        quiz1[2].choice[2]="Electrons and neutrons";
        quiz1[2].choice[3]="All of the above";
        quiz1[2].question_id=3;
        quiz1[3].question="light year is a unit of";
        quiz1[3].choice[0]="Distance";
        quiz1[3].choice[1]="Time";
        quiz1[3].choice[2]="Intensity of light";
        quiz1[3].choice[3]="Light";
        quiz1[3].question_id=4;
    }

void start(quiz quiz1[20],int no_of_questions,int scores[10],int &no_of_quizzes,int random_array[15],int random_array2[4])
{
    srand(time(0));
    random(random_array,no_of_questions);
    string ans;
    for(int i=0;i<4;i++)
    {
        cout<<i+1<<"- "<<quiz1[random_array[i]].question<<endl;
        for(int j=0;j<4;j++)
        {
            random(random_array2,4);
            switch(j)
            {
                case 0:
                    cout<<"[a] "<<quiz1[random_array[i]].choice[random_array2[j]]<<"\t";
                    break;
                case 1:
                    cout<<"[b] "<<quiz1[random_array[i]].choice[random_array2[j]]<<"\t";
                    break;
                case 2:
                    cout<<"[c] "<<quiz1[random_array[i]].choice[random_array2[j]]<<"\t";
                    break;
                case 3:
                    cout<<"[d] "<<quiz1[random_array[i]].choice[random_array2[j]]<<"\t";
                    break;
            }
        }
        cout<<endl;
        getline(cin,ans);
        if(ans!="a" & ans!="b" & ans!="c" & ans!="d")
        {
            cout<<"-----------------------"<<endl;
            cout<<"invalid input"<<endl;
            cout<<"-----------------------"<<endl;
            i--;
        }
        else
        {
            if(ans=="a")
            {
                if(quiz1[random_array[i]].choice[random_array2[0]]==quiz1[random_array[i]].choice[0])
                    scores[no_of_quizzes]+=1;
            }
            else if(ans=="b")
            {
                if(quiz1[random_array[i]].choice[random_array2[1]]==quiz1[random_array[i]].choice[0])
                    scores[no_of_quizzes]+=1;
            }
            else if(ans=="c")
            {
                if(quiz1[random_array[i]].choice[random_array2[2]]==quiz1[random_array[i]].choice[0])
                    scores[no_of_quizzes]+=1;
            }
            else if(ans=="d")
            {
                if(quiz1[random_array[i]].choice[random_array2[3]]==quiz1[random_array[i]].choice[0])
                    scores[no_of_quizzes]+=1;
            }
        }
    }
    no_of_quizzes+=1;
}

void scores_stats(int scores[10],int no_of_quizzes)
{
    int highest_score=0,lowest_score=0;
    float average_score,sum=0;
    for(int i=0;i<no_of_quizzes;i++)
    {
        if (scores[i]>highest_score)
            highest_score=scores[i];
        if (scores[i]<lowest_score)
            lowest_score=scores[i];
        sum+=float(scores[i]);
    }
    average_score=sum/float(no_of_quizzes);
    cout<<"- Number of Quizzes taken: "<<no_of_quizzes<<endl;
    cout<<"- Highest score: "<<highest_score<<'/'<<4<<endl;
    cout<<"- Lowest score: "<<lowest_score<<'/'<<4<<endl;
    cout<<"- Average score: "<<fixed<<setprecision(1)<<average_score<<'/'<<4<<endl;
}

void administration_menu(quiz quiz1[20],int &no_of_questions,int random_array[15],int random_array2[4])
{
    int ans2,num,num2,counter=0,no_of_questions_in_file=0,questions_counter=0,choices_counter=0;
    bool check=false;
    fstream infile;
    string ans,file_name;
    while(1)
    {
        cout<<"Welcome to the administration menu, please choose from the following options:"<<endl;
        cout<<"[1] View all questions"<<endl;
        cout<<"[2] Add new questions"<<endl;
        cout<<"[3] Load questions from file"<<endl;
        cout<<"[4] Go back to main menu"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"My choice: ";
        cin>>ans2;
        cin.clear();
        cin.ignore(10000,'\n');
        switch(ans2)
            {
                case 1:
                    system("CLS");
                    view_questions(quiz1,no_of_questions);
                    cout<<"-----------------------------------------------------------------------"<<endl;
                    cout<<"Press [e] and the question ID if you want to delete a question (Example: e 2)"<<endl;
                    cout<<"Press [f] if you want to go back to the main menu"<<endl;
                    getline(cin,ans);
                    system("cls");
                    if (ans[0]=='e' & ans[1]==' ')
                    {
                        for(int w=2;w<ans.length();w++)
                        {
                            if(isalpha(ans[w]))
                            {
                                check=true;
                                break;
                            }
                        }
                        if(check)
                        {
                            cout<<"-----------------------"<<endl;
                            cout<<"invalid input"<<endl;
                            cout<<"-----------------------"<<endl;
                            break;
                        }
                        else
                            slicing(ans,2);
                        num=stoi(ans);
                        if(num>no_of_questions || num<=0)
                        {
                            cout<<"-----------------------"<<endl;
                            cout<<"invalid input"<<endl;
                            cout<<"-----------------------"<<endl;
                            break;
                        }
                        for(int j=num-1;j<no_of_questions;j++)
                        {
                            quiz1[j].question=quiz1[j+1].question;
                            for(int m=0;m<4;m++)
                                quiz1[j].choice[m]=quiz1[j+1].choice[m];
                            quiz1[j].question_id=quiz1[j+1].question_id;
                        }
                        no_of_questions-=1;
                        system("CLS");
                        view_questions(quiz1,no_of_questions);
                    }
                    else if (ans=="f")
                        break;
                    else
                    {
                        cout<<"-----------------------"<<endl;
                        cout<<"invalid input"<<endl;
                        cout<<"-----------------------"<<endl;
                    }
                    break;
                case 2:
                    system("CLS");
                    cout<<"How many questions would you like to add ?"<<endl;
                    cin>>num2;
                    if(num2<=0)
                    {
                        cout<<"-----------------------"<<endl;
                        cout<<"invalid input"<<endl;
                        cout<<"-----------------------"<<endl;
                        cin.clear();
                        cin.ignore(10000,'\n');
                        break;
                    }
                    cin.ignore(10000,'\n');
                    for(int i=0;i<num2;i++)
                    {
                        cout<<"Enter the question"<<endl;
                        getline(cin,quiz1[no_of_questions+i].question);
                        cout<<"Enter the choices"<<endl;
                        for(int n=0;n<4;n++)
                            getline(cin,quiz1[no_of_questions+i].choice[n]);
                        quiz1[no_of_questions+i].question_id=no_of_questions+i+1;
                    }
                    no_of_questions+=num2;
                    break;
                case 3:
                    cout<<"Enter file name"<<endl;
                    getline(cin,file_name);
                    infile.open(file_name);
                    while(infile.fail())
                    {
                        cout<<"Cannot find the file....Enter file name again"<<endl;
                        getline(cin,file_name);
                        infile.open(file_name);
                    }
                    while(!infile.eof())
                    {
                        if(counter==0)
                        {
                            getline(infile,quiz1[questions_counter+no_of_questions].question);
                            no_of_questions_in_file+=1;
                            questions_counter+=1;
                            quiz1[questions_counter+no_of_questions].question_id=counter+no_of_questions+1;
                            counter++;
                        }
                        else
                        {
                            getline(infile,quiz1[choices_counter+no_of_questions].choice[counter-1]);
                            counter++;
                        }
                        if(counter==5)
                        {
                            choices_counter+=1;
                            counter=0;
                        }
                    }
                    no_of_questions+=no_of_questions_in_file;
                    cout<<"----------------------------------"<<endl;
                    cout<<"Your file has been loaded successfully"<<endl;
                    cout<<"----------------------------------"<<endl;
                    infile.close();
                    break;
                case 4:
                    system("CLS");
                    break;
                default:
                    cout<<"-----------------------"<<endl;
                    cout<<"invalid input"<<endl;
                    cout<<"-----------------------"<<endl;
          }
        if(ans2==4 || ans=="f")
            break;
    }
}

void view_questions(quiz quiz1[20],int no_of_questions)
{
    cout<<"Number of questions available: "<<no_of_questions<<endl;
    cout<<"Questions list:"<<endl<<"---------"<<endl;
    for(int i=0;i<no_of_questions;i++)
    {
        cout<<i+1<<"- "<<quiz1[i].question<<endl;
            for(int l=0;l<4;l++)
            {
                switch(l)
                {
                    case 0:
                        cout<<"*[a] "<<quiz1[i].choice[0]<<"\t";
                        break;
                    case 1:
                        cout<<"[b] "<<quiz1[i].choice[1]<<"\t";
                        break;
                    case 2:
                        cout<<"[c] "<<quiz1[i].choice[2]<<"\t";
                        break;
                    case 3:
                        cout<<"[d] "<<quiz1[i].choice[3]<<"\t";
                        break;
                }
            }
        cout<<endl<<endl;
    }
}

void random(int random_array[],int num)
{
    int arr[num];
    bool check;
    int i=0;
    srand(time(0));
    while(i!=num)
    {
        arr[i]=rand()%num;
        check=true;
        for(int j=0;j<num;j++)
        {
            if(i==j)
                continue;
            else if(arr[j]==arr[i])
            {
                 check=false;
                 break;
            }
        }
        if(check)
        {
            random_array[i]=arr[i];
            i++;
        }
    }
}

void slicing(string& str,int start)
{
    string str2="00";
    int y=0;
    for(int i=start;i<=str.length();i++)
    {
        str2[y]=str[i];
        y+=1;
    }
    str=str2;
}
