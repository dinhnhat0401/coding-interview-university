import java.util.*;
public class Main{
    
    static int[] belongs = null;
    static int[] states = null;
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        //入力
        int n = Integer.parseInt(sc.next());
        int m = Integer.parseInt(sc.next());
        states = new int[n];
        belongs = new int[n];
        
        for(int i=0; i<n; i++){
            belongs[i] = i;
            states[i] = 0;
        }
        
        for(int i=0; i<m; i++){
            int l = Integer.parseInt(sc.next())-1;
            int r = Integer.parseInt(sc.next())-1;
            int d = Integer.parseInt(sc.next());
            if(!merge(l, r, d)){
                System.out.println("No");
                sc.close();
                return;
            }
        }
        System.out.println("Yes");
        sc.close();
    }
        
    public static int updateBelongs(int a){
        if(a == belongs[a]){
            return a;
        }else{
            int temp = belongs[a];
            belongs[a] = updateBelongs(belongs[a]);
            states[a] += states[temp];
            return belongs[a];
        }
    }
    
    public static boolean merge(int l, int r, int d){
        int lb = updateBelongs(l);
        int rb = updateBelongs(r);
        
        if(lb == rb){
            return states[r] == states[l] + d;
        }else{
            belongs[rb] = lb;
            states[rb] = states[l] + d - states[r];
            return true;
        }
    }
}
