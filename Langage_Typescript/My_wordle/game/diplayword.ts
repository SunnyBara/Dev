export default function displayword(
  wordtodisplay: string,
  wordtoguess: string
): boolean {
  let displaysetup: string = "|";
  for (const letter of wordtodisplay) {
    displaysetup += letter + "|";
  }
  console.log(displaysetup);
  if (wordtodisplay === wordtoguess) {
    console.log(`CONGRATULATION !!!!\nThe word has been found !!`);
    return false;
  }
  return true;
}
