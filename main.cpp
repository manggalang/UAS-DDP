#include <iostream>
#include <string>

using namespace std;

string programRepeat = "", name[100], tempName[100], tempS;
int id = 0;
float attendance[100], averageTaskValue[100], middleExam[100],finalExam[100], finalValue[100], tempFinalValue[100], tempN;

void dataList() {
    for(int i = 0; i < id; i++) {
        cout <<i+1<< "] Name : " << name[i]
                << ", Attendance : " << attendance[i]
                << ", Average Task Value : " << averageTaskValue[i]
                << ", Midddle Exam : " << middleExam[i]
                << ", Final Exam : " << finalExam[i]
                << ", Final Value : " << finalValue[i] << endl;
    }
}

void repeat() {
    cout << "\nDo you wanna back to the list commands ? yes or no ? = ";
    cin >> programRepeat;
}

void checkLimit() {
    if(attendance[id] > 14) {
        back:
        cout << "total absenteeism exceeds the limit! reminder! the max limit is 14";
        cout << "\nPlease re-insert total attendance! : ";
        cin >> attendance[id];
        if(attendance[id] > 14) {
            goto back;
        }
    }
    if(averageTaskValue[id] > 100) {
        back1:
        cout << "Average task scores exceeds the limit! the max limit is 100";
        cout << "\nPlease re-insert the average value of the task! : ";
        cin >> averageTaskValue[id];
        if(averageTaskValue[id] > 100) {
            goto back1;
        }
    }
    if(middleExam[id] > 100) {
        back2:
        cout << "Midterm test scores exceeds the limit! the max limit is 100";
        cout << "\nPlease re-insert the midterm test scores! : ";
        cin >> middleExam[id];
        if(middleExam[id] > 100) {
            goto back2;
        }
    }
    if(finalExam[id] > 100) {
        back3:
        cout << "The the end of semester exam scores exceeds the limit! the max limit is 100";
        cout << "\nPlease re-insert the the end of semester exam scores! : ";
        cin >> finalExam[id];
        if(finalExam[id] > 100) {
            goto back3;
        }
    }
}

int main() {
    int select;
    do {
        system("clear");
        cout << "=================Final Grade Program=================\n";
        cout << "\n1] Show Data List\n2] Insert Data\n3] Edit Data\n4] Remove Data\n5] Show Highes Grade\n6] Exit Program\n\n";
        
        cout << "Select commands = ";
        cin >> select;
        
        switch(select) {
            case 1 :
                system("clear");
                cout << "=================Data List=================\n\n";
                if (id == 0) {
                    cout << "Data is empty !";
                } else {
                    dataList();
                    cout << "\nSuccsesfully display data!";
                }
                repeat();
                break;
                
            case 2 :
                system("clear");
                finalValue[id] = 0;
                cout << "=================Insert Data=================\n\n";
                cout << "Insert name : ";
                cin >> name[id];
                cout << "Insert total attendance : ";
                cin >> attendance[id];
                checkLimit();
                finalValue[id] += (attendance[id] / 14 * 10);
                cout << "Insert the average value of the task : ";
                cin >> averageTaskValue[id];
                checkLimit();
                finalValue[id] += (averageTaskValue[id] * 20) / 100;
                cout << "Insert the midterm test scores : ";
                cin >> middleExam[id];
                checkLimit();
                finalValue[id] += (middleExam[id] * 30) / 100;
                cout << "Insert the end of semester exam scores : ";
                cin >> finalExam[id];
                checkLimit();
                finalValue[id] += (finalExam[id] * 40) / 100;
                id = id + 1;
                cout << "\nSuccsesfully insert data!!";
                repeat();
                break;
                
            case 3 :
                int editId;
                system("clear");
                cout << "=================Edit Data=================\n\n";
                if (id == 0) {
                    cout << "Data is empty !";
                } else {
                	editRepeat:
                    dataList();
                    cout << "\nSelect id number to edit data = ";
                    cin >> editId;
                    if(id - 1 < editId || editId < 0) {
                        cout << "\nid not found!!\nplease enter the correct id!\n\n";
                        goto editRepeat;
                    } else {
                        finalValue[editId] = 0;
                        cout << "Insert new name = ";
                        cin >> name[editId];
                        cout << "Insert total attendance : ";
                        cin >> attendance[editId];
                        checkLimit();
                        finalValue[editId] += (attendance[editId] / 14 * 10);
                        cout << "Insert the average value of the task : ";
                        cin >> averageTaskValue[editId];
                        checkLimit();
                        finalValue[editId] += (averageTaskValue[editId] * 20) / 100;
                        cout << "Insert the midterm test scores : ";
                        cin >> middleExam[editId];
                        checkLimit();
                        finalValue[editId] += (middleExam[editId] * 30) / 100;
                        cout << "Insert the end of semester exam scores : ";
                        cin >> finalExam[editId];
                        checkLimit();
                        finalValue[editId] += (finalExam[editId] * 40) / 100;
                        cout << "\nSuccsesfully edit data!!";  
                    }
                }
                repeat();
                break;
                
            case 4 :
                system("clear");
                int deleteId;
                cout << "=================Remove Data=================\n\n";
                if (id == 0) {
                    cout << "Data is empty !";
                } else {
                	removeRepeat:
                    dataList();
	                cout << "\nSelect id number to remove data = ";
	                cin >> deleteId;
	                if(id - 1 < deleteId || deleteId < 0) {
	                    cout << "\nid not found!!\nplease enter the correct id!\n\n";
	                    goto removeRepeat;
	                } else {
	                    for(int i = deleteId; i < id; i++) {
	                    	name[i] = name[i + 1];
	                    	attendance[i] = attendance[i + 1];
	                    	averageTaskValue[i] = averageTaskValue[i + 1];
	                    	middleExam[i] = middleExam[i + 1];
	                    	finalExam[i] = finalExam[i + 1];
	                    	finalValue[i] = finalValue[i + 1];
						}
						id -= 1;
	                    cout << "\nSuccsesfully remove data!!\n";
	                }
                }
                repeat();
                break;
                
            case 5:
            	system("clear");
				cout << "=================Show Data by Grade=================\n\n";
                if (id == 0) {
                    cout << "Data is empty !";
                } else {
                    for(int i = 0; i < id; i++) {
                        tempName[i] = name[i];
                        tempFinalValue[i] = finalValue[i];
                    }
                    for(int i = 0; i < id; i++) {
                        for(int x = 0; x < id; x++) {
                            if(tempFinalValue[i] > tempFinalValue[x]) {
                                tempS = tempName[i];
                                tempName[i] = tempName[x];
                                tempName[x] = tempS;
                                tempN = tempFinalValue[i];
                                tempFinalValue[i] = tempFinalValue[x];
                                tempFinalValue[x] = tempN;
                            }
                        }
                    }
                    for(int i = 0; i < id; i++) {
                        if(tempFinalValue[i] < 50) {
                            cout <<i+1<< "] Name : " << tempName[i] << ", Final Value : " << tempFinalValue[i] << ", Grade : E\n";
                        } else if(tempFinalValue[i] >= 50 && tempFinalValue[i] < 60) {
                            cout <<i+1<< "] Name : " << tempName[i] << ", Final Value : " << tempFinalValue[i] << ", Grade : D\n";
                        } else if(tempFinalValue[i] >= 60 && tempFinalValue[i] < 70) {
                            cout <<i+1<< "] Name : " << tempName[i] << ", Final Value : " << tempFinalValue[i] << ", Grade : C\n";
                        } else if(tempFinalValue[i] >= 70 && tempFinalValue[i] < 80) {
                            cout <<i+1<< "] Name : " << tempName[i] << ", Final Value : " << tempFinalValue[i] << ", Grade : B\n";
                        } else if(tempFinalValue[i] >= 80 && tempFinalValue[i] < 95) {
                            cout <<i+1<< "] Name : " << tempName[i] << ", Final Value : " << tempFinalValue[i] << ", Grade : A\n";
                        } else if(tempFinalValue[i] >= 95 && tempFinalValue[i] <= 100) {
                            cout <<i+1<< "] Name : " << tempName[i] << ", Final Value : " << tempFinalValue[i] << ", Grade : A+\n";
                        }
                    }
				}
				repeat();
				break;
				
			case 6:
			    system("clear");
			    cout << "\nSuccsesfully Exit Program";
                programRepeat = "Exit";
                break;
            
            default :
                cout << "\n404 list not found!";
                repeat();
                break;
        }
        
    } while(programRepeat == "Yes" ||
            programRepeat == "yes" ||
            programRepeat == "1");

    return 0;
}
