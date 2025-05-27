int verificarTriangulo(double a, double b, double c){
    if(a+b < c || a+c < b || c+b < a) return 3;
    
    if(a == b && b == a && c == a){
        return 0;
    }

    if((a == b) || (a==c) || (c==b)){
        return 1;
    }


    return 2;
}