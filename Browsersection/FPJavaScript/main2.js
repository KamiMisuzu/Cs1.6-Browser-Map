function compose(f,g){
    return function(value){
        return f(g(value))
    }
}