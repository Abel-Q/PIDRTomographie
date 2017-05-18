function [ P ] = PSNR( I,img )
%n = size(I)
%M = n;
%N = n;
[N, M] = size(I);
D = 0;
for (m = 1:M)
    for (n = 1:N)
        D = D+(I(m,n)-img(m,n))^2;
    end
end
D = D/(N*M);

%PSNR

P = 10*log10((255^2)/D);

end

