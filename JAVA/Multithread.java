
class terv extends Thread 
{
    public void run()
    {
        for(int i=1;i<=5;i++)
        {
            System.out.println("hi");
            try{

                Thread.sleep(1000);
            }
            catch(Exception e) {}
        }
    }
}

class joseph extends Thread {
    public void run() {
        for(int i=0;i<=5;i++)
        {
            System.out.println(i);
            try {
                Thread.sleep(2000);
            } catch (Exception e) {
                // TODO: handle exception
            }
        }
    }
}

public class Multithread {
    public static void main (String args[]) {
         terv s1 = new terv();
         s1.start();
         joseph s2 = new joseph();
         s2.start();
         if(s1.isAlive())
         {
            System.out.println("thread is alive");
         }
         try {
            s1.join();
         } catch (Exception e) {
            // TODO: handle exception
         }
         System.out.println("saran");
    }
}
