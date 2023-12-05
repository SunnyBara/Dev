function wordtotestlist(playerinput: string) {
  let wordtotest: string[] = [];
  playerinput.split("").forEach((letter) => {
    let incr = 0;
    while (incr < playerinput.length) {
      if (wordtotest[incr] === letter) {
        return;
      }
      incr += 1;
    }
    wordtotest.push(letter);
  });
  return wordtotest;
}

function BuildeWordtoDisplay(
  wordtotest: string[],
  word: string,
  playerinput: string
) {
  let wordtodisplay: string[] = [];
  wordtotest.forEach((letter) => {
    let indices: number[] = [];
    let pos = playerinput.indexOf(letter);

    while (pos !== -1) {
      indices.push(pos);
      pos = playerinput.indexOf(letter, pos + 1);
    }
    indices.forEach((idx: number) => {
      if (letter === word[idx]) {
        console.log(`${letter} est bien placé en position ${idx}!`);
        wordtodisplay[idx] = letter;
        return;
      } else if (word.includes(letter)) {
        console.log(`${letter} existe mais est mal positionné!`);
        wordtodisplay[idx] = letter;
        return;
      } else {
        console.log(`${letter} n'est pas présent dans le mot !`);
        wordtodisplay[idx] = " ";
        return;
      }
    });
  });
  return wordtodisplay;
}

export default function gameplay(playerinput: string, word: string): string {
  let wordtotest: string[] = wordtotestlist(playerinput);
  let wordtodisplay: string[] = BuildeWordtoDisplay(
    wordtotest,
    word,
    playerinput
  );
  return wordtodisplay.join("");
}
