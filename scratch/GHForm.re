module SearchFormParams = {
  type state = {
    owner: string,
    repo: string,
  };
  type fields = [ | `repo | `owner];
  /* (fieldName, getter, setter) */
  let lens = [
    (`repo, s => s.repo, (s, repo) => {...s, repo}),
    (`owner, s => s.owner, (s, owner) => {...s, owner}),
  ];
};

module SearchForm = ReForm.Create(SearchFormParams);

let component = ReasonReact.statelessComponent("SearchForm");

let make = _children => {
  ...component,
  render: _self =>
    <SearchForm
      schema=[
        (
          `repo,
          Custom(
            values =>
              Js.String.length(values.repo) > 20 ?
                Some("Keep it short!") : None,
          ),
        ),
        (`owner, Required),
      ]
      onSubmit={({values}) =>
        {
          let repo = values.repo;
          let owner = values.owner;
          Js.log2(repo, owner);
        }
        |> ignore
      }
      initialState={repo: "", owner: ""}>
      ...{({form, handleChange, handleSubmit, getErrorForField}) =>
        <form
          onSubmit={event => {
            ReactEvent.Synthetic.preventDefault(event);
            handleSubmit();
          }}>
          <label>
            <span> {"Repo:" |> ReasonReact.string} </span>
            <input
              value={form.values.repo}
              onChange={ReForm.Helpers.handleDomFormChange(
                handleChange(`repo),
              )}
            />
            <p>
              {getErrorForField(`repo)
               |> Belt.Option.getWithDefault(_, "")
               |> ReasonReact.string}
            </p>
          </label>
          <label>
            <span> {"Owner:" |> ReasonReact.string} </span>
            <textarea
              value={form.values.owner}
              rows=4
              onChange={ReForm.Helpers.handleDomFormChange(
                handleChange(`owner),
              )}
            />
            <p>
              {getErrorForField(`owner)
               |> Belt.Option.getWithDefault(_, "")
               |> ReasonReact.string}
            </p>
          </label>
          <button type_="submit"> {"Submit" |> ReasonReact.string} </button>
        </form>
      }
    </SearchForm>,
};