import java.util.*;

//We can also do this by converting the string expression to postfix or prefix expression
//But this is what I thought of first, so I did it this way

class Add_Sub_CalculateQ1{
    public String calculateExp(String s){
        int result = 0;
        Stack<Object> stack = new Stack<>();
        int num = 0;
        char lastsign = '+';

        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
            if(Character.isDigit(c)){
                num = num*10 + c - '0';
                if(num>100000000){
                    return "Error";
                }
            }
            if(!Character.isDigit(c) && c!=' ' && c!=')'){
                if(c=='(') {
                    if (lastsign == '(') {
                        stack.add(c);
                    } else {
                        stack.add(lastsign);
                        stack.add(c);
                    }
                }
                //encountered operator, mid way operators
                else if(lastsign=='+') stack.add(num);
                else if(lastsign=='-') stack.add(-num);
                else if(lastsign=='(') stack.add(num);
                //else if(lastsign==' ')

                lastsign = c;
                num = 0;
                System.out.println(stack);
            }
            if(c==')'){
                //add the calculated num first to stack
                if(lastsign=='+') stack.add(num);
                else if(lastsign=='-') stack.add(-num);
                num=0;
                System.out.println(stack);

                //pop stack until the element is (

                int temp = 0;
                while(stack.peek() instanceof Integer /*(char)stack.peek() != '('*/){
                    temp += (int)stack.pop();
                }
                //System.out.println(temp);
                stack.pop();//removing (;
                char ch = (char)stack.peek();
                if(ch=='(' || ch=='+' || ch=='-'){
                    if(ch=='+'){
                        stack.pop();
                        stack.add(temp);
                    }
                    if(ch=='-'){
                        stack.pop();
                        stack.add(-temp);
                    }
                    if(ch=='(') stack.add(temp);
                    //System.out.println(stack);
                }
                else{
                    //Error in String expression
                    return "Expression Error";
                }
            }
        }
        if(lastsign=='+') stack.add(num);
        else if(lastsign=='-') stack.add(-num);

        while(!stack.isEmpty()){
            //System.out.println(stack.size());
            //System.out.println(stack);
            result+=(int)stack.pop();
        }
        return Integer.toString(result);
    }


    public static void main(String[] args){
        //System.out.println("Hey Dude!");
        Add_Sub_CalculateQ1 calc = new Add_Sub_CalculateQ1();
        while(true) {
            System.out.println("Please Enter an expression");
            Scanner sc = new Scanner(System.in);

            String s = sc.nextLine();
            String result = calc.calculateExp(s);
            if (result.equals("Error")) {
                System.out.println("Error: A number is greater than 100,000,000");
            } else {
                System.out.println("Result: " + result);
            }

            System.out.println("Do you want to continue?(y/n)");
            char c = sc.next().charAt(0);
            if(c=='n'){
                break;
            }
        }

    }
}