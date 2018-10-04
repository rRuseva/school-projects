package com.ruseva.dothatmath;

import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Point;
import android.graphics.drawable.ColorDrawable;
import android.graphics.drawable.ShapeDrawable;
import android.graphics.drawable.shapes.OvalShape;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Display;
import android.widget.ImageView;
import android.widget.TextView;

public class DrawCircleActivity extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_draw_circle);



        ImageView drawView = findViewById(R.id.drawView);

        // get the radius from the calculations of previous activity
        Intent i = getIntent();
        int radius = i.getIntExtra("result", 1)*10;
        TextView txt = findViewById(R.id.textView);
        txt.setText("Radius is " + radius+"");

        //get the size of the screen and use it for dimensions of the canvas
        Display display = getWindowManager().getDefaultDisplay();
        Point size = new Point();
        display.getSize(size);

        //set the circle center, dimensions and other properties
        Bitmap bitmap = Bitmap.createBitmap(size.x,size.y, Bitmap.Config.ARGB_8888);
        Canvas canvas = new Canvas(bitmap);
        //canvas.drawColor(Color.WHITE);
        canvas.drawColor(Color.LTGRAY);


        Paint paint = new Paint();
        paint.setStyle(Paint.Style.FILL);
        paint.setColor(Color.RED);
        paint.setAntiAlias(true);

        canvas.drawCircle(canvas.getWidth()/2,canvas.getHeight()/2, radius,paint);

        //show the circle
        drawView.setImageBitmap(bitmap);
    }
}
