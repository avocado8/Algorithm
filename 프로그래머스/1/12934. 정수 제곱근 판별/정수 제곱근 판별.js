function solution(n) {
    var answer = 0;
    let x = Math.sqrt(n);
    return x === Math.floor(x) ? (x+1)**2 : -1;
}