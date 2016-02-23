import net.rahmn.mathlibra.*;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class TestMathlibra
{
    static{
        System.loadLibrary("mathlibraJ");
        System.out.print("mathlibra version: "+ Mathlibra.getVersion() + "\n");
    }
    public static void main(String[] args)
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        Mathlibra x = new Mathlibra();
        try {
            System.out.print("Printing function table...\n");
            for (FunctionData d : x.getFunctions()) {
                System.out.print(d.toString() + "\n");
            }
            System.out.print("\n\nn");
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