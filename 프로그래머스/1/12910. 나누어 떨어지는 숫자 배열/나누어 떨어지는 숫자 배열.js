function solution(arr, divisor) {
    const new_arr = arr.filter((el)=>el%divisor===0);
    return new_arr.length ? new_arr.sort((a,b)=>a-b) : [-1];
}