function solution(record) {
    var answer = [];
    
    // uid랑 들어옴/나감여부 저장해두고 마지막에 문자열로 만들기 (닉네임은 변할수있으니까)
    // uid - 닉네임 맵
    // uid+들어옴나감여부... : 들어오고나가는 순서대로 되어있어야함 [enter/leave, uid] 의 배열형식?
    
    let uidName = new Map();
    let sequence = [];
    
    for(let rec of record){
        let cmd = rec.split(" ");
        if(cmd[0] === "Enter"){
            uidName[cmd[1]] = cmd[2]; //맵에 uid-닉네임 저장
            let seq = [1, cmd[1]]; //1은 Enter, 0은 Leave + uid저장
            sequence.push(seq);
        }
        else if(cmd[0] === "Leave"){
            let seq = [0, cmd[1]]; //Leave
            sequence.push(seq);
        }
        else { //Change
            uidName[cmd[1]] = cmd[2]; //uid-닉네임 재저장(변경)
        }
        // console.log(uidName)
    }
    
    // console.log(sequence);
    
    for(let sq of sequence){
        let msg = uidName[sq[1]]+"님이 ";
        if(sq[0] === 1) msg += "들어왔습니다.";
        else msg+= "나갔습니다.";
        answer.push(msg);
    }
    
    return answer;
}