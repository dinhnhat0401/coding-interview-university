// import java.util.Set;
// import java.util.HashSet;
// import java.util.Map;
// import java.util.TreeMap;
// import java.util.HashMap;
import java.util.List;
import java.util.LinkedList;
import java.util.ListIterator;

class Playground {
    public static void main(String[ ] args) {
        // Hash set
        Set test = new HashSet();
        test.add(1);
        test.add(2);
        test.add(3);
        if (test.contains(4)) {
            System.out.println("Contain");
        } else {
            System.out.println("Does not contain");
        }

        // Tree Map
        Map<String, String> map = new TreeMap<String, String>() {
          {
              put("PC", "personal computer");
              put("A/C", "air conditioner");
              put("remote", "remote control");
          }
        };

        for (String str : map.keySet()) {
            System.out.println(str + ":" + map.get(str));
        }

        if (!map.isEmpty()) {
            System.out.println("Map size is " + map.size());
        }

        // HashMap
        Map <String, Integer> hashmap = new HashMap<String, Integer>();
        hashmap.put("PC", 1500);
        hashmap.put("iPhone", 1000);
        hashmap.put("coin", 20);

        for (String str : hashmap.keySet()) {
            System.out.println(str + ":" + hashmap.get(str));
        }

        List<String> list = new LinkedList<String>();
        list.add("PNL");
        list.add("Veltra");
        list.add("Mobilus");
        list.add("Rakuten");
        list.add("GlobalSignKK");

        for (String str : list) {
            System.out.println(str);
        }
        System.out.println(list.get(1));

        System.out.println("\n Forward Iteration");
        ListIterator listIt = list.listIterator(2);
        while(listIt.hasNext()) {
            System.out.println(listIt.next());
        }

        System.out.println("\n Backward Iteration");
        listIt = list.listIterator(2);
        while(listIt.hasPrevious()) {
            System.out.println(listIt.previous());
        }
    }
}
