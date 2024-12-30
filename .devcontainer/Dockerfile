ARG VARIANT="3.20"
FROM mcr.microsoft.com/vscode/devcontainers/base:0-alpine-${VARIANT}
 
RUN apk update && \
    apk add --no-cache --virtual .build-deps git build-base
RUN mkdir -p /sdk
WORKDIR /sdk
RUN git clone https://github.com/cc65/cc65.git
WORKDIR /sdk/cc65
RUN nice make -j2
RUN make install PREFIX=/usr
WORKDIR /sdk
