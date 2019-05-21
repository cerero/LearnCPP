import java.util.*;
import java.util.Arrays;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import java.io.*;

public class Test {
  public static void main(String[] args) {
    // Integer nullInt = (Integer) (null);
    // if (nullInt == null) {
    //   System.out.println("强转型null的Integer对象,貌似不会崩溃");
    // }
    testShape();
  }

  private static void testShape() {
    int width = 1080;
    int height = 2160;
    String data = readFileToString("./shape.xml");
    Pattern p = Pattern.compile("<point *x=\"([0-9]*)\" *y=\"([0-9]*)\" */>");
    Matcher m = p.matcher(data);
    float pointScale = 1.0f;   //缩放系数，用于控制坐标点不超过屏幕内显示所有point
    float[] points = new float[1200];
    int pointInd = -1;
    int pointItemSize = 0;
    while (m.find() && pointInd < points.length - 2) {//从xml响应里解析x/y坐标点
        int x = Integer.valueOf(m.group(1));
        int y = Integer.valueOf(m.group(2));

        if (x > width) {
            float tempXScale = x / width;
            if (tempXScale > pointScale) {
                pointScale = tempXScale;
            }
        }

        if (y > height) {
            float tempYScale = y / height;
            if (tempYScale > pointScale) {
                pointScale = tempYScale;
            }
        }

        points[++pointInd] = (float) (x) / width;
        points[++pointInd] = (float) (y) / height;
        pointItemSize ++;
    }

    for (int i = 0; i < pointInd - 1; i+=2) {
        points[i]     /= pointScale;
        points[i + 1] /= pointScale;
    }

    float[] realPoints = Arrays.copyOf(points, pointInd - 1);
    System.out.println("pointScale:" + pointScale);
    System.out.println("pointItemSize:" + pointItemSize);
    System.out.println("points:" + Arrays.toString(realPoints));
  }

  public static String readFileToString(String filePath) {
        String str = "";
        FileInputStream inStream = null;
        try {
            File readFile = new File(filePath);
            if (!readFile.exists()) {
                return null;
            }
            inStream = new FileInputStream(readFile);
            ByteArrayOutputStream stream = new ByteArrayOutputStream();
            byte[] buffer = new byte[1024];
            int length = -1;
            while ((length = inStream.read(buffer)) != -1) {
                stream.write(buffer, 0, length);
            }
            str = stream.toString();
            stream.close();
            return str;
        } catch (FileNotFoundException e) {
            return null;
        } catch (IOException e) {
            return null;
        } finally {
            if (inStream != null) {
                try {
                    inStream.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
