
public class FinallyReturn {
    public static final void main(String[] args) {
      System.out.println(foo(args));
    }
  
    private static int foo(String[] args) {
        int n = 42;
      try {
        n = Integer.parseInt(args[0]);
        return n;
      }
      finally {
        return n;
      }
    }
  }