#pragma once
// KeyWindow ダイアログ

class KeyWindow : public CDialog
{
	DECLARE_DYNAMIC(KeyWindow)

public:
	KeyWindow(CWnd* pParent = NULL);   // 標準コンストラクタ
	virtual ~KeyWindow();

  // キーボードを描画
  virtual void draw_keyboard(CDC *pDC, int x, int y, int nx, int ny);
  // 鍵盤押下状態を描画
  virtual void draw_notes(CDC *pDC, int x, int y, int nx, int ny);

  // キーオン通知
  virtual void KeyOn(int note, int color=0xFF0000);
  // キーオフ通知
  virtual void KeyOff(int note);
  // 全てキーオフ
  virtual void Reset();

  virtual void TrackOn(int track, int color, int volume, double fractionalNote, int frame);

  inline int MinWidth(){ return 366+1; }
  inline int MaxWidth(){ return synthesiaWidth; }
  inline int SynthesiaHeight(){ return synthesiaHeight; }
  int synthesiaHeight;
  int synthesiaWidth;
  int startingOctave;

  // 描画したキーボードを格納
  CBitmap m_keyBitmap;
  CDC m_keyDC;

  // キーボードガイド表示用
  CBitmap m_digBitmap;
  CDC m_digDC;

  // 裏画面領域
  CBitmap m_memBitmap;
  CDC m_memDC;

static const int MAX_FRAMES = 10;
static const int NUM_OCTAVES = 10;

  // 発音状態フラグ
  int m_nKeyStatus[256];
  // 発音する色
  int m_nKeyColor[256];

  //backside
  int numberofframes;
  //int lastnumberofframes;
  int synth_speed;
  int sharp_brightness;

  static const int NES_TRACK_MAX = 31;

  //xgm::ITrackInfo* m_nTrackInfo[NES_TRACK_MAX][MAX_FRAMES];
  int m_nTrackStatus[NES_TRACK_MAX][MAX_FRAMES];
  int m_nTrackColor[NES_TRACK_MAX][MAX_FRAMES];
  int m_nTrackVolume[NES_TRACK_MAX][MAX_FRAMES];
  double m_nTrackFractionalNote[NES_TRACK_MAX][MAX_FRAMES];
  int numberoftracks;

  // 初期化完了フラグ
  bool m_bInit;
  // オクターブガイド表示ON/OFF
  bool m_bShowOctave;



// ダイアログ データ
	enum { IDD = IDD_KEYWINDOW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
  virtual BOOL OnInitDialog();
  afx_msg void OnSize(UINT nType, int cx, int cy);
  afx_msg void OnPaint();
  afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
  virtual BOOL DestroyWindow();
};
