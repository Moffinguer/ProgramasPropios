public class CuentaPalabras{
    public static void main(String[] args){
        String palIni = args[0].toUpperCase();
        System.out.println("En la palabra \"" + palIni + "\":");
        while (palIni.length() != 0){
            char a = palIni.charAt(0);
            String j = palIni.replaceAll(String.valueOf(a),"");
            int diff = palIni.length() - j.length();
            System.out.println("El caracter \"" + a + "\" se repite " + diff);
            palIni = j;
        }

    }
}