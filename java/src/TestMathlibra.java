import net.rahmn.mathlibra.*;

import javax.print.attribute.standard.MediaSize;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.DoubleBuffer;

public class TestMathlibra
{
    static{
        System.loadLibrary("mathlibraJ");
        System.out.print("MathlibraJ--A mathlibra java wrapper\nLicenced under the terms of the MIT license\n Copyright 2016 Lukas Rahmn\n\n");
        System.out.print("mathlibra version: "+ Mathlibra.getVersion() + "\n\n");
    }
    private static void printVars(Mathlibra m) throws MathlibraException
    {
        System.out.println("Printing variable table...");
        for(String name:m.getVariableNames())
        {
            try(NativeType tmp =m.getVariable(name)) {
                System.out.println(name + "\t = " + tmp.toString());
            }
        }
    }
    public static void main(String[] args)
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        Mathlibra x = new Mathlibra();
        try
        {
            try(NativeType t = NativeType.makeType(new double[]{1,2,3,4,5,6,7,8,9},3,3))
            {
                x.setVariable("xs",t,true);
            }
            try(NativeType t2 = NativeType.makeType("Hello world"))
            {
                x.setVariable("greeting",t2,true);
            }
            try(NativeType t3 = NativeType.makeType(new double[]{3.1415926535},1,1))
            {
                x.setVariable("pi",t3,true);
            }
            System.out.println("Defining function double(x)=2x ...\n");
            x.setArg("2x");
            x.defineFunction("double",true);

            System.out.print("\nPrinting function table...\n");
            for (FunctionData d : x.getFunctions()) {
                System.out.print(d.toString() + "\n");
            }
            System.out.print("\n\n");
            TestMathlibra.printVars(x);
            System.out.print("\n\n");
            DoubleBuffer  buff =x.map(1,10,1,"double");
            System.out.println("Printing table... \nTable f(x)=double(x)");
            for(int i=0; i < buff.capacity(); i+=2)
            {
                System.out.format("f(%5.3f)\t=%5.3f%n",buff.get(i),buff.get(i+1));
            }
            System.out.println("\n\n");
            Mathlibra.freeBuffer(buff);
        }catch (MathlibraException e)
        {
            System.out.print(e);
            return;
        }

        while (true)
        {
             try {
                 System.out.print("π>");
                 x.setArg(in.readLine());
             x.interpretArg();
             try(NativeType tmp=x.executeArg()) {
                 System.out.println(tmp);
                 x.setVariable("ans",tmp,true);
             }
         }
         catch (MathlibraException e)
        {
            System.out.println(e.toString());
        }
            catch (IOException e)
            {
                System.out.print(e);
            }
        }
    }
}