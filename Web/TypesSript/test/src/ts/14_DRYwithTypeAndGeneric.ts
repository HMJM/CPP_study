// Don't repeat yourself

interface Options {
  property: number;
  to: number;
  test: string;
}

type HTTPFunction = (url: string, opts: Options) => Promise<Response>;

const get: HTTPFunction = (url, opts) => { /* ... */ };
const post: HTTPFunction = (url, opts) => { /* ... */ };

// //

interface Person {
  firstName: string;
  lastName: string;
}

interface PersonWithBirthday extends Person {
  birthday: Date;
}
// or
type PersonWithBirthday2 = Person & { birthday: Date };

// //

interface State {
  userId: string;
  pageTitle: string;
  recentFiles: string[];
  pageContents: string;
}

interface TopNavState {
  userId: string;
  pageTitle: string;
  recentFiles: string[];
}
// or

type TopNavState2 = {
  [k in 'userId' | 'pageTitle' | 'recentFiles']: State[k]
}

// or USING type Pick<T, K extends keyof T> = { [k int K]: T[k] };
type TopNavState3 = Pick<State, 'userId' | 'pageTitle' | 'recentFiles'>;
