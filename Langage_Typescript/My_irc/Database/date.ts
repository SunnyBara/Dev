export function RegexDate(date: string) {
  const regex = /\d{4}-\d{2}-\d{2}\s\d{2}:\d{2}:\d{2}/;
  if (date.match(regex)) {
    return true;
  }
  return false;
}
