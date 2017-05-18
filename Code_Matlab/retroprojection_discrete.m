function [ img  ] = retroprojection_discrete( R,xp,n,theta_max,p )
%avec R la matrice de la transformer de radon, xp , n la taille de  l'image
%et p le pas angulaire
[Rx,theta_max_2]=size(R);
width = 2^nextpow2(Rx);
Rx =n;
Ry = n;
theta_vect = 1:p:theta_max;
%theta_vect = linspace(1,theta_max,p);

xp_offset = abs(min(xp))+1;

B = zeros(Rx,Ry);

proj_fft = fft(R, width);
%filter = ones(width,1);
filter = 2*[0:( width/2-1),width/2:-1:1]'/width;

% figure;
% plot(1:width,filter);
% title("Filtre de Ram-Lak");

for i = 1:length(theta_vect)%i = 1:theta_max
    
    filtered(:,i) = proj_fft(:,i).*filter;
end

proj = real(ifft(filtered));

for k = 1:length(theta_vect)
    Q = proj(:,k);
    rad = theta_vect(k)*pi/180;
    %rad = k*pi/180;
    
    for (x = 1:Rx)
        for (y = 1:Ry)
            u = ((x-Rx/2)*cos(rad)-(y-Ry/2)*sin(rad))+xp_offset;
            u1 = ceil(u);
            u2 = floor(u);
            
            if u1 == u2
                %B(y,x) = B(y,x)+Q(u1);
                B(y,x) = B(y,x)+proj(u1,k);
            else
                %q = Q(u2)+(u-u2)*((Q(u1)-Q(u2))/(u1-u2));%formule de toyalor young pour interpoler la valeur de Q(u)
                q =proj(u2,k)+(u-u2)*((proj(u1,k)-proj(u2,k))/(u1-u2));
                B(y,x) = B(y,x)+q;
            
        end
    end
    end
img = B*(pi/theta_max);
img_min = min(min(img));
img_max = max(max(img));

for (i = 1:Rx)
   for (j = 1:Ry)
        img(i,j) = round((255/(img_max-img_min))*(img(i,j)-img_min));
    end
end
%figure
%colormap('gray');
%imagesc(img);
img;

end

