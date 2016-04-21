package net.rahmn.mathlibra;
import java.nio.Buffer;
import java.nio.ByteOrder;
import java.nio.DoubleBuffer;
import java.nio.ByteBuffer;

/**
 * Created by raven on 2016-01-26.
 */

public class Mathlibra {
    private long __handle;
    private native static long createInstance();
    private native static void freeInstance(long handle);
    private native ByteBuffer mapN(double Start,
                                        double End,
                                        double Offset,
                                        String name) throws MathlibraException;
    private static native void freeBufferN(Buffer buff);
    @Override
    protected void finalize() throws Throwable
    {
        try{
            if(this.__handle!= 0)
                freeInstance(this.__handle);
            this.__handle=0;
        }finally {
            super.finalize();
        }
    }

    public Mathlibra() {
        this.__handle=createInstance();
    }
    public native void setArg(String s)throws MathlibraException;
    public native void interpretArg() throws MathlibraException;
    public native NativeType executeArg() throws MathlibraException;
    public native void defineFunction(String s,boolean visible) throws MathlibraException;
    public native void undefineFunction(String s) throws MathlibraException;
    public DoubleBuffer map(double Start,
                                   double End,
                                   double Offset,
                                   String Name) throws MathlibraException
    {
        return this.mapN(Start,End,Offset,Name).order(ByteOrder.nativeOrder()).asDoubleBuffer();
    }
    public static void freeBuffer(DoubleBuffer buf)
    {
        freeBufferN(buf);
    }
    public native String[] getFunctionNames()throws MathlibraException;
    public native FunctionData[] getFunctions()throws MathlibraException;

    public native String[]      getVariableNames()throws MathlibraException;
    public native NativeType    getVariable(String name)throws MathlibraException;
    public native void          setVariable(String name,NativeType val, boolean constant)throws MathlibraException;
    public native boolean       isVariableDefined(String name)throws MathlibraException;
    public native boolean       isVariableConst(String name)throws MathlibraException;
    public native void          clearVariables()throws MathlibraException;
    public native void          enablePlugins()throws MathlibraException;

    public static native String getVersion();

}

