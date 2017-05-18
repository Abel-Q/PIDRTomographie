%retroprojection_discrete2.m

%transformer de radon
I = phantom('Modified Shepp-Logan');
%subplot(3,1,1);
figure
imshow(I);

theta = 1:180;
[R,xp]=radon(I,theta);
%subplot(3,1,2);
figure
colormap('gray');
imagesc(theta,xp,R);





%retroprojection_discrete
[Rx,theta_max]=size(R);
width = 2^nextpow2(Rx);
Rx =256;
Ry = Rx;
theta_vect = 1:theta_max;

xp_offset = abs(min(xp))+1;

B = zeros(Rx,Ry);

proj_fft = fft(R, width);

filter = ones(width,1);
filter = 2*[0:( width/2-1),width/2:-1:1]'/width;
for i = 1:theta_max
    filtered(:,i) = proj_fft(:,i).*filter;
end

proj = real(ifft(filtered));

for (k = 1:theta_max)
    Q = proj(:,k);
    rad = theta_vect(k)*pi/180;
    
    for (x = 1:Rx)
        for (y = 1:Ry)
            u = round((x-Rx/2)*cos(rad)-(y-Ry/2)*sin(rad))+xp_offset;
            B(y,x) = B(y,x)+Q(u);
            
        end
    end
end

img = B*(pi/theta_max);
img
img_min = min(min(img));
img_max = max(max(img));

for (i = 1:Rx)
   for (j = 1:Ry)
        img(i,j) = round((255/(img_max-img_min))*(img(i,j)-img_min));
    end
end
figure
colormap('gray');
imagesc(img);

%quantification et test

%calcul de la distrotion moyenne
M = 256;
N = 256;
D = 0;
for (m = 1:M)
    for (n = 1:N)
        D = D+(I(m,n)-img(m,n))^2;
    end
end
D = D/(N*M);

%PSNR

PSNR = 10*log10((255^2)/D)

%SNR
SNR = 0;
for (m = 1:M)
    for (n = 1:N)
        SNR = SNR+(I(m,n))^2;
    end
end

SNR = 10*log10(SNR/(N*M*D));