FROM ubuntu:17.10

# Install dependencies
RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y \
    build-essential \
    clang \
    clang-tidy \
    cmake \
    git \
    liballegro5-dev

# Build from source
RUN git clone --recurse-submodules https://github.com/0916dhkim/SimplePlatformer.git repo
RUN mkdir /app
WORKDIR /app
RUN cmake /repo
RUN make simpleplatformer

CMD ["/app/bin/simpleplatformer"]
