FROM debian:stable-slim AS build

RUN apt-get update && apt-get install -y build-essential
RUN apt-get install -y cmake
RUN apt-get install -y catch2

WORKDIR /geometry2d

COPY --exclude=./bin --exclude=./build . .

RUN cmake --preset test
RUN cmake --build --preset test

FROM debian:stable-slim

COPY --from=build /geometry2d/bin .

ENTRYPOINT ["/tests"]