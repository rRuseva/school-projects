package com.ruseva.dothatmath;

import android.content.Intent;
import android.support.annotation.NonNull;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.TextView;

import java.util.Collection;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class MainActivity extends AppCompatActivity  implements View.OnClickListener {

    public ImageButton btnDraw;
    int result=0, a=0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final Button btnAdd = findViewById(R.id.btnAdd);
        btnAdd.setOnClickListener(this);
        final Button btnSubtract = findViewById(R.id.btnSubtract);
        btnSubtract.setOnClickListener(this);
        final Button btnMultiply = findViewById(R.id.btnMultiply);
        btnMultiply.setOnClickListener(this);
        final Button btnDivide = findViewById(R.id.btnDivide);
        btnDivide.setOnClickListener(this);
        final Button btnEqual = findViewById(R.id.btnEqual);
        btnEqual.setOnClickListener(this);
        final Button btnC = findViewById(R.id.btnC);
        btnC.setOnClickListener(this);
        final Button btnLB = findViewById(R.id.btnLB);
        btnLB.setOnClickListener(this);
        final Button btnRB = findViewById(R.id.btnRB);
        btnRB.setOnClickListener(this);

        final Button btn0 = findViewById(R.id.btn0);
        btn0.setOnClickListener(this);
        final Button btn1 = findViewById(R.id.btn1);
        btn1.setOnClickListener(this);
        final Button btn2 = findViewById(R.id.btn2);
        btn2.setOnClickListener(this);
        final Button btn3 = findViewById(R.id.btn3);
        btn3.setOnClickListener(this);
        final Button btn4 = findViewById(R.id.btn4);
        btn4.setOnClickListener(this);
        final Button btn5 = findViewById(R.id.btn5);
        btn5.setOnClickListener(this);
        final Button btn6 = findViewById(R.id.btn6);
        btn6.setOnClickListener(this);
        final Button btn7 = findViewById(R.id.btn7);
        btn7.setOnClickListener(this);
        final Button btn8 = findViewById(R.id.btn8);
        btn8.setOnClickListener(this);
        final Button btn9 = findViewById(R.id.btn9);
        btn9.setOnClickListener(this);

        btnDraw = findViewById(R.id.btnDraw);
        btnDraw.setOnClickListener(this);
        btnDraw.setEnabled(false);
        initImageView();
    }

//    public int calc(String eq){
//        int a =0, b=0; res =0;
//
//        switch (c) {
//            case '+': return a + b; break;
//            case '-': return a - b; break;
//            case '*': return a * b; break;
//            case '/': return a / b; break;
//            default: return a; break;
//        }
//    }

    @Override
    public void onClick(View v){
        TextView input = findViewById(R.id.input);

        switch (v.getId()){
            case R.id.btnAdd: {
                input.setText(input.getText().toString()+ "+");
                //result= result+a;
            } break;
            case R.id.btnSubtract: {
                input.setText(input.getText().toString()+ "-");
               // result= result-a;
            } break;
            case R.id.btnMultiply: {
                input.setText(input.getText().toString()+ '*');
                //result= result*a;
            } break;
            case R.id.btnDivide: {
                input.setText(input.getText().toString()+ '/');
                //result= result/a;
            } break;
            case R.id.btnLB: {
                input.setText(input.getText().toString()+ '(');
                //result= result/a;
            } break;
            case R.id.btnRB: {
                input.setText(input.getText().toString()+ ')');
                //result= result/a;
            } break;
            case R.id.btnEqual: {
                String eq = input.getText().toString();
                result = calculateRP(convertToReversePolish1(eq));
                input.setText(eq + " = " + result );
                btnDraw.setEnabled(true);
                result=0;
            }break;
            case R.id.btnC: {
                input.setText("");
                result=0;
                btnDraw.setEnabled(false);
            }break;

            case R.id.btn0: {
                input.setText(input.getText().toString() + '0');
                a=0;
            } break;
            case R.id.btn1: {
                input.setText(input.getText().toString()+'1');
                a=1;
            }break;
            case R.id.btn2: {
                input.setText(input.getText().toString()+'2');
                a=2;
            }break;
            case R.id.btn3: {
                input.setText(input.getText().toString()+'3');
                a=3;
            }break;
            case R.id.btn4: {
                input.setText(input.getText().toString()+'4');
                a=4;
            }break;
            case R.id.btn5: {
                input.setText(input.getText().toString()+'5');
                a=5;
            }break;
            case R.id.btn6: {
                input.setText(input.getText().toString()+'6');
                a=6;
            }break;
            case R.id.btn7: {
                input.setText(input.getText().toString()+'7');
                a=7;
            }break;
            case R.id.btn8: {
                input.setText(input.getText().toString()+'8');
                a=8;
            }break;
            case R.id.btn9: {
                input.setText(input.getText().toString()+'9');
                a=9;
            }break;
        }
    }

//    protected String convertToReversePolish1(String input){
        protected Queue<Character> convertToReversePolish1(String input){
        Queue<Character> expr = new LinkedList<>();
        for (int i = 0; i < input.length(); i++)
        {
            expr.add(input.charAt(i));
        }
        Queue<Character> result = new LinkedList<Character>();
        Stack<Character> symbol = new Stack<Character>();

        Character c = expr.element();
        Character temp;
        symbol.push('(');

        while(!expr.isEmpty()){
            if(c.equals('(') ) symbol.push(c);
            if(Character.isDigit(c)) result.add(c);
            if(c.equals('*') || c.equals('/')) symbol.push(c);
            if(c.equals('+') || c.equals('-')) {
                temp = symbol.peek();
                while(temp.equals('*') || temp.equals('/')){
                    result.add(temp);
                    symbol.pop();
                    temp=symbol.peek();
                }
                symbol.add(c);
            }
            if(c.equals(')')){
                temp=symbol.peek();
                while(!temp.equals('(')){
                    result.add(temp);
                    symbol.pop();
                    temp=symbol.peek();
                }
                symbol.pop();
            }
            expr.poll();
            if(!expr.isEmpty())
                c=expr.element();
        }
        temp = symbol.peek();
        while(!temp.equals('(')){
            result.add(temp);
            symbol.pop();
            temp=symbol.peek();
        }
        symbol.pop();

        return result;
//        String res= "";
//        while (!result.isEmpty()) {
//            res = res + Character.toString(result.poll()) + " ";
//        }
//        return res;
    }

    protected int calculateRP(Queue<Character> polish){
        Integer result=0, left, right;
        Character curr;

        Stack<Integer> s = new Stack<Integer>();
        curr = polish.peek();
        while(!polish.isEmpty()){
            if(Character.isDigit(curr)){
                Integer c= (Integer.parseInt(curr.toString()));
                s.add(c);
            }
            if(curr.equals('+')|| curr.equals('-') || curr.equals('*')||curr.equals('/')){
                right = (Integer)s.pop();
                left = (Integer)s.pop();
                switch (curr){
                    case '+': result = left + right; break;
                    case '-': result = left - right; break;
                    case '*': result = left * right; break;
                    case '/': result = left / right; break;
                }
                s.push(result);
            }
            polish.poll();
            curr = polish.peek();
        }
        return s.peek();
    }

    public void initImageView(){
        btnDraw =  findViewById(R.id.btnDraw);
        btnDraw.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view){
                Intent drawInt = new Intent(getApplicationContext(), DrawCircleActivity.class);
                drawInt.putExtra("result", result);
                startActivity(drawInt);
//                startActivity(new Intent(getApplicationContext(), DrawCircleActivity.class));
            }
        });
    }
}
