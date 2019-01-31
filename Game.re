open Revery;
open Revery.Core;
open Revery.Math;
open Revery.UI;
open Revery.UI.Components;

let initialCards = Memory.generateCards();

let component = React.component(__MODULE__);

let make = () =>
  component(slots => {
    let (cards, setCards, _slots: React.Hooks.empty) =
      React.Hooks.state(initialCards, slots);

    let valueToColor = value =>
      switch (value) {
      | 0 => Colors.blue
      | 1 => Colors.red
      | 2 => Colors.orange
      | 3 => Colors.green
      | _ => Colors.white
      };

    let flipCard = index => {
      let newCards = Memory.flipCard(index, cards);
      setCards(newCards);
    };

    let containerStyle =
      Style.[
        position(`Absolute),
        alignItems(`Center),
        justifyContent(`Center),
        bottom(0),
        top(0),
        left(0),
        right(0),
        backgroundColor(Colors.white),
      ];

    <View style=containerStyle>
      <Grid>
        ...{List.mapi(
          (index, card: Memory.card) =>
            <Card
              color={valueToColor(card.value)}
              visible={card.visible}
              onClick={() => flipCard(index)}
            />,
          cards,
        )}
      </Grid>
    </View>;
  });

let createElement = (~children as _, ()) => React.element(make());
