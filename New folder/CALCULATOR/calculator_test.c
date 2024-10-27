#include "calculator.h"
#include "stdio.h"
//THIS IS A TEST FILE FOR THE CALCULATOR
Calculator calc1 = {20,30,0,'+',"This is me ",false};
//used to test for division - notice second operand is 0
Calculator calc2 = {20,0,0,'+',"This is me ",false};
//used to test for overflow IN ADDITION
Calculator calc3 = {INT32_MAX,INT32_MAX,0,'+',"This is me ",false};
////used to test for overflow IN SUBTRACTION
Calculator calc4 = {INT32_MIN,INT32_MAX,0,'+',"This is me ",false};
//-----------------------------------------------------------------------------------
//test for addition
void addition_test(){
    Calculator *ptr = &calc1;
    Calculator *ptr3 = &calc3;
    int32_t result1 = add(ptr);
    int32_t result2 = add(ptr3);
     bool flag1 = (result1 == 50);
     bool flag2 = (result2 == -1);
    if(flag1){
    printf("%s","true\t");
    }
    else {
    printf("%s","false\t");
    }
    //
     if(flag2){
    printf("%s","true\n");
    }
    else {
    printf("%s","false\t");
    printf("%d\t",result2);
    printf("%d\t",calc3.hasError);
    printf("%d , %d , %d \n",calc3.operand1,calc3.operand2, calc3.operand1 + calc3.operand2);
    }
}

   
//-----------------------------------------------------------------------------------------

    
//-------------------------------------------------------------------------------------------
//test for subtraction
 void subtraction_test(){
 Calculator *ptr = &calc1;
  bool flag = (sub(ptr) == -10);
    if(flag){
    printf("%s","true\n");
    }
    else {
    printf("%s","false\n");
    }
    }
//-----------------------------------------------------------------------------------------

    
//-------------------------------------------------------------------------------------------
//test for division
 void division_test(){
 Calculator *ptr = &calc1;
 int32_t result = div(ptr);
  bool flag = (result == 0);
    if(flag){
    printf("%s","true\n");
    }
    else {
    printf("%s","false\n");
    }
    printf("%d",result);
    }
//-----------------------------------------------------------------------------------------

    
//-------------------------------------------------------------------------------------------
//test for multiplication
 void multiplication_test(){
 Calculator *ptr = &calc1;
  bool flag = (mult(ptr) == 600);
    if(flag){
    printf("%s","true\n");
    }
    else {
    printf("%s","false\n");
    }
    }
//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
//test for calculate
void calculate_test(){
    //THIS IS A TEST FILE FOR THE CALCULATOR
    Calculator calc11 = {20,30,0,'+',"This is me ",false};
    Calculator calc12 = {20,30,0,'-',"This is me ",false};
    Calculator calc13 = {20,30,0,'x',"This is me ",false};
    Calculator calc14 = {30,20,0,'/',"This is me ",false};
    Calculator *ptr1 = &calc11;
    Calculator *ptr2 = &calc12;
    Calculator *ptr3 = &calc13;
    Calculator *ptr4 = &calc14;
    int32_t result1 = calculate(ptr1,ADD);
    int32_t result2 = calculate(ptr2,SUB);
    int32_t result3 = calculate(ptr3,MULT);
    int32_t result4 = calculate(ptr4,DIV);
     bool flag1 = (result1 == 50);
     bool flag2 = (result2 == -10);
     bool flag3 = (result3 == 600);
     bool flag4 = (result4 == 1);
    if(flag1){
    printf("%s","true\n");
    }
    else {
    printf("%s","false\t");
    printf("%d\t",result1);
    printf("%d\t",calc11.hasError);
    printf("%d , %d , %d \n",calc11.operand1,calc11.operand2, calc11.operand1 + calc11.operand2);
    }
    //
     if(flag2){
    printf("%s","true\n");
    }
    else {
    printf("%s","false\t");
    printf("%d\t",result2);
    printf("%d\t",calc12.hasError);
    printf("%d , %d , %d \n",calc12.operand1,calc12.operand2, calc12.operand1 - calc12.operand2);
    }
    //
    if(flag3){
    printf("%s","true\n");
    }
    else {
    printf("%s","false\t");
    printf("%d\t",result3);
    printf("%d\t",calc13.hasError);
    printf("%d , %d , %d \n",calc13.operand1,calc13.operand2, calc13.operand1 * calc13.operand2);
    }
    //
    if(flag4){
    printf("%s","true\t");
    }
    else {
    printf("%s","false\t");
    printf("%d\t",result4);
    printf("%d\t",calc3.hasError);
    printf("%d , %d , %d \n",calc14.operand1,calc14.operand2, calc14.operand1 / calc14.operand2);
    }
}
//-----------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------
//test for calculate
void equals_test(){
    //THIS IS A TEST FILE FOR THE CALCULATOR
    Calculator calc11 = {20,30,0,'+',"This is me ",false};
    Calculator calc12 = {20,30,0,'-',"This is me ",false};
    Calculator calc13 = {20,30,0,'x',"This is me ",false};
    Calculator calc14 = {30,20,0,'/',"This is me ",false};
    Calculator *ptr1 = &calc11;
    Calculator *ptr2 = &calc12;
    Calculator *ptr3 = &calc13;
    Calculator *ptr4 = &calc14;
    equals(ptr1);
    equals(ptr2);
    equals(ptr3);
    equals(ptr4);
    int32_t result1 = calc11.result;
    int32_t result2 = calc12.result;
    int32_t result3 = calc13.result;
    int32_t result4 = calc14.result;
     bool flag1 = (result1 == 50);
     bool flag2 = (result2 == -10);
     bool flag3 = (result3 == 600);
     bool flag4 = (result4 == 0);
    if(flag1){
    printf("%s","true\n");
    }
    else {
    printf("%s","false\t");
    printf("%d\t",result1);
    printf("%d\t",calc11.hasError);
    printf("%d , %d , %d \n",calc11.operand1,calc11.operand2, calc11.operand1 + calc11.operand2);
    }
    //
     if(flag2){
    printf("%s","true\n");
    }
    else {
    printf("%s","false\t");
    printf("%d\t",result2);
    printf("%d\t",calc12.hasError);
    printf("%d , %d , %d \n",calc12.operand1,calc12.operand2, calc12.operand1 - calc12.operand2);
    }
    //
    if(flag3){
    printf("%s","true\n");
    }
    else {
    printf("%s","false\t");
    printf("%d\t",result3);
    printf("%d\t",calc13.hasError);
    printf("%d , %d , %d \n",calc13.operand1,calc13.operand2, calc13.operand1 * calc13.operand2);
    }
    //
    if(flag4){
    printf("%s","true\t");
    }
    else {
    printf("%s","false\t");
    printf("%d\t",result4);
    printf("%d\t",calc3.hasError);
    printf("%d , %d , %d \n",calc14.operand1,calc14.operand2, calc14.operand1 / calc14.operand2);
    }
}
    int main  (){
        addition_test();
        subtraction_test();
        multiplication_test();
        division_test();
       calculate_test();
       equals_test();
       
        return 0;

    }
   
