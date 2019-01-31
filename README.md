# Revery Memory

<img width="453" alt="screenshot 2019-02-02 at 12 31 21" src="https://user-images.githubusercontent.com/223045/52163717-7a6fed80-26e6-11e9-8c94-0f4cdba6286f.png">

## Instructions

### Setup

Install all the depedencies using

```
esy install
```

Build and run the application a first time:

```
esy run
```

> **NOTE:** The first build will take a while. Subsequent builds will be fast.

The result should be the a native application starts showing "Hello World".

During development you can continious build using:

```
esy dune build --watch
```

> **NOTE:** Requires [fswatch](https://github.com/emcrisostomo/fswatch) to be installed.

## License

[MIT License](LICENSE)
