#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<algorithm>
using namespace std ;
class Sinhvien{
	private:
		string hoten;
		double ma;
		int ngaysinh;
		double tongdiem;
	public:
		bool operator<(const Sinhvien& s1 ){      
			return (this->hoten < s1.hoten);
		}
       void nhap(){
       	cout<<"Ho ten:";
       	fflush(stdin);
       	getline(cin,hoten);
       	cout<<"Ma sinh vien:";
       	cin>>ma;
       	cout<<"Ngay sinh: ";
       	cin>>ngaysinh;
       	cout<<"Diem thi: ";
       	cin>>tongdiem;
	   }
	   string getName(){
	   	   return hoten;
	   }
	   double getDiem(){
	   	 return tongdiem;
	   }
	   friend ostream& operator<<(ostream& os ,Sinhvien &d){
	      os<<"Ho ten:";
	      os<<d.hoten<<endl;
	      os<<"Ma sinh vien:";
	      os<<d.ma<<endl;
	      os<<"Ngay sinh:";
	      os<<d.ngaysinh<<endl;
	      return os;
	   }
	   void in(){
	   	cout<<"Ho ten:"<<hoten<<endl;
	   	cout<<"Ma sinh vien:"<<ma<<endl;
	   }
};
void sapxepsinhvien(vector<Sinhvien>& a){
	sort(a.begin(),a.end());
}
void viethoaten(string &s){
	for(int i=0;i<s.size();i++){
		s[i]=toupper(s[i]);
	}
}
	
main(){
	int n=1;
	//Sinhvien *sv=new Sinhvien[n];
	vector<Sinhvien> a;
    while(1){
    	cout<<"---------------MENU--------------"<<endl;
    	cout<<"1.Nhap thong tin sinh vien"<<endl;
    	cout<<"2.In danh sach thong tin cac sinh vien"<<endl;
    	cout<<"3.Sua thong tin sinh vien"<<endl;
    	cout<<"4.Sap xep thong tin theo thu tu ten:"<<endl;
    	cout<<"5.Thoat khoi chuong trinh!"<<endl;
    	cout<<"6.Danh sach sinh vien hoc lai:"<<endl;
    	int lc;
    	char d;
    	cout<<endl<<"Nhap lua chon:";
        cin>>lc;
        if(lc==1){
        	for(int i=0;i<n;i++){
        		n++;
        		Sinhvien *sv=new Sinhvien[n];
        		sv[i].nhap();
        		a.push_back(sv[i]);
               cout<<"Ban co muon nhap tiep khong:Y/N";
				cin>>d;
	
				if(d=='Y'){
					continue;
				} else if(d=='N'){
					break;
				}   
			}
	}
		if(lc==2){
			for(vector<Sinhvien>::iterator it=a.begin();it!=a.end();++it){
				cout<<*it<<endl;
			}
	}
	    if(lc==3){
	    	int stt;
	    	int i;
	    	cout<<"Nhap so thu tu sinh vien can thay doi:";
	    	cin>>stt;
	    	i=stt-1;
	    	a.erase(a.begin()+i) ;//
	    	Sinhvien sv;
	    	sv.nhap();
	    	a.insert(a.begin()+i,sv);//
		}
		if(lc==4){
			sapxepsinhvien(a);
		}
		if(lc==5){
			break;
		}
		if(lc==6){
		    cout<<*(a.begin()+1);
		}	
	 }
	cout<<"Written by Duong Minh Hai KHMT K64"<<endl;
	cout<<"Thanks for using!";
  	
}
  	



	

