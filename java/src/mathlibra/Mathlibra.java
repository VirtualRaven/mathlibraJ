package mathlibra;

/**
 * Created by raven on 2016-01-26.
 */

public class Mathlibra {
    private long __handle;
    private native static long createInstance();
    private native static void freeInstance(long handle);
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

